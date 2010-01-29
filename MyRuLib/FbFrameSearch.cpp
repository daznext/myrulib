#include "FbFrameSearch.h"
#include <wx/artprov.h>
#include <wx/mimetype.h>
#include "FbConst.h"
#include "FbMainMenu.h"
#include "FbDatabase.h"
#include "FbManager.h"

BEGIN_EVENT_TABLE(FbFrameSearch, FbFrameBase)
	EVT_COMMAND(ID_FOUND_NOTHING, fbEVT_BOOK_ACTION, FbFrameSearch::OnFoundNothing)
END_EVENT_TABLE()

FbFrameSearch::FbFrameSearch(wxAuiMDIParentFrame * parent, const wxString & title)
	:FbFrameBase(parent, ID_FRAME_SEARCH, title)
{
	CreateControls();
}

void FbFrameSearch::CreateControls()
{
	SetMenuBar(new FbFrameMenu);

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_ToolBar = CreateToolBar(wxTB_FLAT|wxTB_NODIVIDER|wxTB_HORZ_TEXT, wxID_ANY, GetTitle());
	bSizer1->Add( m_ToolBar, 0, wxGROW);

	long substyle = wxTR_HIDE_ROOT | wxTR_FULL_ROW_HIGHLIGHT | wxTR_COLUMN_LINES | wxTR_MULTIPLE | wxSUNKEN_BORDER;
	CreateBooksPanel(this, substyle);
	bSizer1->Add( m_BooksPanel, 1, wxEXPAND, 5 );

	SetSizer( bSizer1 );

	FbFrameBase::CreateControls();
}

static bool FullText(const wxString &text)
{
	return ( text.Find(wxT("*")) == wxNOT_FOUND ) && ( text.Find(wxT("?")) == wxNOT_FOUND );
}

static wxString AppendAsterisk(wxString str)
{
	wxString result;
	int i = wxNOT_FOUND;
	do {
		str.Trim(false);
		i = str.find(wxT(' '));
		if (i == wxNOT_FOUND) break;
		result += str.Left(i) + wxT("* ");
		str = str.Mid(i);
	} while (true);
	str.Trim(true);
	if (!str.IsEmpty()) result += str.Left(i) + wxT("*");
	return result;
}

void * FbFrameSearch::SearchThread::Entry()
{

	wxCriticalSectionLocker locker(sm_queue);

	EmptyBooks();
	bool bUseAuthor = !m_author.IsEmpty();
	bool bFullText = FullText(m_title) && FullText(m_author);

	try {
		FbCommonDatabase database;
		InitDatabase(database);
		if ( bFullText ) {
			wxString condition = wxT("books.id IN (SELECT docid FROM fts_book WHERE fts_book MATCH ?)");
			if (bUseAuthor) condition += wxT("AND books.id_author IN (SELECT docid FROM fts_auth WHERE fts_auth MATCH ?)");
			wxString sql = GetSQL(condition);

			wxSQLite3Statement stmt = database.PrepareStatement(sql);
			stmt.Bind(1, AppendAsterisk(m_title));
			if (bUseAuthor) stmt.Bind(2, AppendAsterisk(m_author));

			wxSQLite3ResultSet result = stmt.ExecuteQuery();
			if (result.Eof()) {
				FbCommandEvent(fbEVT_BOOK_ACTION, ID_FOUND_NOTHING).Post(m_frame);
				return NULL;
			}
			FillBooks(result);
		} else {
			wxString condition = wxT("SEARCH_T(books.title)");
			if (bUseAuthor) condition += wxT("AND SEARCH_A(authors.search_name)");
			wxString sql = GetSQL(condition);

			FbSearchFunction sfTitle(m_title);
			FbSearchFunction sfAuthor(m_author);
			database.CreateFunction(wxT("SEARCH_T"), 1, sfTitle);
			if (bUseAuthor) database.CreateFunction(wxT("SEARCH_A"), 1, sfAuthor);
			wxSQLite3Statement stmt = database.PrepareStatement(sql);

			wxSQLite3ResultSet result = stmt.ExecuteQuery();
			if (result.Eof()) {
				FbCommandEvent(fbEVT_BOOK_ACTION, ID_FOUND_NOTHING).Post(m_frame);
				return NULL;
			}
			FillBooks(result);
		}
	} catch (wxSQLite3Exception & e) {
		wxLogError(e.GetMessage());
	}
	return NULL;
}

void FbFrameSearch::Execute(wxAuiMDIParentFrame * parent, const wxString &title, const wxString &author)
{
	if ( title.IsEmpty() ) return;

	wxString msg = wxString::Format(_("Поиск: «%s»"), title.c_str());
	FbFrameSearch * frame = new FbFrameSearch(parent, msg);
	frame->m_author = author;
	frame->m_title = title;
	frame->Update();

	frame->UpdateBooklist();
}

void FbFrameSearch::UpdateBooklist()
{
	( new SearchThread(this, m_BooksPanel->GetListMode(), m_title, m_author) )->Execute();
}

void FbFrameSearch::OnFoundNothing(wxCommandEvent& event)
{
	wxString msg = wxString::Format(_("Ничего не найдено по шаблону «%s»"), m_title.c_str());
	wxMessageBox(msg, wxT("Поиск"));
	Close();
}

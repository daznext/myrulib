#include "FbFrameDate.h"
#include <wx/artprov.h>
#include <wx/splitter.h>
#include "FbConst.h"
#include "FbClientData.h"
#include "FbExportDlg.h"
#include "FbMainMenu.h"
#include "FbMasterTypes.h"
#include "FbDateTree.h"
#include "FbWindow.h"
#include "FbParams.h"

BEGIN_EVENT_TABLE(FbFrameDate, FbFrameBase)
	EVT_FB_MODEL(ID_MODEL_CREATE, FbFrameDate::OnModel)
	EVT_FB_COUNT(ID_BOOKS_COUNT, FbFrameDate::OnBooksCount)
END_EVENT_TABLE()

FbFrameDate::FbFrameDate(wxAuiNotebook * parent, bool select)
	: FbFrameBase(parent, ID_FRAME_DATE, GetTitle(), select), 
		m_FindText(NULL), m_FindInfo(NULL), m_SequenceCode(0)
{
	m_MasterList = new FbTreeViewCtrl(this, ID_MASTER_LIST, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|fbTR_VRULES);
	CreateColumns();

	CreateBooksPanel(this);
	SplitVertically(m_MasterList, m_BooksPanel);

	FbFrameBase::CreateControls(select);

	m_MasterThread = new FbDateTreeThread(this);
	m_MasterThread->Execute();
}

void FbFrameDate::CreateColumns()
{
	m_MasterList->AddColumn(0, _("Date"), 40, wxALIGN_LEFT);
	m_MasterList->AddColumn(1, _("Num."), 10, wxALIGN_RIGHT);
}

void FbFrameDate::OnBooksCount(FbCountEvent& event)
{
	FbDateDayData * child = wxDynamicCast(&m_MasterList->GetCurrent(), FbDateDayData);
	if (child && *child == event.GetInfo()) {
		child->SetCount(event.GetCount());
		m_MasterList->Refresh();
	}

	event.Skip();
}

void FbFrameDate::OnModel( FbModelEvent& event )
{
	m_MasterList->AssignModel(event.GetModel());
}

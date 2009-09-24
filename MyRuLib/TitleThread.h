#ifndef __TITLETHREAD_H__
#define __TITLETHREAD_H__

#include <wx/wx.h>
#include <wx/thread.h>
#include "FbDatabase.h"

class TitleThread : public wxThread
{
public:
    TitleThread(wxEvtHandler *frame, const int id): wxThread(), m_id(id), m_frame(frame) {};
    virtual void *Entry();
    static void Execute(wxEvtHandler *frame, const int id);
private:
	wxString GetBookInfo(FbDatabase &database, int id);
	wxString GetBookFiles(FbDatabase &database, int id);
    static wxString HTMLSpecialChars( const wxString &value, const bool bSingleQuotes = false, const bool bDoubleQuotes = true);
private:
    int m_id;
    wxEvtHandler *m_frame;
};



#endif // __TITLETHREAD_H__

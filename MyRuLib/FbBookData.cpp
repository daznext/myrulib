#include "FbBookData.h"

BookTreeItemData::BookTreeItemData(wxSQLite3ResultSet & res):
    m_id( res.GetInt(wxT("id"))),
    title( res.GetString(wxT("title"))),
    file_name( res.GetString(wxT("file_name"))),
    file_type( res.GetString(wxT("file_type"))),
    file_size( res.GetInt(wxT("file_size"))),
	number( res.GetInt(wxT("number")))
{
}


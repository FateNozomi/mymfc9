// mymfc9Doc.cpp : implementation of the CMymfc9Doc class
//

#include "stdafx.h"
#include "mymfc9.h"

#include "mymfc9Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMymfc9Doc

IMPLEMENT_DYNCREATE(CMymfc9Doc, CDocument)

BEGIN_MESSAGE_MAP(CMymfc9Doc, CDocument)
	//{{AFX_MSG_MAP(CMymfc9Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymfc9Doc construction/destruction

CMymfc9Doc::CMymfc9Doc()
{
	// TODO: add one-time construction code here

}

CMymfc9Doc::~CMymfc9Doc()
{
}

BOOL CMymfc9Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMymfc9Doc serialization

void CMymfc9Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMymfc9Doc diagnostics

#ifdef _DEBUG
void CMymfc9Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMymfc9Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMymfc9Doc commands

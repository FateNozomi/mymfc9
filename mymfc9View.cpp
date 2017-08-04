// mymfc9View.cpp : implementation of the CMymfc9View class
//

#include "stdafx.h"
#include "mymfc9.h"

#include "mymfc9Doc.h"
#include "mymfc9View.h"
#include "DieViewer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMymfc9View

IMPLEMENT_DYNCREATE(CMymfc9View, CView)

BEGIN_MESSAGE_MAP(CMymfc9View, CView)
	//{{AFX_MSG_MAP(CMymfc9View)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_CloseDieViewer, OnCloseDieViewer)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymfc9View construction/destruction

CMymfc9View::CMymfc9View()
{
	// TODO: add construction code here
	m_pDieViewerDlg = new CDieViewer(this);
}

CMymfc9View::~CMymfc9View()
{
	// destroys window if not already destroyed  
	delete m_pDieViewerDlg;
}

BOOL CMymfc9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMymfc9View drawing

void CMymfc9View::OnDraw(CDC* pDC)
{
	CMymfc9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30, 30, "Press the left mouse button here.");
}

/////////////////////////////////////////////////////////////////////////////
// CMymfc9View diagnostics

#ifdef _DEBUG
void CMymfc9View::AssertValid() const
{
	CView::AssertValid();
}

void CMymfc9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMymfc9Doc* CMymfc9View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMymfc9Doc)));
	return (CMymfc9Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMymfc9View message handlers

void CMymfc9View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_pDieViewerDlg->DestroyWindow();
    // no problem if window was already destroyed

	CView::OnRButtonDown(nFlags, point);
}

void CMymfc9View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// creates the dialog if not created already
    if (m_pDieViewerDlg->GetSafeHwnd() == 0)
    {
        m_pDieViewerDlg->Create(); // displays the dialog window
    }

	CView::OnLButtonDown(nFlags, point);
}

LRESULT CMymfc9View::OnCloseDieViewer(WPARAM wParam, LPARAM lParam)
{
    // message received in response to modeless dialog OK
    // and Cancel buttons
    TRACE("CMymfc9View::OnCloseDiewViewer %x, %lx\n", wParam, lParam);
    TRACE("Dialog Path contents = %s\n", (const char*) m_pDieViewerDlg->m_strPath);
    m_pDieViewerDlg->DestroyWindow();
    return 0L;
}
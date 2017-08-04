// DieViewer.cpp : implementation file
//

#include "stdafx.h"
#include "mymfc9.h"
#include "DieViewer.h"
#include "BitmapPicture.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDieViewer dialog


CDieViewer::CDieViewer(CWnd* pParent /*=NULL*/)
	: CDialog(CDieViewer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDieViewer)
	m_strPath = _T("");
	//}}AFX_DATA_INIT
	m_pView = NULL;
}


void CDieViewer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDieViewer)
	DDX_Control(pDX, IDC_DiePic, m_DiePic);
	DDX_Text(pDX, IDC_PATH, m_strPath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDieViewer, CDialog)
	//{{AFX_MSG_MAP(CDieViewer)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTNLAUNCH, OnBtnlaunch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDieViewer message handlers

void CDieViewer::OnOK() 
{
	if (m_pView != NULL)
	{
		// modeless case - do not call base class OnOK
		UpdateData(TRUE);
		m_pView->PostMessage(WM_CloseDieViewer, IDOK);
	}
    else
    {
		CDialog::OnOK(); // modal case
	}
}

void CDieViewer::OnCancel() 
{
	if (m_pView != NULL)
	{
		// modeless case - do not call base class OnCancel
		m_pView->PostMessage(WM_CloseDieViewer, IDCANCEL);
    }
	else
	{
		CDialog::OnCancel(); // modal case
	}
}

CDieViewer::CDieViewer(CView *pView)
{
	m_pView = pView;
}

BOOL CDieViewer::Create()
{
	return CDialog::Create(CDieViewer::IDD);
}

int CDieViewer::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	return 0;
}

void CDieViewer::OnBtnlaunch() 
{
	// TODO: Add your control notification handler code here
	//ShellExecute(0, 0, m_strPath, 0, 0, SW_SHOW);

	// Load the bitmap from file
	CBitmapPicture bmpPicture;
	bmpPicture.Load("C:/Users/Will/Pictures/test.jpg");

	m_DiePic.SetBitmap(bmpPicture);
}

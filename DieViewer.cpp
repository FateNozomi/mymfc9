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
	bmpPicture.Load("C:/Users/Will/Pictures/LFFEFFM01S01_1_1-fail.jpg");

	//CBitmap bmpPicture;
	//HANDLE hBitMap = ::LoadImage(0, "C:/Users/Will/Pictures/materialdesign.bmp",IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//bmpPicture.Attach((HBITMAP)hBitMap);

	// Get dialog CRect
	CRect* rect = new CRect();
	this->GetClientRect(rect);

	CDC *pDC = m_DiePic.GetDC();
	CDC m_DC;

	m_DC.CreateCompatibleDC(pDC);
	m_DC.SelectObject(&bmpPicture);

	// For getting bitmap width and height
	BITMAP bm;
	bmpPicture.GetBitmap(&bm);

	double screenToImgRatio = (double)rect->Height() / (double)bm.bmHeight;

	double resizedWidth = bm.bmWidth * screenToImgRatio;
	double resizedheight = bm.bmHeight * screenToImgRatio;

	double centerImgPos = (rect->Width() - resizedWidth) / 2;

	SetStretchBltMode(*pDC, HALFTONE); // Prevents distortion
	pDC->StretchBlt((int)centerImgPos, 0, (int)resizedWidth, (int)resizedheight, &m_DC, 0,0, bm.bmWidth, bm.bmHeight, SRCCOPY);

	
	
}

#if !defined(AFX_DIEVIEWER_H__DDA48382_7042_47A6_A932_13C4B69561DF__INCLUDED_)
#define AFX_DIEVIEWER_H__DDA48382_7042_47A6_A932_13C4B69561DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_CloseDieViewer  WM_USER + 5

// DieViewer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDieViewer dialog

class CDieViewer : public CDialog
{
// Construction
public:
	CView* m_pView;
	BOOL Create();
	CDieViewer(CView* pView);
	CDieViewer(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDieViewer)
	enum { IDD = IDD_DieViewer };
	CStatic	m_DiePic;
	CString	m_strPath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDieViewer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDieViewer)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBtnlaunch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIEVIEWER_H__DDA48382_7042_47A6_A932_13C4B69561DF__INCLUDED_)

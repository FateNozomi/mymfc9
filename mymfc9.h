// mymfc9.h : main header file for the MYMFC9 application
//

#if !defined(AFX_MYMFC9_H__86E6CF02_E475_44E9_BF30_75A6CC51CE82__INCLUDED_)
#define AFX_MYMFC9_H__86E6CF02_E475_44E9_BF30_75A6CC51CE82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMymfc9App:
// See mymfc9.cpp for the implementation of this class
//

class CMymfc9App : public CWinApp
{
public:
	CMymfc9App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymfc9App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMymfc9App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMFC9_H__86E6CF02_E475_44E9_BF30_75A6CC51CE82__INCLUDED_)

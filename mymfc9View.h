class CDieViewer;
// mymfc9View.h : interface of the CMymfc9View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMFC9VIEW_H__5B4AAAF3_723F_4A60_9C35_C2844B16F80B__INCLUDED_)
#define AFX_MYMFC9VIEW_H__5B4AAAF3_723F_4A60_9C35_C2844B16F80B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMymfc9View : public CView
{
protected: // create from serialization only
	CMymfc9View();
	DECLARE_DYNCREATE(CMymfc9View)

// Attributes
public:
	CMymfc9Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymfc9View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMymfc9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMymfc9View)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnCloseDieViewer(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CDieViewer* m_pDieViewerDlg;
};

#ifndef _DEBUG  // debug version in mymfc9View.cpp
inline CMymfc9Doc* CMymfc9View::GetDocument()
   { return (CMymfc9Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMFC9VIEW_H__5B4AAAF3_723F_4A60_9C35_C2844B16F80B__INCLUDED_)

// mymfc9Doc.h : interface of the CMymfc9Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMFC9DOC_H__BE822B58_048D_4A74_80F9_80D0FE53DB40__INCLUDED_)
#define AFX_MYMFC9DOC_H__BE822B58_048D_4A74_80F9_80D0FE53DB40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMymfc9Doc : public CDocument
{
protected: // create from serialization only
	CMymfc9Doc();
	DECLARE_DYNCREATE(CMymfc9Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymfc9Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMymfc9Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMymfc9Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMFC9DOC_H__BE822B58_048D_4A74_80F9_80D0FE53DB40__INCLUDED_)

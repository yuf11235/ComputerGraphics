// CDTest002Doc.h : interface of the CCDTest002Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CDTEST002DOC_H__F4AA2B77_CE3B_41BA_BD7B_98A11968DBFC__INCLUDED_)
#define AFX_CDTEST002DOC_H__F4AA2B77_CE3B_41BA_BD7B_98A11968DBFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCDTest002Doc : public CDocument
{
protected: // create from serialization only
	CCDTest002Doc();
	DECLARE_DYNCREATE(CCDTest002Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDTest002Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCDTest002Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCDTest002Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDTEST002DOC_H__F4AA2B77_CE3B_41BA_BD7B_98A11968DBFC__INCLUDED_)

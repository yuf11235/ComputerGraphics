#if !defined(AFX_CMDLG4_H__201D88CE_07D6_4993_ABC2_37FC1F47A612__INCLUDED_)
#define AFX_CMDLG4_H__201D88CE_07D6_4993_ABC2_37FC1F47A612__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlg4 dialog

class CCDTest002View;

class CCMDlg4 : public CDialog
{
// Construction
public:
	CCMDlg4(CWnd* pParent = NULL);   // standard constructor

	BOOL Create();


	CCDTest002View * m_pView4;
// Dialog Data
	//{{AFX_DATA(CCMDlg4)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg4)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG4_H__201D88CE_07D6_4993_ABC2_37FC1F47A612__INCLUDED_)

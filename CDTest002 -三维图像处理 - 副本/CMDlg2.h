#if !defined(AFX_CMDLG2_H__A4B38928_C2C2_4B7D_B314_0566E2320972__INCLUDED_)
#define AFX_CMDLG2_H__A4B38928_C2C2_4B7D_B314_0566E2320972__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlg2 dialog


class CCDTest002View;

class CCMDlg2 : public CDialog
{
// Construction
public:
	CCMDlg2(CWnd* pParent = NULL);   // standard constructor

	BOOL Create();

	CCDTest002View * m_pView2;
// Dialog Data
	//{{AFX_DATA(CCMDlg2)
	enum { IDD = IDD_DIALOG2 };
	int		m_angle;
	int		m_pointx;
	int		m_pointy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg2)
	afx_msg void OnButton1();
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG2_H__A4B38928_C2C2_4B7D_B314_0566E2320972__INCLUDED_)

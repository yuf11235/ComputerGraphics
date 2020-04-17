#if !defined(AFX_CMDLG_H__6925092A_F540_42C6_9EA0_C2D7A3E8A3CA__INCLUDED_)
#define AFX_CMDLG_H__6925092A_F540_42C6_9EA0_C2D7A3E8A3CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlg dialog


class CCDTest002View;



class CCMDlg : public CDialog
{
// Construction
public:
	CCMDlg(CWnd* pParent = NULL);   // standard constructor

	BOOL Create();


	CCDTest002View * m_pView;



// Dialog Data
	//{{AFX_DATA(CCMDlg)
	enum { IDD = IDD_DIALOG1 };
	int		m_x;
	int		m_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg)
	afx_msg void OnChangeEdit3();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG_H__6925092A_F540_42C6_9EA0_C2D7A3E8A3CA__INCLUDED_)

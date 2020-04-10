#if !defined(AFX_CMDLG3_H__93B07BF3_A125_4F7E_B860_A547E075E603__INCLUDED_)
#define AFX_CMDLG3_H__93B07BF3_A125_4F7E_B860_A547E075E603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlg3 dialog


class CCDTest002View;



class CCMDlg3 : public CDialog
{
// Construction
public:
	CCMDlg3(CWnd* pParent = NULL);   // standard constructor

	BOOL Create();


	CCDTest002View * m_pView3;



// Dialog Data
	//{{AFX_DATA(CCMDlg3)
	enum { IDD = IDD_DIALOG3 };
	float	m_zoomRatio;
	int		m_zoomX;
	int		m_zoomY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg3)
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG3_H__93B07BF3_A125_4F7E_B860_A547E075E603__INCLUDED_)

#if !defined(AFX_CMDLG5_H__085F4E56_1C46_42CF_9544_AFAA694B5F8F__INCLUDED_)
#define AFX_CMDLG5_H__085F4E56_1C46_42CF_9544_AFAA694B5F8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlg5 dialog


class CCDTest002View;



class CCMDlg5 : public CDialog
{
// Construction
public:
	CCMDlg5(CWnd* pParent = NULL);   // standard constructor

	BOOL Create();


	CCDTest002View * m_pView5;
// Dialog Data
	//{{AFX_DATA(CCMDlg5)
	enum { IDD = IDD_DIALOG5 };
	int		m_R;
	int		m_G;
	int		m_B;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg5)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG5_H__085F4E56_1C46_42CF_9544_AFAA694B5F8F__INCLUDED_)

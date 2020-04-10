#if !defined(AFX_CMDLG4_H__84730E70_EDE4_4772_80BD_01372D95BB82__INCLUDED_)
#define AFX_CMDLG4_H__84730E70_EDE4_4772_80BD_01372D95BB82__INCLUDED_

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
	int		m_3DX;
	int		m_3DY;
	int		m_3DZ;
	int		m_3DANGLE;
	CString	m_ROTATEAXIS;
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
	afx_msg void OnOutofmemorySpin1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnOutofmemorySpin4(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG4_H__84730E70_EDE4_4772_80BD_01372D95BB82__INCLUDED_)

#if !defined(AFX_CMDLGFOR3D_H__50397281_61C4_4C92_B6E8_3E2A04E50790__INCLUDED_)
#define AFX_CMDLGFOR3D_H__50397281_61C4_4C92_B6E8_3E2A04E50790__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlgFor3D.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlgFor3D dialog


class CCDTest002View;



class CCMDlgFor3D : public CDialog
{
// Construction
public:
	CCMDlgFor3D(CWnd* pParent = NULL);   // standard constructor

	BOOL Create();


	CCDTest002View * m_pView3D;

// Dialog Data
	//{{AFX_DATA(CCMDlgFor3D)
	enum { IDD = IDD_DIALOG4 };
	int		m_3DX;
	int		m_3DY;
	int		m_3DExtern;
	int		m_3DRotate;
	CString	m_3DRotateAxis;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlgFor3D)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlgFor3D)
	virtual void OnOK();
	afx_msg void OnOutofmemorySpin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOutofmemorySpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLGFOR3D_H__50397281_61C4_4C92_B6E8_3E2A04E50790__INCLUDED_)

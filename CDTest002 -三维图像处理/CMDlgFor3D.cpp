// CMDlgFor3D.cpp : implementation file
//

#include "stdafx.h"
#include "CDTest002.h"
#include "CMDlgFor3D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlgFor3D dialog

#include "CDTest002View.h"

CCMDlgFor3D::CCMDlgFor3D(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlgFor3D::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlgFor3D)
	m_3DX = 0;
	m_3DY = 0;
	m_3DExtern = 0;
	m_3DRotate = 0;
	m_3DRotateAxis = _T("");
	//}}AFX_DATA_INIT
}

BOOL CCMDlgFor3D::Create()
{
	return CDialog::Create(CCMDlgFor3D::IDD);
}


void CCMDlgFor3D::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlgFor3D)
	DDX_Text(pDX, IDC_EDIT1, m_3DX);
	DDX_Text(pDX, IDC_EDIT2, m_3DY);
	DDX_Text(pDX, IDC_EDIT4, m_3DExtern);
	DDX_Text(pDX, IDC_EDIT5, m_3DRotate);
	DDX_CBString(pDX, IDC_COMBO1, m_3DRotateAxis);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlgFor3D, CDialog)
	//{{AFX_MSG_MAP(CCMDlgFor3D)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN2, OnOutofmemorySpin2)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN1, OnOutofmemorySpin1)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlgFor3D message handlers

void CCMDlgFor3D::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CCMDlgFor3D::OnOutofmemorySpin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CCMDlgFor3D::OnOutofmemorySpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CCMDlgFor3D::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void CCMDlgFor3D::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

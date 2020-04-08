// CMDlg4.cpp : implementation file
//

#include "stdafx.h"
#include "CDTest002.h"
#include "CMDlg4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg4 dialog

#include "CDTest002View.h"


CCMDlg4::CCMDlg4(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg4)
	m_3DX = 0;
	m_3DY = 0;
	m_3DZ = 0;
	m_3DANGLE = 0;
	m_ROTATEAXIS = _T("");
	//}}AFX_DATA_INIT
}

BOOL CCMDlg4::Create()
{
	return CDialog::Create(CCMDlg4::IDD);
}


void CCMDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg4)
	DDX_Text(pDX, IDC_EDIT1, m_3DX);
	DDX_Text(pDX, IDC_EDIT2, m_3DY);
	DDX_Text(pDX, IDC_EDIT3, m_3DZ);
	DDX_Text(pDX, IDC_EDIT4, m_3DANGLE);
	DDX_CBString(pDX, IDC_COMBO1, m_ROTATEAXIS);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg4, CDialog)
	//{{AFX_MSG_MAP(CCMDlg4)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN1, OnOutofmemorySpin1)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN4, OnOutofmemorySpin4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, OnDeltaposSpin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, OnDeltaposSpin3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg4 message handlers

void CCMDlg4::OnOutofmemorySpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	*pResult = 0;
}


void CCMDlg4::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	// this->m_pView4->m_
	this->m_pView4->m_zLength = this->m_3DZ;

	this->m_pView4->Extern();

	this->m_pView4->Invalidate(TRUE);

	UpdateData(FALSE);
	CDialog::OnOK();
}


void CCMDlg4::OnOutofmemorySpin4(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CCMDlg4::OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CCMDlg4::OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_3DZ -= 1*pNMUpDown->iDelta;

	this->m_pView4->m_zLength = this->m_3DZ;

	this->m_pView4->Extern();

	this->m_pView4->Invalidate(TRUE);

	UpdateData(FALSE);
	*pResult = 0;
}

// CMDlg5.cpp : implementation file
//

#include "stdafx.h"
#include "CDTest002.h"
#include "CMDlg5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg5 dialog

#include "CDTest002View.h"


CCMDlg5::CCMDlg5(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg5::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg5)
	m_R = 255;
	m_G = 0;
	m_B = 0;
	//}}AFX_DATA_INIT
}

BOOL CCMDlg5::Create()
{
	return CDialog::Create(CCMDlg5::IDD);
}


void CCMDlg5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg5)
	DDX_Text(pDX, IDC_EDIT1, m_R);
	DDX_Text(pDX, IDC_EDIT2, m_G);
	DDX_Text(pDX, IDC_EDIT3, m_B);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg5, CDialog)
	//{{AFX_MSG_MAP(CCMDlg5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg5 message handlers

void CCMDlg5::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	this->m_pView5->m_iR = this->m_R;
	this->m_pView5->m_iG = this->m_G;
	this->m_pView5->m_iB = this->m_B;
	this->m_pView5->Invalidate(TRUE);

	UpdateData(FALSE);
	//CDialog::OnOK();
}

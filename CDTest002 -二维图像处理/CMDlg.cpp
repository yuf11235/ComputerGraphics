// CMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CDTest002.h"
#include "CMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "CDTest002View.h"



/////////////////////////////////////////////////////////////////////////////
// CCMDlg dialog


CCMDlg::CCMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg)
	m_x = 0;
	m_y = 0;
	//}}AFX_DATA_INIT
}

BOOL CCMDlg::Create()
{
	return CDialog::Create(CCMDlg::IDD);
}


void CCMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg)
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg, CDialog)
	//{{AFX_MSG_MAP(CCMDlg)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg message handlers

void CCMDlg::OnChangeEdit3() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
}

void CCMDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CPoint pt;
	pt.x = this->m_x;
	pt.y = this->m_y;
	this->m_pView->m_pt_array.Add(pt);
	this->m_pView->Invalidate();
}

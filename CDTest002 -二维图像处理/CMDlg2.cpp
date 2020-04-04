// CMDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "CDTest002.h"
#include "CMDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg2 dialog

#include "CDTest002View.h"


CCMDlg2::CCMDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg2)
	m_angle = 0;
	m_pointx = 0;
	m_pointy = 0;
	//}}AFX_DATA_INIT
}

BOOL CCMDlg2::Create()
{
	return CDialog::Create(CCMDlg2::IDD);
}

void CCMDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg2)
	DDX_Text(pDX, IDC_EDIT1, m_angle);
	DDX_Text(pDX, IDC_EDIT2, m_pointx);
	DDX_Text(pDX, IDC_EDIT3, m_pointy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg2, CDialog)
	//{{AFX_MSG_MAP(CCMDlg2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg2 message handlers

void CCMDlg2::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CPoint pt;
	pt.x = this->m_pointx;
	pt.y = this->m_pointy;
	this->m_pView2->m_point_Array.Add(pt);
	this->m_pView2->Invalidate();
}

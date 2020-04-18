// CMDlg3.cpp : implementation file
//

#include "stdafx.h"
#include "CDTest002.h"
#include "CMDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg3 dialog

#include "CDTest002View.h"


CCMDlg3::CCMDlg3(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg3)
	m_zoomRatio = 0.0f;
	m_zoomX = 0;
	m_zoomY = 0;
	//}}AFX_DATA_INIT
}

BOOL CCMDlg3::Create()
{
	return CDialog::Create(CCMDlg3::IDD);
}

void CCMDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg3)
	DDX_Text(pDX, IDC_EDIT1, m_zoomRatio);
	DDX_Text(pDX, IDC_EDIT2, m_zoomX);
	DDX_Text(pDX, IDC_EDIT3, m_zoomY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg3, CDialog)
	//{{AFX_MSG_MAP(CCMDlg3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg3 message handlers

void CCMDlg3::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	double ratio;
	double x_ledge, y_ledge;
	double m_Matrix0_2D[3][3];

	x_ledge = this->m_zoomX;
	y_ledge = this->m_zoomY;
	ratio = 1 / this->m_zoomRatio;

	m_pView3->GetMatrix(m_pView3->m_Matrix_2D, 0, 0, (-1)*x_ledge, (-1)*y_ledge, 0);

	m_pView3->GetMatrix(m_Matrix0_2D, 6, 0, 0, 0, ratio);
	m_pView3->MatrixXMatrix(m_pView3->m_Matrix_2D, m_Matrix0_2D);

	m_pView3->GetMatrix(m_Matrix0_2D, 0, 0, x_ledge, y_ledge, 0);
	m_pView3->MatrixXMatrix(m_pView3->m_Matrix_2D, m_Matrix0_2D);

	m_pView3->GetNewPoint();
	this->m_pView3->Invalidate();
}

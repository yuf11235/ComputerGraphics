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
	m_3DY = 0;
	m_3DZ = 0;
	m_3DANGLE = 0;
	m_ROTATEAXIS = _T("");
	m_3DZoomRatio = 1.0;
	m_AXIS = 1;
	m_3DX = 0;
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
	DDX_Text(pDX, IDC_EDIT2, m_3DY);
	DDX_Text(pDX, IDC_EDIT3, m_3DZ);
	DDX_Text(pDX, IDC_EDIT4, m_3DANGLE);
	DDX_CBString(pDX, IDC_COMBO1, m_ROTATEAXIS);
	DDX_Text(pDX, IDC_EDIT5, m_3DZoomRatio);
	DDX_Text(pDX, IDC_EDIT6, m_AXIS);
	DDX_Text(pDX, IDC_EDIT1, m_3DX);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg4, CDialog)
	//{{AFX_MSG_MAP(CCMDlg4)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN1, OnOutofmemorySpin1)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN4, OnOutofmemorySpin4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, OnDeltaposSpin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, OnDeltaposSpin3)
	ON_EN_CHANGE(IDC_EDIT6, OnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON1, OnStartAnimation)
	ON_BN_CLICKED(IDC_BUTTON2, OnFinishAnimation)
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

	this->m_pView4->m_i3DZoomRatio = this->m_3DZoomRatio;
	// double m_Matrix[4][4];
	// double m_Matrix0[4][4];
	// GetMatrix(m_Matrix, 0, 0, this->m_BottomRightPoint.x - this->m_TopLeftPoint.x, this->m_BottomRightPoint.y - this->m_TopLeftPoint.y, 0);
	// GetNewPoint();
	// this->m_point_Array0.RemoveAll();
	// this->m_point_Array0.Append(this->m_point_Array);
	// this->m_pView4->GetMatrix3D(m_Matrix, 10, 0, 0, 0, 0, 1/this->m_3DZoomRatio);
	// GetMatrix3D(m_Matrix0, 0, m_BottomRightPoint.x - m_TopLeftPoint.x, m_BottomRightPoint.y - m_TopLeftPoint.y, 0, 0, 1);
	// this->m_pView4->GetNewPoint3D(m_Matrix);
	// this->m_pView4->Extern();
	this->m_pView4->Zoom();

	// this->m_pView4->Extern();

	this->m_pView4->Invalidate(TRUE);

	UpdateData(FALSE);
	//CDialog::OnOK();
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
	UpdateData(TRUE);
	this->m_3DANGLE -= 1 * pNMUpDown->iDelta;

	this->m_pView4->m_dblAngle = this->m_3DANGLE;

	this->m_pView4->m_iRotateAxis = this->m_AXIS;

	this->m_pView4->m_zLength = this->m_3DZ;

	this->m_pView4->Rotate();

	// this->m_pView4->Invalidate(TRUE);

	UpdateData(FALSE);
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

void CCMDlg4::OnChangeEdit6() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CCMDlg4::OnStartAnimation() 
{
	// TODO: Add your control notification handler code here
	this->m_pView4->SetTimer(1, 100, NULL);
}

void CCMDlg4::OnFinishAnimation() 
{
	// TODO: Add your control notification handler code here
	this->m_pView4->KillTimer(1);
}

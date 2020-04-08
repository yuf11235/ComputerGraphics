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
		// NOTE: the ClassWizard will add member initialization here
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
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg4, CDialog)
	//{{AFX_MSG_MAP(CCMDlg4)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg4 message handlers

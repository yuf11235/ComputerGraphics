// CDTest002Doc.cpp : implementation of the CCDTest002Doc class
//

#include "stdafx.h"
#include "CDTest002.h"

#include "CDTest002Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDTest002Doc

IMPLEMENT_DYNCREATE(CCDTest002Doc, CDocument)

BEGIN_MESSAGE_MAP(CCDTest002Doc, CDocument)
	//{{AFX_MSG_MAP(CCDTest002Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDTest002Doc construction/destruction

CCDTest002Doc::CCDTest002Doc()
{
	// TODO: add one-time construction code here

}

CCDTest002Doc::~CCDTest002Doc()
{
}

BOOL CCDTest002Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCDTest002Doc serialization

void CCDTest002Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCDTest002Doc diagnostics

#ifdef _DEBUG
void CCDTest002Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCDTest002Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCDTest002Doc commands

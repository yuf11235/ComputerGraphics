// CDTest002View.h : interface of the CCDTest002View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CDTEST002VIEW_H__F8A25D10_33E1_4DAD_A6AE_EC3F590F98EE__INCLUDED_)
#define AFX_CDTEST002VIEW_H__F8A25D10_33E1_4DAD_A6AE_EC3F590F98EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "CMDlg.h"


class CCDTest002Doc;




class CCDTest002View : public CView
{
protected: // create from serialization only
	CCDTest002View();
	DECLARE_DYNCREATE(CCDTest002View)

// Attributes
public:
	CCDTest002Doc* GetDocument();

	CCMDlg *m_MDlg;

	CArray<CPoint, CPoint> m_point_Array;// to store point which pickuped by the left mouse botton

	CPoint pt;

	int flag;//0-point; 1-polyline; 2-seperate lines; 3-polygon
	int finished;//0-not close; 1-close
	CPoint pt0, pt1;
	void DDA_Line(CDC * pDC, CPoint startPoint, CPoint endPoint);
// Operations
public:
	int m_iFillFLag;//0-not fill; 1-fill
	void scanTransfer(CDC * pDC);

	int m_iDeleteFlag;//0-not delete; 1-delete

	CPoint m_TopLeftPoint, m_BottomRightPoint;// to make up the rectangle clipping area
	int m_iClipFlag;//0-not clip; 1-pick up TopLeft; 2-pick up BottomRight; 3-start to clip the polyline; 4-show the result
	void CutPolyLine();



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDTest002View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCDTest002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCDTest002View)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMg();
	afx_msg void OnFillcolor();
	afx_msg void OnDrawpolyline();
	afx_msg void OnPolygon();
	afx_msg void OnMutiplyline();
	afx_msg void OnBin();
	afx_msg void OnClippolyline();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CDTest002View.cpp
inline CCDTest002Doc* CCDTest002View::GetDocument()
   { return (CCDTest002Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDTEST002VIEW_H__F8A25D10_33E1_4DAD_A6AE_EC3F590F98EE__INCLUDED_)



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
#include "CMDlg2.h"
#include "CMDlg3.h"
#include "CMDlg4.h"
#define PI 3.1415926
#include <cmath>
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
	CCMDlg2 *m_MDlg2;
	CCMDlg3 *m_MDlg3;
	CCMDlg4 *m_MDlg4;

	CArray<CPoint, CPoint> m_point_Array;// to store point which pickuped by the left mouse botton
	CArray<CPoint, CPoint> m_point_Array1;// to store point which copied from m_point_Array
	CArray<CPoint, CPoint> m_point_Array0;// to store point which copied from m_point_Array

	CPoint pt;

	int flag;//0-point; 1-polyline; 2-seperate lines; 3-polygon
	int finished;//0-not close; 1-close
	CPoint pt0, pt1;
	void DDA_Line(CDC * pDC, CPoint startPoint, CPoint endPoint);

	//for 3d
	double m_zLength;//拉伸长度
	double m_dblAngle;//旋转角度
	int m_iPointNum;
	int m_iRotateAxis;
	int m_i3DFlag;//是否已有3D顶点
	int m_i3DTypeFlag;//1-移动，2-放缩
	double (*Point0)[4];// = new double[m_iPointNum][4];
	double (*Point1)[4];// = new double[m_iPointNum][4];
	double (*Point2)[4];// = new double[m_iPointNum][4];
	double (*Point3)[4];// = new double[m_iPointNum][4];
// Operations
public:
	int m_iFillFLag;//0-not fill; 1-fill
	int m_iGetTwoPoint;
	void scanTransfer(CDC * pDC);

	int m_iDeleteFlag;//0-not delete; 1-delete

	CPoint m_TopLeftPoint, m_BottomRightPoint;// to make up the rectangle clipping area
	int m_iClipFlag;//0-not clip; 1-pick up TopLeft; 2-pick up BottomRight; 3-start to clip the polyline; 4-show the result
	void CutPolyLine();

	int m_iTypeFlag;//m_iTypeFlag 1-移动， 2-旋转， 3-x轴镜像， 4-y轴镜像， 5-x轴错移， 6-y轴错移， 7-比例放缩
	double m_Matrix[][3];//齐次矩阵
	// iFlag/: 0-移动， 1-旋转， 2-x轴镜像， 3-y轴镜像， 4-x轴错移， 5-y轴错移， 6-比例放缩
	void GetMatrix(double matrix[][3], int iFlag, double rotateAngle, double x_dis, double y_dis, double dbl_zoom);
	void GetNewPoint();
	void MatrixXMatrix(double matrix0[][3], double matrix1[][3]);
///*
	// for 3d
	// double m_zLength;//拉伸长度
	// double m_dblAngle;//旋转角度
	// int m_iPointNum;
	void GetMatrix3D(double matrix[][4], int iFlag, double x_dis, double y_dis, double z_dis, double rotateAngle, double dbl_zoom);
	//iFlag：0-移动，1：x轴旋转，2-y轴旋转，3-z轴旋转，4-x镜像，5-y镜像，6-z镜像，7-x错移，8-y错移，9-z错移，10-缩放
	void GetNewPoint3D(double m_Matrix[][4]);
	void MatrixXMatrix3D(double matrix0[][4], double matrix1[][4]);

	// int m_iRotateAxis;
	void Extern();//拉伸
	void Rotate();//旋转

	// int m_i3DFlag;//是否已有3D顶点
	// double (*Point0)[4];// = new double[m_iPointNum][4];
	// double (*Point1)[4];// = new double[m_iPointNum][4];
	// double (*Point2)[4];// = new double[m_iPointNum][4];
	// double (*Point3)[4];// = new double[m_iPointNum][4];

	//for 3d
//*/


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
	afx_msg void OnOnMove();
	afx_msg void OnMirror();
	afx_msg void OnMg2();
	afx_msg void OnZoom();
	afx_msg void On3d();
	afx_msg void On3dmove();
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



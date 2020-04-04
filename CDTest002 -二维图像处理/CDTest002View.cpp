// CDTest002View.cpp : implementation of the CCDTest002View class
//

#include "stdafx.h"
#include "CDTest002.h"

#include "CDTest002Doc.h"
#include "CDTest002View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDTest002View

IMPLEMENT_DYNCREATE(CCDTest002View, CView)

BEGIN_MESSAGE_MAP(CCDTest002View, CView)
	//{{AFX_MSG_MAP(CCDTest002View)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_MG, OnMg)
	ON_COMMAND(ID_FILLCOLOR, OnFillcolor)
	ON_COMMAND(ID_DRAWPOLYLINE, OnDrawpolyline)
	ON_COMMAND(ID_POLYGON, OnPolygon)
	ON_COMMAND(ID_MUTIPLYLINE, OnMutiplyline)
	ON_COMMAND(ID_BIN, OnBin)
	ON_COMMAND(ID_CLIPPOLYLINE, OnClippolyline)
	ON_COMMAND(ID_ONMOVE, OnOnMove)
	ON_COMMAND(ID_MIRROR, OnMirror)
	ON_COMMAND(ID_MG2, OnMg2)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDTest002View construction/destruction

CCDTest002View::CCDTest002View()
{
	// TODO: add construction code here
	this->flag=0;
	this->finished=0;
	this->m_MDlg=new CCMDlg();
	this->m_MDlg2=new CCMDlg2();
	this->m_iFillFLag=0;
	this->m_MDlg->m_pView=this;
	this->m_MDlg2->m_pView2=this;
	this->m_iClipFlag = 0;
	this->m_iDeleteFlag = 0;
	this->m_iGetTwoPoint = 0;
	this->m_iTypeFlag = 0;
}

CCDTest002View::~CCDTest002View()
{
	if(this->m_MDlg!=NULL)
		delete this->m_MDlg;
	if(this->m_MDlg2!=NULL)
		delete this->m_MDlg2;
}

BOOL CCDTest002View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCDTest002View drawing

void CCDTest002View::OnDraw(CDC* pDC)
{
	CCDTest002Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CString str;
	CPoint pt_1, pt_2;
	CPoint pt_0;
	CPoint pt_4clip1, pt_4clip2;// for clip

	if(this->m_iDeleteFlag == 1)
	{
		this->m_point_Array.RemoveAll();
		this->m_iDeleteFlag = 0;
		return;
	}



	// 画多个点
	if(this->flag==0)
	{
		for(int i = 0; i < this->m_point_Array.GetSize(); i++)
		{
			pt_1 = this->m_point_Array.GetAt(i);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			pDC->SetPixel(pt_1.x+1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x-1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y+1, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y-1, RGB(255, 0, 0));
		}
	}
	// 画连续的折线
	else if(this->flag==1)
	{
		// 第一个点
		if(this->m_point_Array.GetSize() == 1)
		{
			
			pt_1 = this->m_point_Array.GetAt(0);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			pDC->SetPixel(pt_1.x, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x+1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x-1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y+1, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y-1, RGB(255, 0, 0));
		}
		// 连线
		for(int i = 0; i < this->m_point_Array.GetSize()-1; i++)
		{
			pt_1 = this->m_point_Array.GetAt(i);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			//pDC->SetPixel(pt_1.x, pt_1.y, RGB(255, 0, 0));

			pt_2 = this->m_point_Array.GetAt(i+1);

			str.Format("(%d, %d)", pt_2.x, pt_2.y);
			pDC->TextOut(pt_2.x, pt_2.y, str);

			this->DDA_Line(pDC, pt_1, pt_2);
		}
	}
	// 画多条分离的线
	else if(this->flag==2)
	{
		// 第一个点
		if(this->m_point_Array.GetSize() == 1)
		{
			
			pt_1 = this->m_point_Array.GetAt(0);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			pDC->SetPixel(pt_1.x, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x+1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x-1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y+1, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y-1, RGB(255, 0, 0));
		}
		// 连线
		for(int i = 0; i < this->m_point_Array.GetSize() / 2; i++)
		{
			pt_1 = this->m_point_Array.GetAt(2*i);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			//pDC->SetPixel(pt_1.x, pt_1.y, RGB(255, 0, 0));

			pt_2 = this->m_point_Array.GetAt(2*i+1);

			str.Format("(%d, %d)", pt_2.x, pt_2.y);
			pDC->TextOut(pt_2.x, pt_2.y, str);

			this->DDA_Line(pDC, pt_1, pt_2);
		}
	}
	else if(this->flag == 3)
	{
		//画多边形
				// 第一个点
		if(this->m_point_Array.GetSize() == 1)
		{
			
			pt_1 = this->m_point_Array.GetAt(0);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			pDC->SetPixel(pt_1.x, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x+1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x-1, pt_1.y, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y+1, RGB(255, 0, 0));
			pDC->SetPixel(pt_1.x, pt_1.y-1, RGB(255, 0, 0));
		}
		// 连线
		for(int i = 0; i < this->m_point_Array.GetSize()-1; i++)
		{
			pt_1 = this->m_point_Array.GetAt(i);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			//pDC->SetPixel(pt_1.x, pt_1.y, RGB(255, 0, 0));

			pt_2 = this->m_point_Array.GetAt(i+1);

			str.Format("(%d, %d)", pt_2.x, pt_2.y);
			pDC->TextOut(pt_2.x, pt_2.y, str);

			this->DDA_Line(pDC, pt_1, pt_2);
		}
		// polygon多边形，右键闭合，整合为按钮吧
		if(finished==1)
		{
			pt_0 = this->m_point_Array.GetAt(0);
			this->DDA_Line(pDC, pt_2, pt_0);
			// this->finished = 0;
		}
	}

	if(this->m_iFillFLag==1)
	{
		// fill the figure with yellow color
		if(this->m_point_Array.GetSize()>=3)
		{
			scanTransfer(pDC);
			// this->m_iFillFLag = 0;
		}
	}

	if(this->m_iClipFlag == 2)
	{
		pt_4clip1.x = this->m_TopLeftPoint.x;
		pt_4clip1.y = this->m_BottomRightPoint.y;
		pt_4clip2.x = this->m_BottomRightPoint.x;
		pt_4clip2.y = this->m_TopLeftPoint.y;

		str.Format("(%d, %d)", pt_4clip1.x, pt_4clip1.y);
		pDC->TextOut(pt_4clip1.x, pt_4clip1.y, str);
		str.Format("(%d, %d)", pt_4clip2.x, pt_4clip2.y);
		pDC->TextOut(pt_4clip2.x, pt_4clip2.y, str);
		str.Format("(%d, %d)", m_TopLeftPoint.x, m_TopLeftPoint.y);
		pDC->TextOut(m_TopLeftPoint.x, m_TopLeftPoint.y, str);
		str.Format("(%d, %d)", m_BottomRightPoint.x, m_BottomRightPoint.y);
		pDC->TextOut(m_BottomRightPoint.x, m_BottomRightPoint.y, str);

		this->DDA_Line(pDC, m_TopLeftPoint, pt_4clip1);
		this->DDA_Line(pDC, pt_4clip1, m_BottomRightPoint);
		this->DDA_Line(pDC, pt_4clip2, m_BottomRightPoint);
		this->DDA_Line(pDC, pt_4clip2, m_TopLeftPoint);

		CutPolyLine();

		for(int i = 0; i < this->m_point_Array.GetSize()-1; i++)
		{
			pt_1 = this->m_point_Array.GetAt(i);
			
			str.Format("(%d, %d)", pt_1.x, pt_1.y);
			pDC->TextOut(pt_1.x, pt_1.y, str);
			//pDC->SetPixel(pt_1.x, pt_1.y, RGB(255, 0, 0));

			pt_2 = this->m_point_Array.GetAt(i+1);

			str.Format("(%d, %d)", pt_2.x, pt_2.y);
			pDC->TextOut(pt_2.x, pt_2.y, str);

			this->DDA_Line(pDC, pt_1, pt_2);
		}
		this->DDA_Line(pDC, pt_2, this->m_point_Array.GetAt(0));
		this->m_iClipFlag = 0;
		// this->m_iGetTwoPoint = 0;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCDTest002View printing

void CCDTest002View::DDA_Line(CDC * pDC, CPoint startPoint, CPoint endPoint)
{
	//处理特殊情况
	if(startPoint.x==endPoint.x)//垂直画线
	{
		if(startPoint.y<endPoint.y)
		{
			for(int i=startPoint.y;i<=endPoint.y;i++)
			{
				pDC->SetPixel(startPoint.x,i,RGB(0,255,255));
			}
		}
		else if(startPoint.y>endPoint.y)
		{
			for(int i=startPoint.y;i>=endPoint.y;i--)
			{
				pDC->SetPixel(startPoint.x,i,RGB(0,0,255));
			}
		}
	}

	else if(startPoint.y==endPoint.y)//画水平线
	{
		if(startPoint.x<endPoint.x)
		{
			for(int i=startPoint.x;i<endPoint.x;i++)
			{
				pDC->SetPixel(i,startPoint.y,RGB(255,0,0));
			}
		}
		else if(startPoint.x>endPoint.x)
		{
			for(int i=startPoint.x;i>=endPoint.x;i--)
			{
				pDC->SetPixel(i,startPoint.y,RGB(255,0,0));
			}
		}
	}

	int kFlag=0;//0:斜率<=1 1:斜率>1
	int sFlag=1;//斜率正负的标识
	//首先判断两个端点，通过交换使起点X小于终点X，
	if(startPoint.x>endPoint.x)
	{
		CPoint pt=startPoint;
		startPoint=endPoint;
		endPoint=pt;
	}
	if(abs(endPoint.y-startPoint.y)>abs(endPoint.x-startPoint.x))
	{
		kFlag=1;//如果斜率大于1
	}
	//如果斜率小于0,则进行标识
	if(startPoint.y>endPoint.y)
		sFlag=-1;
	int a,b,tA,tAB,d,x,y;
	if(sFlag==-1)
	{
		endPoint.y=startPoint.y+(startPoint.y-endPoint.y);
	}
	a=startPoint.y-endPoint.y;		
	b=endPoint.x-startPoint.x;
	tA=2*a;
	tAB=2*(a+b);
	d=2*a+b;

	x=startPoint.x;
	y=startPoint.y;
	pDC->SetPixel(x,y,RGB(255,0,0));
	if(kFlag==0)//斜率<=1
	{
		for(int i=0;i<(endPoint.x-startPoint.x);i++)
		{
			if(d>=0)
			{
				pDC->SetPixel(x+1,y,RGB(255,0,0));//取点(x+1,y)
				x+=1;
				d+=tA;
			}
			else//d<0
			{
				pDC->SetPixel(x+1,y+sFlag,RGB(255,0,0));//取点(x+1,y+1)
				x+=1;
				y+=sFlag;
				d+=tAB;
			}
		}
	}
	else//斜率>1
	{
		if(kFlag==1)
		{
			tA=2*b;
			d=2*b+a;
		}
		for(int i=0;i<abs(endPoint.y-startPoint.y);i++)
		{
			if(d>=0)
			{
				pDC->SetPixel(x+1,y+sFlag ,RGB(255,0,0));//取点(x,y+1)
				y+=sFlag;
				x+=1;
				d+=tAB;
			}
			else//d<0
			{
				pDC->SetPixel(x,y+sFlag,RGB(255,0,0));//取点(x+1,y+1)
				y+=sFlag;
				d+=tA;
			}
		}
	}

}

BOOL CCDTest002View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCDTest002View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCDTest002View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCDTest002View diagnostics

#ifdef _DEBUG
void CCDTest002View::AssertValid() const
{
	CView::AssertValid();
}

void CCDTest002View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCDTest002Doc* CCDTest002View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCDTest002Doc)));
	return (CCDTest002Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCDTest002View message handlers

void CCDTest002View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("(%d, %d)", point.x, point.y);
	if (this->m_iGetTwoPoint == 0)
	{
		// 正常取点、画线和多边形
		if(finished==0)
			this->m_point_Array.Add(point);
		else if(finished==1)
			return;
	}
	else if(this->m_iGetTwoPoint == 1)
	{
		this->m_TopLeftPoint = point;
		if(this->m_iClipFlag == 1 || this->m_iTypeFlag == 1 || this->m_iTypeFlag == 2)
		{
			this->m_iGetTwoPoint = 2;
		}
		else if(this->m_iTypeFlag == 3 || this->m_iTypeFlag == 4)
		{

			this->m_iGetTwoPoint = 0;
		}
	}
	else if(this->m_iGetTwoPoint == 2 )
	{
		this->m_BottomRightPoint = point;
		if(this->m_iClipFlag == 1)
		{
			this->m_iClipFlag = 2;
		}

		if(this->m_iTypeFlag == 1)
		{
			GetMatrix(m_Matrix, 0, 0, this->m_BottomRightPoint.x - this->m_TopLeftPoint.x, this->m_BottomRightPoint.y - this->m_TopLeftPoint.y, 0);
			GetNewPoint();
			this->m_iTypeFlag = 0;
		}
		else if(this->m_iTypeFlag == 2)
		{
			int a, b, c;
			double m_dblY, angle; 
			int x0, y0, x1, y1;
			double y_ledge;

			x0 = m_TopLeftPoint.x;
			y0 = m_TopLeftPoint.y;
			x1 = m_BottomRightPoint.x;
			y1 = m_BottomRightPoint.y;
			a = y0 - y1;
			b = x1 - x0;
 
			c = x0*y1 - x1*y0;

			y_ledge = m_dblY = (-1)*c / (double) b;
			y_ledge = (int)(m_dblY+0.5);

			angle = atan((-1)*(double(a)) / (double)b);
			angle = angle*180 / PI; 

			double m_Matrix0[3][3];
			// void GetMatrix(double matrix[][3], int iFlag, double rotateAngle, double x_dis, double y_dis, double dbl_zoom);
			GetMatrix(this->m_Matrix, 0, 0, 0, (-1)*y_ledge, 0);

			GetMatrix(m_Matrix0, 1, (-1)*angle, 0, 0, 0);
			MatrixXMatrix(this->m_Matrix, m_Matrix0);

			GetMatrix(m_Matrix0, 2, 0, 0, 0, 0);
			MatrixXMatrix(this->m_Matrix, m_Matrix0);

			GetMatrix(m_Matrix0, 1, angle, 0, 0, 0);
			MatrixXMatrix(this->m_Matrix, m_Matrix0);

			GetMatrix(m_Matrix0, 0, 0, 0, y_ledge, 0);
			MatrixXMatrix(this->m_Matrix, m_Matrix0);

			GetNewPoint();
			this->m_iTypeFlag = 0;
		}
		this->m_iGetTwoPoint = 0;
	}
	// else if(this->m_iClipFlag == 4)
	// {
	// 	this->m_iClipFlag = 0;
	// }

	if(this->m_MDlg->GetSafeHwnd()!=NULL)
	{
		this->m_MDlg->m_x=point.x;
		this->m_MDlg->m_y=point.y;
		this->m_MDlg->UpdateData(FALSE);
	}
	if(this->m_MDlg2->GetSafeHwnd()!=NULL)
	{
		this->m_MDlg2->m_pointx=point.x;
		this->m_MDlg2->m_pointy=point.y;
		this->m_MDlg2->UpdateData(FALSE);
	}
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CCDTest002View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDown(nFlags, point);
}

void CCDTest002View::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("现在是鼠标r键点击！");
	if(this->finished==0)
	{
		this->finished = 1;
	}
	else if(this->finished==1)
		this->finished = 0;
	Invalidate();
	CView::OnRButtonUp(nFlags, point);
}

void CCDTest002View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonDown(nFlags, point);
}

void CCDTest002View::OnMg() 
{
	// TODO: Add your command handler code here
	if(this->m_MDlg->GetSafeHwnd()==NULL)
	{
		this->m_MDlg->Create();
	}
	else
	{
		this->m_MDlg->ShowWindow(TRUE);
	}
	
}

void InsertPoint_x(CArray<int,int>& m_x_array,int m_x)
{
	//排序
	int i_flag=0;
	for(int i=0;i<m_x_array.GetSize();i++)
	{
		i_flag=0;
		if(m_x<m_x_array.GetAt(i))
		{
			//插入中间
			m_x_array.InsertAt(i,m_x);
			i_flag=1;
			break;
		}
	}
	if(i_flag==0)//加入尾部
		m_x_array.Add(m_x);
}
int GetInterPointX(int yx,int x0,int y0,int x1,int y1)
{
	//求扫描线和线段交点
	int m_x;
	if(yx==y0)
		m_x=x0;
	else if(yx==y1)
		m_x=x1;
	else
	{
		int a=y0-y1;
		int b=x1-x0;
		int c=x0*y1-x1*y0;
		double m_dblX;
		m_dblX=(-1)*(double(b*yx+c))/(double)a;
		m_x=(int)(m_dblX+0.5);
	}
	return  m_x;
}

void CCDTest002View::scanTransfer(CDC* pDC)
{
//扫描转换
	//得到最小和最大扫描线
	int ymin,ymax;
	if(this->m_point_Array.GetAt(0).y<=this->m_point_Array.GetAt(1).y)
	{
		ymin=this->m_point_Array.GetAt(0).y;
		ymax=this->m_point_Array.GetAt(1).y;
	}
	else
	{
		ymin=this->m_point_Array.GetAt(1).y;
		ymax=this->m_point_Array.GetAt(0).y;
	}
	for(int i=2;i<=this->m_point_Array.GetSize()-1;i++)
	{
		if(this->m_point_Array.GetAt(i).y<ymin)
			ymin=this->m_point_Array.GetAt(i).y;
		else  if(this->m_point_Array.GetAt(i).y>ymax)
			ymax=this->m_point_Array.GetAt(i).y;
	}
	//从ymin扫描到 ymax
	this->m_point_Array.Add(m_point_Array.GetAt(0));//首先把首点加到最后一点，使首尾相接，最后删除
	CArray<int,int> m_x_array;//排序后的交点集合
	int m_x;//交点
	int j,k;
	for(int yi=ymin;yi<=ymax;yi++)
	{
		m_x_array.RemoveAll();
		//判断扫描线和那些边相交，如相交，求交点,并排序
		for(i=0;i<m_point_Array.GetSize()-1;i++)
		{			
			if(yi>=m_point_Array.GetAt(i).y&&yi<m_point_Array.GetAt(i+1).y)
			{
		//求交点				
				m_x=GetInterPointX(yi,m_point_Array.GetAt(i).x,m_point_Array.GetAt(i).y,m_point_Array.GetAt(i+1).x,m_point_Array.GetAt(i+1).y);
				InsertPoint_x(m_x_array,m_x);
			}
			else if(yi>=m_point_Array.GetAt(i+1).y&&yi<m_point_Array.GetAt(i).y)
			{
		//求交点			
				m_x=GetInterPointX(yi,m_point_Array.GetAt(i).x,m_point_Array.GetAt(i).y,m_point_Array.GetAt(i+1).x,m_point_Array.GetAt(i+1).y);
				InsertPoint_x(m_x_array,m_x);
			}	
			else if(yi==m_point_Array.GetAt(i+1).y&&yi==m_point_Array.GetAt(i).y)	
			{
		//是水平线,则将两个端点加入点集
				InsertPoint_x(m_x_array,m_point_Array.GetAt(i).x);				
				InsertPoint_x(m_x_array,m_point_Array.GetAt(i+1).x);
			}
		}
	//填充色
	for(j=0;j<=m_x_array.GetSize()-2;j++,j++)
		{
		for(k=m_x_array.GetAt(j);k<=m_x_array.GetAt(j+1);k++)
		pDC->SetPixel(k,yi,RGB(255,255,0));
		}
	}
	this->m_point_Array.RemoveAt(m_point_Array.GetSize()-1);
}

void CCDTest002View::CutPolyLine()
{
	CArray<CPoint, CPoint> m_point_Array1, m_point_Array2, m_point_Array3, m_point_Array4;

	this->m_point_Array.Add(m_point_Array.GetAt(0));// 使首尾相接

	int x_ledge, y_ledge;
	if (this->m_TopLeftPoint.x < this->m_BottomRightPoint.x)
	{
		x_ledge = this->m_TopLeftPoint.x;
	}
	else
	{
		x_ledge = this->m_BottomRightPoint.x;
	}

	int a, b, c;
	double m_dblX, m_dblY;
	int x0, x1, y0, y1;
	CPoint newpoint;
	// 1 x min clip
	for (int i = 0; i < m_point_Array.GetSize()-1; i++)
	{
		if(m_point_Array.GetAt(i).x < x_ledge && m_point_Array.GetAt(i+1).x < x_ledge)
		{
			// refuse
			continue;
		}
		else if(m_point_Array.GetAt(i).x >= x_ledge && m_point_Array.GetAt(i+1).x >= x_ledge)
		{
			// accept
			m_point_Array1.Add(m_point_Array.GetAt(i));
		}
		else
		{
			// compute the interjected point
			x0 = m_point_Array.GetAt(i).x;
			x1 = m_point_Array.GetAt(i+1).x;
			y0 = m_point_Array.GetAt(i).y;
			y1 = m_point_Array.GetAt(i+1).y;
			a = y0 - y1;
			b = x1 - x0;
			c = x0*y1 - x1*y0;

			m_dblY = (-1) * (double(a * x_ledge + c)) / (double)b;
			y_ledge = (int)(m_dblY + 0.5);

			newpoint.x = x_ledge;
			newpoint.y = y_ledge;

			// compute the sequence
			if(m_point_Array.GetAt(i).x < x_ledge)
			{
				// interject 
				m_point_Array1.Add(newpoint);
			}
			else
			{
				m_point_Array1.Add(m_point_Array.GetAt(i));
				m_point_Array1.Add(newpoint);
			}
		}
	}
	// this->m_point_Array.RemoveAll();
	// this->m_point_Array.Append(m_point_Array1);
	// return;

	// 2 y min clip
	if(this->m_TopLeftPoint.y < m_BottomRightPoint.y)
		y_ledge = this->m_TopLeftPoint.y;
	else
		y_ledge = this->m_BottomRightPoint.y;
	m_point_Array1.Add(m_point_Array1.GetAt(0));
	for (i = 0; i < m_point_Array1.GetSize()-1; i++)
	{
		if(m_point_Array1.GetAt(i).y < y_ledge && m_point_Array1.GetAt(i+1).y < y_ledge)
			continue;
		else if(m_point_Array1.GetAt(i).y >= y_ledge && m_point_Array1.GetAt(i+1).y >= y_ledge)
			m_point_Array2.Add(m_point_Array1.GetAt(i));
		else
		{
			// compute the interjected point
			x0 = m_point_Array1.GetAt(i).x;
			x1 = m_point_Array1.GetAt(i+1).x;
			y0 = m_point_Array1.GetAt(i).y;
			y1 = m_point_Array1.GetAt(i+1).y;
			a = y0 - y1;
			b = x1 - x0;
			c = x0*y1 - x1*y0;

			m_dblX = (-1) * (double(b * y_ledge + c)) / (double)a;
			x_ledge = (int)(m_dblX + 0.5);

			newpoint.x = x_ledge;
			newpoint.y = y_ledge;

			// compute the sequence
			if(m_point_Array1.GetAt(i).y < y_ledge)
			{
				// interject 
				m_point_Array2.Add(newpoint);
			}
			else
			{
				m_point_Array2.Add(m_point_Array1.GetAt(i));
				m_point_Array2.Add(newpoint);
			}
		}
	}
	//3 x max clip
	if(this->m_TopLeftPoint.x > m_BottomRightPoint.x)
		x_ledge = this->m_TopLeftPoint.x;
	else
		x_ledge = this->m_BottomRightPoint.x;
	m_point_Array2.Add(m_point_Array2.GetAt(0));
	for (i = 0; i < m_point_Array2.GetSize()-1; i++)
	{
		if(m_point_Array2.GetAt(i).x > x_ledge && m_point_Array2.GetAt(i+1).x > x_ledge)
			continue;
		else if(m_point_Array2.GetAt(i).x <= x_ledge && m_point_Array2.GetAt(i+1).x <= x_ledge)
			m_point_Array3.Add(m_point_Array2.GetAt(i));
		else
		{
			// compute the interjected point
			x0 = m_point_Array2.GetAt(i).x;
			x1 = m_point_Array2.GetAt(i+1).x;
			y0 = m_point_Array2.GetAt(i).y;
			y1 = m_point_Array2.GetAt(i+1).y;
			a = y0 - y1;
			b = x1 - x0;
			c = x0*y1 - x1*y0;

			m_dblY = (-1) * (double(a * x_ledge + c)) / (double)b;
			y_ledge = (int)(m_dblY + 0.5);

			newpoint.x = x_ledge;
			newpoint.y = y_ledge;

			// compute the sequence
			if(m_point_Array2.GetAt(i).x > x_ledge)
			{
				// interject 
				m_point_Array3.Add(newpoint);
			}
			else
			{
				m_point_Array3.Add(m_point_Array2.GetAt(i));
				m_point_Array3.Add(newpoint);
			}
		}
	}
	// 4 y max clip
	if(this->m_TopLeftPoint.y > m_BottomRightPoint.y)
		y_ledge = this->m_TopLeftPoint.y;
	else
		y_ledge = this->m_BottomRightPoint.y;
	m_point_Array3.Add(m_point_Array3.GetAt(0));
	for (i = 0; i < m_point_Array3.GetSize()-1; i++)
	{
		if(m_point_Array3.GetAt(i).y > y_ledge && m_point_Array3.GetAt(i+1).y > y_ledge)
			continue;
		else if(m_point_Array3.GetAt(i).y <= y_ledge && m_point_Array3.GetAt(i+1).y <= y_ledge)
			m_point_Array4.Add(m_point_Array3.GetAt(i));
		else
		{
			// compute the interjected point
			x0 = m_point_Array3.GetAt(i).x;
			x1 = m_point_Array3.GetAt(i+1).x;
			y0 = m_point_Array3.GetAt(i).y;
			y1 = m_point_Array3.GetAt(i+1).y;
			a = y0 - y1;
			b = x1 - x0;
			c = x0*y1 - x1*y0;

			m_dblX = (-1) * (double(b * y_ledge + c)) / (double)a;
			x_ledge = (int)(m_dblX + 0.5);

			newpoint.x = x_ledge;
			newpoint.y = y_ledge;

			// compute the sequence
			if(m_point_Array3.GetAt(i).y > y_ledge)
			{
				// interject 
				m_point_Array4.Add(newpoint);
			}
			else
			{
				m_point_Array4.Add(m_point_Array3.GetAt(i));
				m_point_Array4.Add(newpoint);
			}
		}
	}
	this->m_point_Array.RemoveAll();
	this->m_point_Array.Append(m_point_Array4);
}

void CCDTest002View::GetMatrix(double matrix[][3], int iFlag, double rotateAngle, double x_dis, double y_dis, double dbl_zoom)
{
	// iFlag: 0-移动， 1-旋转， 2-x轴镜像， 3-y轴镜像， 4-x轴错移， 5-y轴错移， 6-比例放缩
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	// matrix = [[1 0 0]
	// 			 [0 1 0]
	// 			 [0 0 1]]


	if(iFlag == 0)//0-移动
	{
		matrix[2][0] = x_dis;
		matrix[2][1] = y_dis;
		// matrix = [[1     0     0]
		// 			 [0     1     0]
		// 			 [x_dis y_dis 1]]
	}
	else if(iFlag == 1)//1-旋转， 
	{
		matrix[0][0] = cos(PI/180 * rotateAngle);
		matrix[0][1] = sin(PI/180 * rotateAngle);
		matrix[1][0] = (-1) * sin(PI/180 * rotateAngle);
		matrix[1][1] = cos(PI/180 * rotateAngle);
		// matrix[0][0] = cos(PI/180 * rotateAngle);
		// matrix[0][1] = sin(PI/180 * rotateAngle);
		// matrix[1][0] = (-1) * sin(PI/180 * rotateAngle);
		// matrix[1][1] = cos(PI/180 * rotateAngle);
		// matrix = [[cos(0)  sin(0) 0]
		// 			 [-sin(0) cos(0) 0]
		// 			 [0       0      1]]
	}
	else if(iFlag == 2)//2-x轴镜像， 
	{
		matrix[1][1] = -1;
		// matrix = [[1 0  0]
		// 			 [0 -1 0]
		// 			 [0 0  1]]
	}
	else if(iFlag == 3)//3-y轴镜像
	{
		matrix[0][0] = -1;
		// matrix = [[-1 0 0]
		// 			 [0  1 0]
		// 			 [0  0 1]]
	}
	else if(iFlag == 4)//4-x轴错移
	{
		matrix[1][0] = x_dis;
		// matrix = [[1     0 0]
		// 			 [x_dis 1 0]
		// 			 [0     0 1]]
	}
	else if(iFlag == 5)//5-y轴错移
	{
		matrix[0][1] = y_dis;
		// matrix = [[1 y_dis 0]
		// 			 [0 1     0]
		// 			 [0 0     1]]
	}
	else if(iFlag == 6)//6-比例放缩
	{
		matrix[2][2] = dbl_zoom;//<1-放大，>1-缩小
		// matrix = [[1 0 0]
		// 			 [0 1 0]
		// 			 [0 0 dbl_zoom]]
	}
}

void CCDTest002View::GetNewPoint()
{
	CArray<CPoint, CPoint> m_point_Array_new;
	CPoint point_new;
	double s_dbl;
	for(int i=0; i<m_point_Array.GetSize(); i++)
	{
		point_new.x = m_point_Array.GetAt(i).x * m_Matrix[0][0] + m_point_Array.GetAt(i).y * m_Matrix[1][0] + m_Matrix[2][0];
		point_new.y = m_point_Array.GetAt(i).x * m_Matrix[0][1] + m_point_Array.GetAt(i).y * m_Matrix[1][1] + m_Matrix[2][1];
		s_dbl = m_Matrix[0][2] + m_Matrix[1][2] + m_Matrix[2][2];
		point_new.x /= s_dbl;
		point_new.y /= s_dbl;

		m_point_Array_new.Add(point_new);
	}
	m_point_Array.RemoveAll();
	m_point_Array.Append(m_point_Array_new);
}

void CCDTest002View::MatrixXMatrix(double matrix0[][3], double matrix1[][3])
{
	double matrix2[3][3];

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			matrix2[i][j] = matrix0[i][0]*matrix1[0][j] + matrix0[i][1]*matrix1[1][j] + matrix0[i][2]*matrix1[2][j];
		}
	}
	for(i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			matrix0[i][j] = matrix2[i][j];
		}
	}
}



void CCDTest002View::OnFillcolor() 
{
	// TODO: Add your command handler code here
	if(this->m_iFillFLag==0)
		this->m_iFillFLag=1;//0-not fill; 1-fill
	else if(this->m_iFillFLag==1)
		this->m_iFillFLag=0;
	Invalidate(TRUE);
}


void CCDTest002View::OnDrawpolyline() 
{
	// TODO: Add your command handler code here
	this->flag=1;
	Invalidate();
}

void CCDTest002View::OnPolygon() 
{
	// TODO: Add your command handler code here
	this->flag=3;
	Invalidate();
}

void CCDTest002View::OnMutiplyline() 
{
	// TODO: Add your command handler code here
	this->flag=2;
	Invalidate();
}

void CCDTest002View::OnBin() 
{
	// TODO: Add your command handler code here
	this->m_iDeleteFlag = 1;
	this->flag = 0;
	this->finished = 0;
	this->m_iFillFLag = 0;
	this->m_iClipFlag = 0;
	this->m_iGetTwoPoint = 0;
	this->m_iTypeFlag = 0;
	Invalidate();
}

void CCDTest002View::OnClippolyline() 
{
	// TODO: Add your command handler code here
	if(this->finished == 1)
	{
		this->m_iClipFlag = 1;
		this->m_iGetTwoPoint = 1;
	}
	else
		MessageBox("not closed!");
	Invalidate();
}

void CCDTest002View::OnOnMove() 
{
	// TODO: Add your command handler code here
	// 平移
	this->m_iTypeFlag = 1;
	this->m_iGetTwoPoint = 1;
	this->m_BottomRightPoint = this->m_TopLeftPoint;
	Invalidate(TRUE);
}

void CCDTest002View::OnMirror() 
{
	// TODO: Add your command handler code here
	this->m_iTypeFlag = 2;
	this->m_iGetTwoPoint = 1;
	this->m_BottomRightPoint = this->m_TopLeftPoint;
	Invalidate(TRUE);
}

void CCDTest002View::OnMg2() 
{
	// TODO: Add your command handler code here
	if(this->m_MDlg2->GetSafeHwnd()==NULL)
	{
		this->m_MDlg2->Create();
	}
	else
	{
		this->m_MDlg2->ShowWindow(TRUE);
	}
}

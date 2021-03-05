
#include "stdafx.h"
#include <iostream>
#include <iostream>


CRectD::CRectD(double l,double t,double r,double b)
{
  left = l; 
  top = t; 
  right = r; 
  bottom = b; 
}
//------------------------------------------------------------------------------
void CRectD::SetRectD(double l,double t,double r,double b)
{
  left = l; 
  top = t; 
  right = r; 
  bottom = b; 
}

//------------------------------------------------------------------------------
CSizeD CRectD::SizeD()
{
  CSizeD cz;
  cz.cx=fabs(right-left);	// Ширина прямоугольной области
  cz.cy=fabs(top-bottom);	// Высота прямоугольной области
  return cz;
}

//-------------------------------------------------------------------------------
CMatrix SpaceToWindow(CRectD& rs, CRect& rw)
{
	CMatrix M(3,3);
	CSize s = rw.Size(); //размер в оконных координатах
	int wx = s.cx; //в оконных
	int wy = s.cy;
	
	CSizeD sd = rs.SizeD(); //размер в мировых координатах
	double dx = sd.cx;
	double dy = sd.cy;

	double kx = (double)wx/dx;
	double ky = (double)wy/dy;

	M(0,0) = kx;
	M(0,1) = 0;
	M(0,2) = (double)rw.left-kx*rs.left;
	 
	M(1,0) = 0;
	M(1,1) = -ky;
	M(1,2) = (double)rw.bottom+ky*rs.bottom;
	
	M(2,0) = 0;
	M(2,1) = 0;
	M(2,2) = 1;
	return M;


}

//-------------------------------------------------------------------------------
void SetMyMode(CDC& dc,CRectD& rs, CRect& rw)
{
	double dsx = rs.right - rs.left;
	double dsy = rs.top - rs.bottom;
	double xsL = rs.left;
	double ysL = rs.bottom;
	
	int dwx = rw.right - rw.left;
	int dwy = rw.bottom - rw.top;
	int xwL = rw.left;
	int ywL = rw.bottom;

	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt(dsx,dsy);
	dc.SetViewportExt(dwx,-dwy);
	dc.SetWindowOrg(xsL,ysL);
	dc.SetViewportOrg(xwL,ywL);


}

//---------------------------------------------------------------------------------

void CPlot2D::SetParams(CMatrix& XX, CMatrix& YY, CRect& RWX)
{
	//XX - вектор данных по х
	//YY - вектор данных по y
	//RWX - область в окне

	int nRowsX = XX.rows();
	int nRowsY = YY.rows();

	if (nRowsX!=nRowsY)
	{
		char* error = "SetParams - неправильный размер массива данных";
		MessageBox(NULL,error,"Ошибка",MB_ICONSTOP);
		exit(0);
	}
	x.RedimMatrix(nRowsX);
	y.RedimMatrix(nRowsY);
	x = XX;
	y = YY;
	double x_max = x.MaxElement();
	double x_min = x.MinElement();
	double y_max = y.MaxElement();
	double y_min = y.MinElement();

	RS.SetRectD(x_min,y_max,x_max,y_min); //область в мировых
	RW.SetRect(RWX.left,RWX.top,RWX.right,RWX.bottom); //область в оконных
	
	k = SpaceToWindow(RS,RW); //матрица пересчёта координат
}

//------------------------------------------------------------------------------------

void CPlot2D::SetWindowRect(CRect& RWX)
{
	RW.SetRect(RWX.left,RWX.top,RWX.right,RWX.bottom); //область в оконных
	k = SpaceToWindow(RS,RW); 
}

//------------------------------------------------------------------------------------------
//установка параметров пера
//для линии
void CPlot2D::SetPenLine(CMyPen& PLine)
{
	PenLine.PenStyle = PLine.PenStyle;
	PenLine.PenWidth = PLine.PenWidth;
	PenLine.PenColor = PLine.PenColor;
}

//для осей
void CPlot2D::SetPenAxis(CMyPen& PAxis)
{
	PenAxis.PenStyle = PAxis.PenStyle;
	PenAxis.PenWidth = PAxis.PenWidth;
	PenAxis.PenColor = PAxis.PenColor;	
}

//-------------------------------------------------------------------------------------------------

void CPlot2D::GetRs(CRectD& RS)
{
	//RS - структура, куда записывается параметры области графика
	RS.left = (this->RS).left;
	RS.top = (this->RS).top;
	RS.right = (this->RS).right;
	RS.bottom = (this->RS).bottom;
}

//---------------------------------------------------------------------------------------------------------

void CPlot2D::GetWindowCoords(double xs, double ys, int &xw, int &yw)
{
	CMatrix V(3),W(3);
	V(2) = 1;
	V(0) = xs;
	V(1) = ys;
	W = k*V;
	xw = (int)W(0);
	yw = (int)W(1);
}

//--------------------------------------------------------------------------------------------------------
void CPlot2D::Draw(CDC& dc, int Ind1, int Ind2)
{
	CMatrix V(3), W(3);
	V(2) = 1;

	if(Ind1==1)
		dc.Rectangle(RW);

	V(0) = x(0);
	V(1) = y(0);
	W = k*V;
	CPen MyPen(PenLine.PenStyle, PenLine.PenWidth, PenLine.PenColor);
	CPen* pOldPen = dc.SelectObject(&MyPen);
	dc.MoveTo((int)W(0),(int)W(1)); //начальная точка для рисования графика
	for(int i = 1; i<x.rows();i++)
	{
		V(0) = x(i);
		V(1) = y(i);
		W = k*V;
		dc.LineTo((int)W(0),(int)W(1));
	}
	dc.SelectObject(pOldPen); 

}

//-------------------------------------------------------------------------------

void CPlot2D::Draw1(CDC& dc, int Ind1, int Ind2)
{
	CRect IRS (RS.left,RS.top,RS.right,RS.bottom);
	if (Ind1 == 1)
		dc.Rectangle(IRS);
	if(Ind2 == 1) //если нужны оси
	{
		CPen MyPen(PenAxis.PenStyle, PenAxis.PenWidth, PenAxis.PenColor);
		CPen* pOldPen = dc.SelectObject(&MyPen);

		if(RS.left*RS.right<0) //нужна ось у
		{
			dc.MoveTo(0,(int)RS.top);
			dc.LineTo(0,(int)RS.bottom);
		}
		if(RS.top*RS.bottom<0) //нужна ось x
		{
			dc.MoveTo((int)RS.left,0);
			dc.LineTo((int)RS.right,0);
			
		}
		dc.SelectObject(pOldPen);
		
	}

	CPen MyPen(PenLine.PenStyle,PenLine.PenWidth,PenLine.PenColor);	
	CPen* pOldPen= dc.SelectObject(&MyPen);	
	dc.MoveTo((int)x(0),(int)y(0));
	for(int i=1; i<x.rows(); i++)	
		dc.LineTo((int)x(i),(int)y(i));
		dc.SelectObject(pOldPen);

	
}
/////////------------

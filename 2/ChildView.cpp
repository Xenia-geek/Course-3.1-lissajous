
// ChildView.cpp : реализация класса CChildView

#include "stdafx.h"
#include "2.h"
#include "ChildView.h"
#include "MainFrm.h"
#include "DialogOptions.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_IsMousePressed = 0;
	m_IsImageToPaste = 0;
	m_IsGraphSelect1 = 0;
	m_IsGraphSelect2 = 0;
	m_IsGraphSelect3 = 0;
	m_IsGraphSelect4 = 0;
	m_IsGraphSelect5 = 0;
	m_IsGraphSelect6 = 0;
	m_IsGraphSelect7 = 0;
	m_SelectedRect = new CRect();
	pen.CreatePen(PS_GEOMETRIC,1,RGB(0,255,255));
	bpen.CreatePen(0,1,RGB(255,255,255));
	bbrush.CreateSolidBrush(RGB(255,255,255));
	PenLine.Set(PS_SOLID,1,RGB(255,0,255));

	m_File_Load = 0;
	m_height = 0;
	m_width = 0;
	m_File_Save = 0;
	i1=0;
	i2 = 0;
	i3 = 0;
	i4 = 0;
	i5 = 0;
	i6 = 0;
	i = 0;
	beginX = 0;
	beginY = 0;
	endX = 0;
	endY = 0;
	flag=0;
	//параметры лисажу
	pi=3.1415926535898;
	A=1;
	B=1;
	a=3;
	b=3;
	IfFirst=false;
	IfAnim=false;
	pause = false;
	kcouts=0;
	grad=45;
	iterflag=0;
	df=0.0;
	da=0.0;
	//1
	A1 = 1;
	B1 = 1;
	a1 = 3;
	b1 = 3;
	IfFirst1 = true;
	IfAnim1 = false;
	pause1 = false;
	kcouts1 = 0;
	grad1 = 0;
	df1 = 0.0;
	da1 = 0.0;
	iterflag1 = 0;
	//2
	A2 = 1;
	B2 = 1;
	a2 = 3;
	b2 = 3;
	IfFirst2 = true;
	IfAnim2 = false;
	pause2 = false;
	kcouts2 = 0;
	grad2 = 90;
	df2 = 0.0;
	da2 = 0.0;
	iterflag2 = 0;
	//3
	A3 = 1;
	B3 = 1;
	a3 = 3;
	b3 = 3;
	IfFirst3 = true;
	IfAnim3 = false;
	pause3 = false;
	kcouts3 = 0;
	grad3 = 45;
	df3 = 0.0;
	da3 = 0.0;
	iterflag3 = 0;
	//4
	A4 = 1;
	B4 = 1;
	a4 = 6;
	b4 = 3;
	IfFirst4 = true;
	IfAnim4 = false;
	pause4 = false;
	kcouts4 = 0;
	grad4 = 0;
	df4 = 0.0;
	da4 = 0.0;
	iterflag4 = 0;
	//5
	A5 = 1;
	B5 = 1;
	a5 = 3;
	b5 = 2;
	IfFirst5 = true;
	IfAnim5 = false;
	pause5 = false;
	kcouts5 = 0;
	grad5 = 90;
	df5 = 0.0;
	da5 = 0.0;
	iterflag5 = 0;
	//6
	A6 = 1;
	B6 = 1;
	a6 = 3;
	b6 = 4;
	IfFirst6 = true;
	IfAnim6 = false;
	pause6 = false;
	kcouts6 = 0;
	grad6 = 90;
	df6 = 0.0;
	da6 = 0.0;
	iterflag6 = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
//	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_32771,OnOpen)
	ON_COMMAND(ID_OPEN_SIX_IMG,OpenSix)
	ON_COMMAND(ID_OPTIONS_SET_FIRST,Prop1)
	ON_COMMAND(ID_OPTIONS_SET_SECOND, Prop2)
	ON_COMMAND(ID_OPTIONS_SET_THERD, Prop3)
	ON_COMMAND(ID_OPTIONS_SET_FOURTH, Prop4)
	ON_COMMAND(ID_OPTIONS_SET_FIFTH, Prop5)
	ON_COMMAND(ID_OPTIONS_SET_SIXTH, Prop6)
	ON_COMMAND(ID_32772,OnSave)
	ON_COMMAND(ID_OPTIONS_SET,Prop)
END_MESSAGE_MAP()



// обработчики сообщений CChildView


BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs)) {
		
		return FALSE;
	}
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);
	return TRUE;
	
}

void CChildView::OnRButtonDown( UINT, CPoint cp)
{
	IfAnim=false;
		KillTimer(1);
}

void CChildView::OnRButtonDown1(UINT, CPoint cp)
{
	IfAnim1 = false;
	KillTimer(2);
}

void CChildView::OnRButtonDown2(UINT, CPoint cp)
{
	IfAnim2 = false;
	KillTimer(3);
}

void CChildView::OnRButtonDown3(UINT, CPoint cp)
{
	IfAnim3 = false;
	KillTimer(4);
}

void CChildView::OnRButtonDown4(UINT, CPoint cp)
{
	IfAnim4 = false;
	KillTimer(5);
}

void CChildView::OnRButtonDown5(UINT, CPoint cp)
{
	IfAnim5 = false;
	KillTimer(6);
}

void CChildView::OnRButtonDown6(UINT, CPoint cp)
{
	IfAnim6 = false;
	KillTimer(7);
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

void CChildView::OnTimer( UINT uTime)
{
	iterflag++;
	iterflag1++;
	iterflag2++;
	iterflag3++;
	iterflag4++;
	iterflag5++;
	iterflag6++;

	if (!IfFirst)
	{
		
		if (iterflag < kcouts)
		{
			grad += df;
			a += da;
			Graph1();
			Invalidate();
		}
		if (iterflag >= kcouts)
		{
			IfAnim = false;
			KillTimer(1);
			iterflag = 0;
			Invalidate();
		}
	}
	if (!IfFirst1)
	{
		
		if (iterflag1 < kcouts1)
		{
			grad1 += df1;
			a1 += da1;
			Graph2();
			Invalidate();
		}
		if (iterflag1 >= kcouts1)
		{
			IfAnim1 = false;
			KillTimer(2);
			iterflag1 = 0;
			Invalidate();
		}
	}
	if (!IfFirst2)
	{

		if (iterflag2 < kcouts2)
		{
			grad2 += df2;
			a2 += da2;
			Graph3();
			Invalidate();
		}
		if (iterflag2 >= kcouts2)
		{
			IfAnim2 = false;
			KillTimer(3);
			iterflag2 = 0;
			Invalidate();
		}
	}
	if (!IfFirst3)
	{

		if (iterflag3 < kcouts3)
		{
			grad3 += df3;
			a3 += da3;
			Graph4();
			Invalidate();
		}
		if (iterflag3 >= kcouts3)
		{
			IfAnim3 = false;
			KillTimer(4);
			iterflag3 = 0;
			Invalidate();
		}
	}
	if (!IfFirst4)
	{

		if (iterflag4 < kcouts4)
		{
			grad4 += df4;
			a4 += da4;
			Graph5();
			Invalidate();
		}
		if (iterflag4 >= kcouts4)
		{
			IfAnim4 = false;
			KillTimer(5);
			iterflag4 = 0;
			Invalidate();
		}
	}
	if (!IfFirst5)
	{

		if (iterflag5 < kcouts5)
		{
			grad5 += df5;
			a5 += da5;
			Graph6();
			Invalidate();
		}
		if (iterflag5 >= kcouts5)
		{
			IfAnim5 = false;
			KillTimer(6);
			iterflag5 = 0;
			Invalidate();
		}
	}
	if (!IfFirst6)
	{

		if (iterflag6 < kcouts6)
		{
			grad6 += df6;
			a6 += da6;
			Graph7();
			Invalidate();
		}
		if (iterflag6 >= kcouts6)
		{
			IfAnim6 = false;
			KillTimer(7);
			iterflag6 = 0;
			Invalidate();
		}
	}
}



void CChildView::OnPaint() 
{
    CPaintDC            dc(this);

	if(m_File_Load)
	{
		showBitMap(dc.GetWindow()->m_hWnd,opened_file,0,0);
	}

	if(IfFirst)
	{		
		Graph1();
		
	}
	if (IfFirst1)
	{
		Graph2();
	}
	if (IfFirst2)
	{
		Graph3();
	}
	if (IfFirst3)
	{
		Graph4();
	}
	if (IfFirst4)
	{
		Graph5();
	}
	if (IfFirst5)
	{
		Graph6();
	}
	if (IfFirst6)
	{
		Graph7();
	}
	if(m_IsGraphSelect1)
	{
		CPlot1.Draw(dc,1,1);
	}
	if (m_IsGraphSelect2)
	{
		CPlot1.Draw(dc, 1, 1);
	}
	if (m_IsGraphSelect3)
	{
		CPlot2.Draw(dc, 1, 1);
	}
	if (m_IsGraphSelect4)
	{
		CPlot3.Draw(dc, 1, 1);
	}
	if (m_IsGraphSelect5)
	{
		CPlot4.Draw(dc, 1, 1);
	}
	if (m_IsGraphSelect6)
	{
		CPlot5.Draw(dc, 1, 1);
	}
	if (m_IsGraphSelect7)
	{
		CPlot6.Draw(dc, 1, 1);
	}
}

void CChildView::OnOpen() 
{

	CFileDialog fd(TRUE,NULL,"");
	fd.m_ofn.lpstrFilter = "BMP\0 *.bmp\0\0";

	if(fd.DoModal()==IDOK)
	{

		CWnd *cwnd = AfxGetMainWnd();
		HWND hwnd = cwnd->GetSafeHwnd();
		HBITMAP hBit = (HBITMAP)LoadImage(NULL, fd.GetPathName().GetBuffer(), IMAGE_BITMAP,	0, 0, LR_LOADFROMFILE |  LR_CREATEDIBSECTION);
		opened_file=hBit;
		showBitMap(hwnd,hBit,0,0);
		BITMAP BitMap;
		GetObject(hBit, sizeof(BITMAP), &BitMap);
		m_File_Load = 1;
		m_height = BitMap.bmHeight;
		m_width = BitMap.bmWidth;
		if(i>0)
		{
			OnPaint();
		}
		i++;

	}
	Invalidate();

}

void CChildView::OnSave() 
{
	CFileDialog fileDialog(FALSE, _T("fif"), 0, 6UL,NULL , this);
		fileDialog.m_ofn.lpstrFilter = "BMP\0 *.bmp\0\0";
		int result = fileDialog.DoModal();
		if (result==IDOK)
		{
			CWnd *cwnd = AfxGetMainWnd();
			HWND hwnd = cwnd->GetSafeHwnd();
			RECT r;
			r.bottom= RW.bottom;
			r.left=RW.left;
			r.right=RW.right;
			r.top=RW.top;
			ClientToBmp(hwnd,fileDialog.GetPathName(),r );
		}
}

void CChildView::Graph1()
{
	IfFirst=false;
	m_IsGraphSelect1 = true;
	m_IsGraphSelect2 = false;
	m_IsGraphSelect3 = false;
	m_IsGraphSelect4 = false;
	m_IsGraphSelect5 = false;
	m_IsGraphSelect6 = false;
	m_IsGraphSelect7 = false;
	int N=0.0;
	if(a==0.0 || b==0.0)
	{
		N=360*100;
	}
	else	
	{
		N=ceil(360/a)*100;		
	}
	if(N>100000)
		N=100000;
	XX.RedimMatrix(N+1);
	YY.RedimMatrix(N+1);
	double f=0.0;
	double trololo,trol;
	for(int i =0; i <=N; i++,f+=0.01)
	{
		trololo=A*sin(a*f + qradtorad(grad));
		trol=B*sin(b*f);
		XX(i)=trololo;
		YY(i)=trol;
	}
	PenAxis.Set(PS_SOLID,1,RGB(0,0,0));
	
	RW.SetRect(90,45,530,500);
	CPlot1.SetParams(XX,YY,RW);
	CPlot1.SetPenLine(PenLine);
	CPlot1.SetPenAxis(PenAxis);
}


void CChildView::Animate()
{
		Graph1();
		Invalidate();		
}

void CChildView::Graph2()
{
	IfFirst1 = false;
	m_IsGraphSelect1 = false;
	m_IsGraphSelect2 = true;
	m_IsGraphSelect3 = true;
	m_IsGraphSelect4 = true;
	m_IsGraphSelect5 = true;
	m_IsGraphSelect6 = true;
	m_IsGraphSelect7 = true;
	int N = 0.0;
	if (a1 == 0.0 || b1 == 0.0)
	{
		N = 360 * 100;
	}
	else
	{
		N = ceil(360 / a1) * 100;
	}

	if (N > 100000)
		N = 100000;
	XX.RedimMatrix(N + 1);
	YY.RedimMatrix(N + 1);
	double f = 0.0;
	double trololo, trol;
	for (int i1 = 0; i1 <= N; i1++, f += 0.01)
	{
		trololo = A1 * sin(a1 * f + qradtorad1(grad1));
		trol = B1 * sin(b1 * f);
		XX(i1) = trololo;
		YY(i1) = trol;
	}
	PenAxis.Set(PS_SOLID, 1, RGB(0, 0, 0));
	RW.SetRect(40, 45, 220, 225);
	CPlot1.SetParams(XX, YY, RW);
	CPlot1.SetPenLine(PenLine);
	CPlot1.SetPenAxis(PenAxis);
}


void CChildView::Animate1()
{
	Graph2();
	Invalidate();
}


void CChildView::Graph3()
{
	IfFirst2 = false;
	m_IsGraphSelect1 = false;
	m_IsGraphSelect2 = true;
	m_IsGraphSelect3 = true;
	m_IsGraphSelect4 = true;
	m_IsGraphSelect5 = true;
	m_IsGraphSelect6 = true;
	m_IsGraphSelect7 = true;
	int N = 0.0;
	if (a2 == 0.0 || b2 == 0.0)
	{
		N = 360 * 100;
	}
	else
	{
		N = ceil(360 / a2) * 100;
	}
	if (N > 100000)
		N = 100000;
	XX.RedimMatrix(N + 1);
	YY.RedimMatrix(N + 1);
	double f = 0.0;
	double trololo, trol;
	for (int i2 = 0; i2 <= N; i2++, f += 0.01)
	{
		trololo = A2 * sin(a2 * f + qradtorad2(grad2));
		trol = B2 * sin(b2 * f);
		XX(i2) = trololo;
		YY(i2) = trol;
	}
	PenAxis.Set(PS_SOLID, 1, RGB(0, 0, 0));
	RW.SetRect(340, 45, 520, 225);
	CPlot2.SetParams(XX, YY, RW);
	CPlot2.SetPenLine(PenLine);
	CPlot2.SetPenAxis(PenAxis);
}


void CChildView::Animate2()
{
	Graph3();
	Invalidate();
}

void CChildView::Graph4()
{
	IfFirst3 = false;
	m_IsGraphSelect1 = false;
	m_IsGraphSelect2 = true;
	m_IsGraphSelect3 = true;
	m_IsGraphSelect4 = true;
	m_IsGraphSelect5 = true;
	m_IsGraphSelect6 = true;
	m_IsGraphSelect7 = true;
	int N = 0.0;
	if (a3 == 0.0 || b3 == 0.0)
	{
		N = 360 * 100;
	}
	else
	{
		N = ceil(360 / a3) * 100;
	}
	if (N > 100000)
		N = 100000;
	XX.RedimMatrix(N + 1);
	YY.RedimMatrix(N + 1);
	double f = 0.0;
	double trololo, trol;
	for (int i3 = 0; i3 <= N; i3++, f += 0.01)
	{
		trololo = A3 * sin(a3 * f + qradtorad3(grad3));
		trol = B3 * sin(b3 * f);
		XX(i3) = trololo;
		YY(i3) = trol;
	}
	PenAxis.Set(PS_SOLID, 1, RGB(0, 0, 0));
	RW.SetRect(640, 45, 820, 225);
	CPlot3.SetParams(XX, YY, RW);
	CPlot3.SetPenLine(PenLine);
	CPlot3.SetPenAxis(PenAxis);
}


void CChildView::Animate3()
{
	Graph4();
	Invalidate();
}

void CChildView::Graph5()
{
	IfFirst4 = false;
	m_IsGraphSelect1 = false;
	m_IsGraphSelect2 = true;
	m_IsGraphSelect3 = true;
	m_IsGraphSelect4 = true;
	m_IsGraphSelect5 = true;
	m_IsGraphSelect6 = true;
	m_IsGraphSelect7 = true;
	int N = 0.0;
	if (a4 == 0.0 || b4 == 0.0)
	{
		N = 360 * 100;
	}
	else
	{
		N = ceil(360 / a4) * 100;
	}
	if (N > 100000)
		N = 100000;
	XX.RedimMatrix(N + 1);
	YY.RedimMatrix(N + 1);
	double f = 0.0;
	double trololo, trol;
	for (int i4 = 0; i4 <= N; i4++, f += 0.01)
	{
		trololo = A4 * sin(a4 * f + qradtorad4(grad4));
		trol = B4 * sin(b4 * f);
		XX(i4) = trololo;
		YY(i4) = trol;
	}
	PenAxis.Set(PS_SOLID, 1, RGB(0, 0, 0));
	RW.SetRect(40, 270, 220, 450);
	CPlot4.SetParams(XX, YY, RW);
	CPlot4.SetPenLine(PenLine);
	CPlot4.SetPenAxis(PenAxis);
}


void CChildView::Animate4()
{
	Graph5();
	Invalidate();
}

void CChildView::Graph6()
{
	IfFirst5 = false;
	m_IsGraphSelect1 = false;
	m_IsGraphSelect2 = true;
	m_IsGraphSelect3 = true;
	m_IsGraphSelect4 = true;
	m_IsGraphSelect5 = true;
	m_IsGraphSelect6 = true;
	m_IsGraphSelect7 = true;
	int N = 0.0;
	if (a5 == 0.0 || b5 == 0.0)
	{
		N = 360 * 100;
	}
	else
	{
		N = ceil(360 / a5) * 100;
	}
	if (N > 100000)
		N = 100000;
	XX.RedimMatrix(N + 1);
	YY.RedimMatrix(N + 1);
	double f = 0.0;
	double trololo, trol;
	for (int i5 = 0; i5 <= N; i5++, f += 0.01)
	{
		trololo = A5 * sin(a5 * f + qradtorad5(grad5));
		trol = B5 * sin(b5 * f);
		XX(i5) = trololo;
		YY(i5) = trol;
	}
	PenAxis.Set(PS_SOLID, 1, RGB(0, 0, 0));
	RW.SetRect(340, 270, 520, 450);
	CPlot5.SetParams(XX, YY, RW);
	CPlot5.SetPenLine(PenLine);
	CPlot5.SetPenAxis(PenAxis);
}


void CChildView::Animate5()
{
	Graph6();
	Invalidate();
}

void CChildView::Graph7()
{
	IfFirst6 = false;
	m_IsGraphSelect1 = false;
	m_IsGraphSelect2 = true;
	m_IsGraphSelect3 = true;
	m_IsGraphSelect4 = true;
	m_IsGraphSelect5 = true;
	m_IsGraphSelect6 = true;
	m_IsGraphSelect7 = true;
	int N = 0.0;
	if (a6 == 0.0 || b6 == 0.0)
	{
		N = 360 * 100;
	}
	else
	{
		N = ceil(360 / a6) * 100;
	}
	if (N > 100000)
		N = 100000;
	XX.RedimMatrix(N + 1);
	YY.RedimMatrix(N + 1);
	double f = 0.0;
	double trololo, trol;
	for (int i6 = 0; i6 <= N; i6++, f += 0.01)
	{
		trololo = A6 * sin(a6 * f + qradtorad6(grad6));
		trol = B6 * sin(b6 * f);
		XX(i6) = trololo;
		YY(i6) = trol;
	}
	PenAxis.Set(PS_SOLID, 1, RGB(0, 0, 0));
	RW.SetRect(640, 270, 820, 450);
	CPlot6.SetParams(XX, YY, RW);
	CPlot6.SetPenLine(PenLine);
	CPlot6.SetPenAxis(PenAxis);
}


void CChildView::Animate6()
{
	Graph7();
	Invalidate();
}

void CChildView::Prop()
{
	
	CDialogOptions  DialOpt;
	DialOpt.COLORLine=PenLine.PenColor;
	DialOpt.InputA=A;
	DialOpt.InputB=B;
	DialOpt.Inputa=a;
	DialOpt.Inputb=b;
	DialOpt.kcouts=kcouts;
	DialOpt.InputQ=grad;
	DialOpt.df=df;
	DialOpt.da=da;
	if(DialOpt.DoModal()==IDOK)
	{		
		PenLine.PenColor=DialOpt.COLORLine;
		A=DialOpt.InputA;
		B=DialOpt.InputB;
		a=DialOpt.Inputa;
		b=DialOpt.Inputb;
		grad=DialOpt.InputQ;
		IfAnim=DialOpt.IfAnim;
		kcouts=DialOpt.kcouts;	
		df=DialOpt.df;
		da=DialOpt.da;
		if(IfAnim)
		{
			SetTimer(1,100,NULL);
		}
		Animate();
	}
}

void CChildView::Prop1()
{

	CDialogOptions  DialOpt1;
	DialOpt1.COLORLine = PenLine.PenColor;
	DialOpt1.InputA = A1;
	DialOpt1.InputB = B1;
	DialOpt1.Inputa = a1;
	DialOpt1.Inputb = b1;
	DialOpt1.kcouts = kcouts1;
	DialOpt1.InputQ = grad1;
	DialOpt1.df = df1;
	DialOpt1.da = da1;
	if (DialOpt1.DoModal() == IDOK)
	{
		PenLine.PenColor = DialOpt1.COLORLine;
		A1 = DialOpt1.InputA;
		B1 = DialOpt1.InputB;
		a1 = DialOpt1.Inputa;
		b1 = DialOpt1.Inputb;
		grad1 = DialOpt1.InputQ;
		IfAnim1 = DialOpt1.IfAnim;
		kcouts1 = DialOpt1.kcouts;
		df1 = DialOpt1.df;
		da1 = DialOpt1.da;
		if (IfAnim1)
		{
			SetTimer(2, 0, NULL);
		}
		Animate1();
	}
}

void CChildView::Prop2()
{

	CDialogOptions  DialOpt2;
	DialOpt2.COLORLine = PenLine.PenColor;
	DialOpt2.InputA = A2;
	DialOpt2.InputB = B2;
	DialOpt2.Inputa = a2;
	DialOpt2.Inputb = b2;
	DialOpt2.kcouts = kcouts2;
	DialOpt2.InputQ = grad2;
	DialOpt2.df = df2;
	DialOpt2.da = da2;
	if (DialOpt2.DoModal() == IDOK)
	{
		PenLine.PenColor = DialOpt2.COLORLine;
		A2 = DialOpt2.InputA;
		B2 = DialOpt2.InputB;
		a2 = DialOpt2.Inputa;
		b2 = DialOpt2.Inputb;
		grad2 = DialOpt2.InputQ;
		IfAnim2 = DialOpt2.IfAnim;
		kcouts2 = DialOpt2.kcouts;
		df2 = DialOpt2.df;
		da2 = DialOpt2.da;
		if (IfAnim2)
		{
			SetTimer(3, 0, NULL);
		}
		Animate2();
	}
}

void CChildView::Prop3()
{

	CDialogOptions  DialOpt3;
	DialOpt3.COLORLine = PenLine.PenColor;
	DialOpt3.InputA = A3;
	DialOpt3.InputB = B3;
	DialOpt3.Inputa = a3;
	DialOpt3.Inputb = b3;
	DialOpt3.kcouts = kcouts3;
	DialOpt3.InputQ = grad3;
	DialOpt3.df = df3;
	DialOpt3.da = da3;
	if (DialOpt3.DoModal() == IDOK)
	{
		PenLine.PenColor = DialOpt3.COLORLine;
		A3 = DialOpt3.InputA;
		B3 = DialOpt3.InputB;
		a3 = DialOpt3.Inputa;
		b3 = DialOpt3.Inputb;
		grad3 = DialOpt3.InputQ;
		IfAnim3 = DialOpt3.IfAnim;
		kcouts3 = DialOpt3.kcouts;
		df3 = DialOpt3.df;
		da3 = DialOpt3.da;
		if (IfAnim3)
		{
			SetTimer(4, 0, NULL);
		}
		Animate3();
	}
}

void CChildView::Prop4()
{

	CDialogOptions  DialOpt4;
	DialOpt4.COLORLine = PenLine.PenColor;
	DialOpt4.InputA = A4;
	DialOpt4.InputB = B4;
	DialOpt4.Inputa = a4;
	DialOpt4.Inputb = b4;
	DialOpt4.kcouts = kcouts4;
	DialOpt4.InputQ = grad4;
	DialOpt4.df = df4;
	DialOpt4.da = da4;
	if (DialOpt4.DoModal() == IDOK)
	{
		PenLine.PenColor = DialOpt4.COLORLine;
		A4 = DialOpt4.InputA;
		B4 = DialOpt4.InputB;
		a4 = DialOpt4.Inputa;
		b4 = DialOpt4.Inputb;
		grad4 = DialOpt4.InputQ;
		IfAnim4 = DialOpt4.IfAnim;
		kcouts4 = DialOpt4.kcouts;
		df4 = DialOpt4.df;
		da4 = DialOpt4.da;
		if (IfAnim4)
		{
			SetTimer(5, 0, NULL);
		}
		Animate4();
	}
}

void CChildView::Prop5()
{

	CDialogOptions  DialOpt5;
	DialOpt5.COLORLine = PenLine.PenColor;
	DialOpt5.InputA = A5;
	DialOpt5.InputB = B5;
	DialOpt5.Inputa = a5;
	DialOpt5.Inputb = b5;
	DialOpt5.kcouts = kcouts5;
	DialOpt5.InputQ = grad5;
	DialOpt5.df = df5;
	DialOpt5.da = da5;
	if (DialOpt5.DoModal() == IDOK)
	{
		PenLine.PenColor = DialOpt5.COLORLine;
		A5 = DialOpt5.InputA;
		B5 = DialOpt5.InputB;
		a5 = DialOpt5.Inputa;
		b5 = DialOpt5.Inputb;
		grad5 = DialOpt5.InputQ;
		IfAnim5 = DialOpt5.IfAnim;
		kcouts5 = DialOpt5.kcouts;
		df5 = DialOpt5.df;
		da5 = DialOpt5.da;
		if (IfAnim5)
		{
			SetTimer(6, 0, NULL);
		}
		Animate5();
	}
}

void CChildView::Prop6()
{

	CDialogOptions  DialOpt6;
	DialOpt6.COLORLine = PenLine.PenColor;
	DialOpt6.InputA = A6;
	DialOpt6.InputB = B6;
	DialOpt6.Inputa = a6;
	DialOpt6.Inputb = b6;
	DialOpt6.kcouts = kcouts6;
	DialOpt6.InputQ = grad6;
	DialOpt6.df = df6;
	DialOpt6.da = da6;
	if (DialOpt6.DoModal() == IDOK)
	{
		PenLine.PenColor = DialOpt6.COLORLine;
		A6 = DialOpt6.InputA;
		B6 = DialOpt6.InputB;
		a6 = DialOpt6.Inputa;
		b6 = DialOpt6.Inputb;
		grad6 = DialOpt6.InputQ;
		IfAnim6 = DialOpt6.IfAnim;
		kcouts6 = DialOpt6.kcouts;
		df6 = DialOpt6.df;
		da6 = DialOpt6.da;
		if (IfAnim6)
		{
			SetTimer(7, 0, NULL);
		}
		Animate6();
	}
}

void CChildView::OpenSix()
{

}

double CChildView::qradtorad(int grad)
{
	 double intpart,rad;
	 rad=0.0;
     rad=modf(grad/360,&intpart);
     if (abs(intpart)>0)
            {
            if (grad>0) grad=grad-360*intpart;
            else grad=grad+360*intpart;
            }
     if (grad<0) grad=(grad+360);
     if ((grad>=0) && (grad<180)) rad=grad*pi/180;
     if ((grad>=180) && (grad<360)) rad=(grad-180)*pi/180;
	 return rad;
}




double CChildView::qradtorad1(int grad1)
{
	double intpart, rad;
	rad = 0.0;
	rad = modf(grad1 / 360, &intpart);
	if (abs(intpart) > 0)
	{
		if (grad1 > 0) grad1 = grad1 - 360 * intpart;
		else grad1 = grad1 + 360 * intpart;
	}
	if (grad1 < 0) grad1 = (grad1 + 360);
	if ((grad1 >= 0) && (grad1 < 180)) rad = grad1 * pi / 180;
	if ((grad1 >= 180) && (grad1 < 360)) rad = (grad1 - 180) * pi / 180;
	return rad;
}

double CChildView::qradtorad2(int grad2)
{
	double intpart, rad;
	rad = 0.0;
	rad = modf(grad2 / 360, &intpart);
	if (abs(intpart) > 0)
	{
		if (grad2 > 0) grad2 = grad2 - 360 * intpart;
		else grad2 = grad2 + 360 * intpart;
	}
	if (grad2 < 0) grad2 = (grad2 + 360);
	if ((grad2 >= 0) && (grad2 < 180)) rad = grad2 * pi / 180;
	if ((grad2 >= 180) && (grad2 < 360)) rad = (grad2 - 180) * pi / 180;
	return rad;
}

double CChildView::qradtorad3(int grad3)
{
	double intpart, rad;
	rad = 0.0;
	rad = modf(grad3 / 360, &intpart);
	if (abs(intpart) > 0)
	{
		if (grad3 > 0) grad3 = grad3 - 360 * intpart;
		else grad3 = grad3 + 360 * intpart;
	}
	if (grad3 < 0) grad3 = (grad3 + 360);
	if ((grad3 >= 0) && (grad3 < 180)) rad = grad3 * pi / 180;
	if ((grad3 >= 180) && (grad3 < 360)) rad = (grad3 - 180) * pi / 180;
	return rad;
}

double CChildView::qradtorad4(int grad4)
{
	double intpart, rad;
	rad = 0.0;
	rad = modf(grad4 / 360, &intpart);
	if (abs(intpart) > 0)
	{
		if (grad4 > 0) grad4 = grad4 - 360 * intpart;
		else grad4 = grad4 + 360 * intpart;
	}
	if (grad4 < 0) grad4 = (grad4 + 360);
	if ((grad4 >= 0) && (grad4 < 180)) rad = grad4 * pi / 180;
	if ((grad4 >= 180) && (grad4 < 360)) rad = (grad4 - 180) * pi / 180;
	return rad;
}

double CChildView::qradtorad5(int grad5)
{
	double intpart, rad;
	rad = 0.0;
	rad = modf(grad5 / 360, &intpart);
	if (abs(intpart) > 0)
	{
		if (grad5 > 0) grad5 = grad5 - 360 * intpart;
		else grad5 = grad5 + 360 * intpart;
	}
	if (grad5 < 0) grad5 = (grad5 + 360);
	if ((grad5 >= 0) && (grad5 < 180)) rad = grad5 * pi / 180;
	if ((grad5 >= 180) && (grad5 < 360)) rad = (grad5 - 180) * pi / 180;
	return rad;
}

double CChildView::qradtorad6(int grad6)
{
	double intpart, rad;
	rad = 0.0;
	rad = modf(grad6 / 360, &intpart);
	if (abs(intpart) > 0)
	{
		if (grad6 > 0) grad6 = grad6 - 360 * intpart;
		else grad6 = grad6 + 360 * intpart;
	}
	if (grad6 < 0) grad6 = (grad6 + 360);
	if ((grad6 >= 0) && (grad6 < 180)) rad = grad6 * pi / 180;
	if ((grad6 >= 180) && (grad6 < 360)) rad = (grad6 - 180) * pi / 180;
	return rad;
}




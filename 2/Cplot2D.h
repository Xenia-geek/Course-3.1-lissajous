
#ifndef LIBGRAPH
#define LIBGRAPH 1
const double pi=3.14159;

struct CSizeD
{
  double cx;
  double cy;
};

struct CRectD 
 { 
  double left; 
  double top; 
  double right; 
  double bottom; 
  CRectD()
  {
	  left=top=right=bottom=0;
  };
  CRectD(double l,double t,double r,double b);
  void SetRectD(double l,double t,double r,double b);
  CSizeD SizeD();	// Возвращает размеры(ширина, высота) прямоугольника 
 };

struct CMyPen //перо
{
	int PenStyle; //стиль
	int PenWidth; //толщина
	COLORREF PenColor; //цвет

	CMyPen()
	{
		PenStyle = PS_SOLID;
		PenWidth = 1;
		PenColor = RGB(0,0,0);
	}
	void Set(int PS, int PW, COLORREF PC)
	{
		PenStyle = PC;
		PenWidth = PW;
		PenColor = PC;
	}
};
//--------------------------

CMatrix SpaceToWindow(CRectD& rs, CRect& rw); //матрица пересчёта
void SetMyMode(CDC& dc,CRectD& rs, CRect& rw); //// Устанавливает режим отображения MM_ANISOTROPIC и его параметры

//--------------------------
class CPlot2D
{
public:
	CMatrix x; //аргумент
	CMatrix y; //функция
	CMatrix k; //матрица пересчёта координат
	CRect RW; //прямоуголник в оконных
	CRectD RS; // прямоугольная область в мировых
	CMyPen PenLine; //перо для линии
	CMyPen PenAxis; //перо для осей

public:
	CPlot2D()
	{
		k.RedimMatrix(3,3); 
	}
	void SetParams(CMatrix& XX, CMatrix& YY, CRect& RWX);
	void SetWindowRect(CRect& RWX);
	void GetWindowCoords(double xs, double ys, int &xw, int &yw);
	void SetPenLine(CMyPen& PLine); //перо для рисования графика
	void SetPenAxis(CMyPen& PAxis); //перо для рисования осей
	void Draw (CDC& dc, int Ind1, int Ind2); //рисование с самостоятельным пересчётом координат
	void Draw1(CDC& dc, int Ind1, int Ind2); //рисование без самостоятельного пересчёта
	void GetRs(CRectD& RS); //возвращает область графика в мировых координатах
};

#endif
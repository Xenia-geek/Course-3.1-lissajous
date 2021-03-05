
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
  CSizeD SizeD();	// ���������� �������(������, ������) �������������� 
 };

struct CMyPen //����
{
	int PenStyle; //�����
	int PenWidth; //�������
	COLORREF PenColor; //����

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

CMatrix SpaceToWindow(CRectD& rs, CRect& rw); //������� ���������
void SetMyMode(CDC& dc,CRectD& rs, CRect& rw); //// ������������� ����� ����������� MM_ANISOTROPIC � ��� ���������

//--------------------------
class CPlot2D
{
public:
	CMatrix x; //��������
	CMatrix y; //�������
	CMatrix k; //������� ��������� ���������
	CRect RW; //������������ � �������
	CRectD RS; // ������������� ������� � �������
	CMyPen PenLine; //���� ��� �����
	CMyPen PenAxis; //���� ��� ����

public:
	CPlot2D()
	{
		k.RedimMatrix(3,3); 
	}
	void SetParams(CMatrix& XX, CMatrix& YY, CRect& RWX);
	void SetWindowRect(CRect& RWX);
	void GetWindowCoords(double xs, double ys, int &xw, int &yw);
	void SetPenLine(CMyPen& PLine); //���� ��� ��������� �������
	void SetPenAxis(CMyPen& PAxis); //���� ��� ��������� ����
	void Draw (CDC& dc, int Ind1, int Ind2); //��������� � ��������������� ���������� ���������
	void Draw1(CDC& dc, int Ind1, int Ind2); //��������� ��� ���������������� ���������
	void GetRs(CRectD& RS); //���������� ������� ������� � ������� �����������
};

#endif
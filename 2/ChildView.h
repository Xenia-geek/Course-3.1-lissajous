
// ChildView.h : интерфейс класса CChildView
//


#pragma once


// окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
public:
// Операции
public:
	bool m_IsMousePressed;
	CRect *m_SelectedRect;
	bool m_IsImageToPaste;

	bool m_IsGraphSelect1;
	bool m_IsGraphSelect2;
	bool m_IsGraphSelect3;
	bool m_IsGraphSelect4;
	bool m_IsGraphSelect5;
	bool m_IsGraphSelect6;
	bool m_IsGraphSelect7;

	CPen pen,bpen;
	CBrush brush,bbrush;

	int m_height;
	int m_width;

	HANDLE opened_file;
	bool m_File_Load;
	bool m_File_Save;
	char* m_saved_file;
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int beginX;
	int beginY;
	int endX;
	int endY;

	bool flag;
	CPoint p1, p2, pl;
	//-------------------------------
	int NN;
	int iterflag;
	int iterflag1;
	int iterflag2;
	int iterflag3;
	int iterflag4;
	int iterflag5;
	int iterflag6;
	double qradtorad(int grad);
	double qradtorad1(int grad1);
	double qradtorad2(int grad2);
	double qradtorad3(int grad3);
	double qradtorad4(int grad4);
	double qradtorad5(int grad5);
	double qradtorad6(int grad6);
	afx_msg void OnRButtonDown(UINT var, CPoint point);
	afx_msg void OnRButtonDown1(UINT var, CPoint point);
	afx_msg void OnRButtonDown2(UINT var, CPoint point);
	afx_msg void OnRButtonDown3(UINT var, CPoint point);
	afx_msg void OnRButtonDown4(UINT var, CPoint point);
	afx_msg void OnRButtonDown5(UINT var, CPoint point);
	afx_msg void OnRButtonDown6(UINT var, CPoint point);
	afx_msg void OnLButtonUp(UINT var, CPoint point);
	afx_msg void OnMouseMove(UINT var, CPoint point);
	afx_msg void OnOpen();
	afx_msg void OnSave();
	afx_msg void Graph1();
	afx_msg void Graph2();
	afx_msg void Graph3();
	afx_msg void Graph4();
	afx_msg void Graph5();
	afx_msg void Graph6();
	afx_msg void Graph7();
	afx_msg void OnTimer( UINT );
	

	void Animate();
	void Animate1();
	void Animate2();
	void Animate3();
	void Animate4();
	void Animate5();
	void Animate6();

	void OpenSix();

	int CX;
	int CY;
	int X;
	int Y;

	int CX1;
	int CY1;
	int X1;
	int Y1;

	//---------------------------
	afx_msg void Prop();
	double a,b,A,B,df,da;
	int grad;
	bool IfFirst;
	bool IfAnim;
	bool pause;
	int kcouts;
	//----------------------------
	afx_msg void Prop1();
	double a1, b1, A1, B1, df1, da1;
	int grad1;
	bool IfFirst1;
	bool IfAnim1;
	bool pause1;
	int kcouts1;
	//----------------------------
	afx_msg void Prop2();
	double a2, b2, A2, B2, df2, da2;
	int grad2;
	bool IfFirst2;
	bool IfAnim2;
	bool pause2;
	int kcouts2;
	//----------------------------
	afx_msg void Prop3();
	double a3, b3, A3, B3, df3, da3;
	int grad3;
	bool IfFirst3;
	bool IfAnim3;
	bool pause3;
	int kcouts3;
	//----------------------------
	afx_msg void Prop4();
	double a4, b4, A4, B4, df4, da4;
	int grad4;
	bool IfFirst4;
	bool IfAnim4;
	bool pause4;
	int kcouts4;
	//----------------------------
	afx_msg void Prop5();
	double a5, b5, A5, B5, df5, da5;
	int grad5;
	bool IfFirst5;
	bool IfAnim5;
	bool pause5;
	int kcouts5;
	//----------------------------
	afx_msg void Prop6();
	double a6, b6, A6, B6,df6, da6;
	int grad6;
	bool IfFirst6;
	bool IfAnim6;
	bool pause6;
	int kcouts6;
	//-----------------------------
	CRectD RS;
	CMatrix XX,YY;
	CRect RWX, RW;
	CPlot2D CPlot1;
	CPlot2D CPlot2;
	CPlot2D CPlot3;
	CPlot2D CPlot4;
	CPlot2D CPlot5;
	CPlot2D CPlot6;
	CMyPen PenLine,PenAxis;
	//-----------------------------


// Переопределение
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
protected:
	double pi;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};


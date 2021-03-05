#pragma once
#include "afxcmn.h"


// диалоговое окно CDialogOptions

class CDialogOptions : public CDialog
{
	DECLARE_DYNAMIC(CDialogOptions)

public:
	CDialogOptions(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CDialogOptions();
	BOOL OnInitDialog();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG1 };
	COLORREF COLORLine;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
	
	afx_msg void ButtonClickedOK();
public:
	afx_msg void OnBnClickedMfcbutton1();
	CProgressCtrl LabelColor;
	double InputA;
	double InputB;
	double Inputa;
	double Inputb;
	int InputQ;
	BOOL IfAnim;
	int kcouts;
	afx_msg void OnBnClickedCheck1();
	double df;
	double da;
};

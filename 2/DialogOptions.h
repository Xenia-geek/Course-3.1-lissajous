#pragma once
#include "afxcmn.h"


// ���������� ���� CDialogOptions

class CDialogOptions : public CDialog
{
	DECLARE_DYNAMIC(CDialogOptions)

public:
	CDialogOptions(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CDialogOptions();
	BOOL OnInitDialog();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG1 };
	COLORREF COLORLine;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

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

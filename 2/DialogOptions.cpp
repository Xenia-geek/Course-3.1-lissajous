// DialogOptions.cpp: файл реализации
//

#include "stdafx.h"
#include "2.h"
#include "DialogOptions.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ChildView.h"


// диалоговое окно CDialogOptions

IMPLEMENT_DYNAMIC(CDialogOptions, CDialog)

CDialogOptions::CDialogOptions(CWnd* pParent): CDialog(CDialogOptions::IDD, pParent)
, InputA(0)
, InputB(0)
, Inputa(0)
, Inputb(0)
, InputQ(0)
, IfAnim(FALSE)
, kcouts(0)
, df(0)
, da(0)
{
}

BOOL CDialogOptions::OnInitDialog()
{
	CDialog::OnInitDialog();
	CProgressCtrl *prg = (CProgressCtrl*) GetDlgItem(IDC_PROGRESS1);
	prg->SetBkColor(COLORLine);
	CEdit *ed=(CEdit*)GetDlgItem(IDC_EDIT6);
	ed->SetReadOnly(false);
	//LabelColor.SetBkColor(RGB(255,0,255));
	return true;
}
CDialogOptions::~CDialogOptions()
{
}

void CDialogOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, LabelColor);
	DDX_Text(pDX, IDC_EDIT1, InputA);
	DDX_Text(pDX, IDC_EDIT2, InputB);
	DDX_Text(pDX, IDC_EDIT3, Inputa);
	DDX_Text(pDX, IDC_EDIT4, Inputb);
	DDX_Text(pDX, IDC_EDIT5, InputQ);
	DDX_Check(pDX, IDC_CHECK1, IfAnim);
	DDX_Text(pDX, IDC_EDIT6, kcouts);
	DDX_Text(pDX, IDC_EDIT7, df);
	DDX_Text(pDX, IDC_EDIT8, da);
}


BEGIN_MESSAGE_MAP(CDialogOptions, CDialog)
	ON_BN_CLICKED(IDOK,ButtonClickedOK)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CDialogOptions::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_CHECK1, &CDialogOptions::OnBnClickedCheck1)
END_MESSAGE_MAP()

void CDialogOptions::ButtonClickedOK()
{
	OnOK();
}
// обработчики сообщений CDialogOptions


void CDialogOptions::OnBnClickedMfcbutton1()
{
	CColorDialog GetColorDlg;
	if(GetColorDlg.DoModal()==IDOK)
	{		
		COLORLine = GetColorDlg.GetColor();
		LabelColor.SetBkColor(COLORLine);
	}
}


void CDialogOptions::OnBnClickedCheck1()
{
	CEdit *ed=(CEdit*)GetDlgItem(IDC_EDIT6);
	if(IfAnim)
	{	
	ed->SetReadOnly(true);
	}
	else
	{
	ed->SetReadOnly(false);
	}
}


// 2.h : ������� ���� ��������� ��� ���������� 2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMy2App:
// � ���������� ������� ������ ��. 2.cpp
//

class CMy2App : public CWinApp
{
public:
	CMy2App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2App theApp;

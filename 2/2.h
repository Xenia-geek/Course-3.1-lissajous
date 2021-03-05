
// 2.h : главный файл заголовка для приложения 2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMy2App:
// О реализации данного класса см. 2.cpp
//

class CMy2App : public CWinApp
{
public:
	CMy2App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2App theApp;

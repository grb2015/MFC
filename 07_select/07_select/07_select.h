
// 07_select.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号


// CMy07selectApp:
// 有关此类的实现，请参阅 07_select.cpp
//

class CMy07selectApp : public CWinApp
{
public:
	CMy07selectApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy07selectApp theApp;

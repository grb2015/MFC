﻿
// 03 EditCtrl.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号


// CMy03EditCtrlApp:
// 有关此类的实现，请参阅 03 EditCtrl.cpp
//

class CMy03EditCtrlApp : public CWinApp
{
public:
	CMy03EditCtrlApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy03EditCtrlApp theApp;

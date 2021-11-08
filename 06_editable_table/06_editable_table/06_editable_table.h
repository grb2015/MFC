
// 06_editable_table.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号


// CMy06editabletableApp:
// 有关此类的实现，请参阅 06_editable_table.cpp
//

class CMy06editabletableApp : public CWinApp
{
public:
	CMy06editabletableApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy06editabletableApp theApp;

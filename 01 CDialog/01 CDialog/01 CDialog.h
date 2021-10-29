
// 01 CDialog.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号


// CMy01CDialogApp:
// 有关此类的实现，请参阅 01 CDialog.cpp
//

class CMy01CDialogApp : public CWinApp
{
public:
	CMy01CDialogApp();					/// 构造函数

// 重写
public:
	virtual BOOL InitInstance();		/// 初始化函数

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy01CDialogApp theApp;			/// 定义的类示例

// CDlogExec.cpp: 实现文件
//

#include "pch.h"
#include "01 CDialog.h"
#include "CDlogExec.h"
#include "afxdialogex.h"


// CDlogExec 对话框

IMPLEMENT_DYNAMIC(CDlogExec, CDialogEx)

CDlogExec::CDlogExec(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Exec, pParent)
{

}

CDlogExec::~CDlogExec()
{
}

void CDlogExec::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlogExec, CDialogEx)
END_MESSAGE_MAP()


// CDlogExec 消息处理程序

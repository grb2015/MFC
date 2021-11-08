﻿
// 06_editable_tableDlg.cpp: 实现文件  
/// breif：制作一个可以编辑的table
///	使用方法：双击某个单元格.然后输入新的数值，再单击单元格其他部分，就改好了。

#include "pch.h"
#include "framework.h"
#include "06_editable_table.h"
#include "06_editable_tableDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy06editabletableDlg 对话框



CMy06editabletableDlg::CMy06editabletableDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY06_EDITABLE_TABLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy06editabletableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMy06editabletableDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMy06editabletableDlg::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CMy06editabletableDlg::OnNMDblclkList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMy06editabletableDlg::OnNMClickList1)
END_MESSAGE_MAP()


// CMy06editabletableDlg 消息处理程序

BOOL CMy06editabletableDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
		/// 列表控件的使用	CString str[] = { TEXT }
	CString str[] = { TEXT("姓名"),	TEXT("性别"),	TEXT("年龄") };
	for (int i = 0; i < 3; i++) {
		//设置表头
		m_list.InsertColumn(i, str[i], LVCFMT_LEFT, 100);

	};
	/// 设置正文 
	//m_list.InsertItem(0,TEXT("张三"));	/// 第0行
	/// 给这个Item插入其他类的数据
	//m_list.SetItemText(0, 1, TEXT("男"));	/// 第0行 第1列
	//m_list.SetItemText(0, 2,TEXT("23"));	/// 第0行 第1列
	for (int i = 0; i < 10; i++) {
		int j = 0;
		CString name;
		name.Format(TEXT("张三_%d"), i);
		m_list.InsertItem(i, name);
		m_list.SetItemText(i, ++j, TEXT("男"));
		m_list.SetItemText(i, ++j, TEXT("18"));

	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy06editabletableDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy06editabletableDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy06editabletableDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy06editabletableDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

/// 参考：https://www.cnblogs.com/rogee/archive/2010/11/05/1869961.html
void CMy06editabletableDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	///LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	///*pResult = 0;

	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast <LPNMITEMACTIVATE> (pNMHDR);

	LVHITTESTINFO info;
	info.pt = pNMItemActivate->ptAction;

	if (m_list.SubItemHitTest(&info) != -1)
	{
		hitRow = info.iItem;
		hitCol = info.iSubItem;

		if (editItem.m_hWnd == NULL) // editItem为一输入框控件， 
		{
			RECT rect;
			rect.left = 0;
			rect.top = 0;
			rect.bottom = 15;
			rect.right = 200;
			editItem.Create(WS_CHILD | ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | ES_WANTRETURN | ES_MULTILINE, rect, this, 101);
			editItem.SetFont(this->GetFont(), FALSE);
		}
		CRect rect;
		m_list.GetSubItemRect(info.iItem, info.iSubItem, LVIR_BOUNDS, rect);
		rect.top += 2;		/// 这里的坐标需要慢慢调
		rect.left += 2;
		rect.right += 13;
		rect.bottom += 12;

		editItem.SetWindowText(m_list.GetItemText(info.iItem, info.iSubItem));
		editItem.MoveWindow(&rect, TRUE);
		editItem.ShowWindow(1);
		editItem.SetFocus();
	}
	*pResult = 0;
}

/// 参考：https://www.cnblogs.com/rogee/archive/2010/11/05/1869961.html
void CMy06editabletableDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	///LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	///*pResult = 0;

	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast <LPNMITEMACTIVATE> (pNMHDR);

	if (editItem.m_hWnd != NULL)
	{
		editItem.ShowWindow(0);
		if (hitRow != -1)
		{
			CString text;
			editItem.GetWindowText(text);		/// 获取当前单元格编辑后的新值
			m_list.SetItemText(hitRow, hitCol, text);	/// 保存编辑后的新值
		}
	}
	hitCol = hitRow = -1;
	*pResult = 0;
}

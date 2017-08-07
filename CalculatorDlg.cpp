
// CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mEdit); //1.将变量m_Edit和控件IDC_EDIT进行绑定2.通过修改变量的数值控制控件操作。
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorDlg::OnBnClickedButton22)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO:  在此添加额外的初始化代码
	CFont* m_font = new CFont;
	//创建一种有特殊性的逻辑字体
	m_font->CreateFont(36, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
	mEdit.SetFont(m_font, FALSE);
	lastPress = false;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton1()
{
	// “清屏”按钮
	mEdit.SetWindowText(_T(""));
}

void CCalculatorDlg::Clear()
{
	if (lastPress == true)
	{
		mEdit.SetWindowText(_T(""));
		lastPress = false;
	}
}

void CCalculatorDlg::OnBnClickedButton12()  //6
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("6");
	mEdit.SetWindowText(str);
}



void CCalculatorDlg::OnBnClickedButton14()//1
{
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("1");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton15() //2
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("2");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton17()//3
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("3");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton10()  //4
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("4");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton11() //6
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("5");
	mEdit.SetWindowText(str);
}



void CCalculatorDlg::OnBnClickedButton6()//7
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("7");
	mEdit.SetWindowText(str);
}


void CCalculatorDlg::OnBnClickedButton7()//8
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("8");
	mEdit.SetWindowText(str);
}



void CCalculatorDlg::OnBnClickedButton8()//9
{
	// TODO:  在此添加控件通知处理程序代码
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str + _T("9");
	mEdit.SetWindowText(str);
}



void CCalculatorDlg::OnBnClickedButton2()
{
	// “后退”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	str = str.Left(str.GetLength() - 1);
	mEdit.SetWindowText(str);
}



void CCalculatorDlg::OnBnClickedButton4()
{
	// “左括号”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	if (str == "")
	{
		str = str + _T("(");
		mEdit.SetWindowText(str);
	}
	else
	{
		if (str.GetAt(str.GetLength() - 1)<'0' || str.GetAt(str.GetLength() - 1)>'9')
		{
			str = str + _T("(");
			mEdit.SetWindowText(str);
		}
	}
}



void CCalculatorDlg::OnBnClickedButton5()
{
	// “右括号”按钮
	Clear();
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		if (str.GetAt(str.GetLength() - 1) >= '0' && str.GetAt(str.GetLength() - 1) <= '9')
		{
			str = str + _T(")");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// 加号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		if (str.GetAt(str.GetLength() - 1) != '+' && str.GetAt(str.GetLength() - 1) != '-'
			&& str.GetAt(str.GetLength() - 1) != '*' && str.GetAt(str.GetLength() - 1) != '/')
		{
			str = str + _T("+");
			mEdit.SetWindowText(str);
		}
	}
}



void CCalculatorDlg::OnBnClickedButton13()
{
	// 减号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		if (str.GetAt(str.GetLength() - 1) != '+' && str.GetAt(str.GetLength() - 1) != '-'
			&& str.GetAt(str.GetLength() - 1) != '*' && str.GetAt(str.GetLength() - 1) != '/')
		{
			str = str + _T("-");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedButton18()
{
	// 乘号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		if (str.GetAt(str.GetLength() - 1) != '+' && str.GetAt(str.GetLength() - 1) != '-'
			&& str.GetAt(str.GetLength() - 1) != '*' && str.GetAt(str.GetLength() - 1) != '/')
		{
			str = str + _T("*");
			mEdit.SetWindowText(str);
		}
	}
}


void CCalculatorDlg::OnBnClickedButton21()
{
	// 除号
	lastPress = false;
	CString str;
	mEdit.GetWindowText(str);
	if (str != "")
	{
		if (str.GetAt(str.GetLength() - 1) != '+' && str.GetAt(str.GetLength() - 1) != '-'
			&& str.GetAt(str.GetLength() - 1) != '*' && str.GetAt(str.GetLength() - 1) != '/')
		{
			str = str + _T("/");
			mEdit.SetWindowText(str);
		}
	}
}



void CCalculatorDlg::OnBnClickedButton22()
{
	// 等号，计算结果
	CString str;
	mEdit.GetWindowText(str);
	if (str.Find('+') == -1 && str.Find('-') == -1 && str.Find('*') == -1 && str.Find('/') == -1)
		return;
	else
		lastPress = true;

	CT2CA pszConvertedAnsiString(str);  // 将 TCHAR 转换为 LPCSTR
	string exp_str(pszConvertedAnsiString); // 从 LPCSTR 构造 string

	if (exp_str != "")
	{
		Expression_Capacity e(exp_str);
		if (e.test())
		{
			string tmp;
			stringstream ss;
			ss << e.calculate();
			ss >> tmp;
			str = tmp.c_str();
		}
		else
		{
			str = "输入错误";
		}
		mEdit.SetWindowText(str);
	}
}

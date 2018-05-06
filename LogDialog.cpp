// LogDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphics_Work.h"
#include "LogDialog.h"
#include "afxdialogex.h"
#include "ExitDialog.h"

// CLogDialog 对话框

IMPLEMENT_DYNAMIC(CLogDialog, CDialogEx)

CLogDialog::CLogDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogDialog::IDD, pParent)
{

}

CLogDialog::~CLogDialog()
{
}

void CLogDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Teacher, m_teacher);
	DDX_Control(pDX, IDC_Student, m_student);
	DDX_Control(pDX, IDC_BUTTON1, m_enter);
	DDX_Control(pDX, IDC_Exit, m_exit);
	DDX_Control(pDX, IDC_Title, m_title);
}


BEGIN_MESSAGE_MAP(CLogDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogDialog::OnEnter)
	ON_BN_CLICKED(IDC_Exit, &CLogDialog::OnExit)
	ON_WM_CTLCOLOR()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLogDialog 消息处理程序

BOOL CLogDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	//AnimateWindow(3000, AW_HOR_NEGATIVE | AW_SLIDE);//3秒内窗口从右向左弹出
	//AnimateWindow(4000,AW_HIDE| AW_BLEND);
	ModifyStyle(WS_SYSMENU, 0); // 隐藏关闭栏

	ModifyStyle(WS_CAPTION, 0); // 隐藏标题
	// 控制静态文本的字体 和 大小

	m_Font.CreatePointFont(150, _T("楷体"), NULL);
	m_teacher.SetFont(&m_Font, true);
	m_student.SetFont(&m_Font, true);

	m_Font1.CreatePointFont(100, _T("宋体"), NULL);
	m_enter.SetFont(&m_Font1, true);
	m_exit.SetFont(&m_Font1, true);

	m_Font2.CreatePointFont(200, _T("宋体"), NULL);
	m_title.SetFont(&m_Font2, true);
	//m_teacher.SetWindowText(_T("")); // 设置静态文本内容
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}



void CLogDialog::OnEnter()
{
	// TODO:  在此添加控件通知处理程序代码
	Enter = true;
	SendMessage(WM_CLOSE);
}


void CLogDialog::OnExit()
{
	// TODO:  在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE);
}


HBRUSH CLogDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// 控制静态文本的颜色和背景颜色
	if (IDC_Teacher == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		//pDC->SetBkColor(RGB(0, 0, 255));//设置文本背景
		hbr = CreateSolidBrush(RGB(0, 255, 0));//控件的背景色为绿色
	}

	if (IDC_Student == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		//pDC->SetBkColor(RGB(0, 0, 255));//设置文本背景
		hbr = CreateSolidBrush(RGB(0, 255, 0));//控件的背景色为绿色
	}

	// TODO:  在此更改 DC 的任何特性

	// 设置背景图片 bmp格式
	static CBrush gBr;
	static bool isInited = false;
	if (!isInited)
	{
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP2); // bmp图片的ID
		gBr.CreatePatternBrush(&bitmap);
		COLORREF clearColor = -1;
		bitmap.DeleteObject();
		isInited = true;
	}
	if (pWnd == this)
	{
		pDC->SetBkMode(TRANSPARENT);
		return gBr; //主窗口背景使用这个背景刷
	}
	else
	{
		pDC->SetBkMode(TRANSPARENT);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH); //其他控件使用透明背景
	}


	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CLogDialog::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (!Enter) {
		ExitDialog dlg;
		if (dlg.DoModal() == IDCANCEL) {
			return;
		}
	}
	CDialogEx::OnClose();
}

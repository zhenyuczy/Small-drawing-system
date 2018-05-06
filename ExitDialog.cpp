// ExitDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphics_Work.h"
#include "ExitDialog.h"
#include "afxdialogex.h"


// ExitDialog 对话框

IMPLEMENT_DYNAMIC(ExitDialog, CDialogEx)

ExitDialog::ExitDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(ExitDialog::IDD, pParent)
{

}

ExitDialog::~ExitDialog()
{
}

void ExitDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Sure, m_sure);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDCANCEL, m_cancle);
}


BEGIN_MESSAGE_MAP(ExitDialog, CDialogEx)
END_MESSAGE_MAP()


// ExitDialog 消息处理程序


BOOL ExitDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	ModifyStyle(WS_SYSMENU, 0);
	//ModifyStyle(WS_CAPTION, 0);
	m_Font.CreatePointFont(150, _T("楷体"), NULL);
	m_sure.SetFont(&m_Font, true);

	m_Font1.CreatePointFont(100, _T("宋体"), NULL);
	m_ok.SetFont(&m_Font1, true);
	m_cancle.SetFont(&m_Font1, true);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

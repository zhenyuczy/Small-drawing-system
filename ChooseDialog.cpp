// ChooseDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Graphics_Work.h"
#include "ChooseDialog.h"
#include "afxdialogex.h"


// CChooseDialog 对话框

IMPLEMENT_DYNAMIC(CChooseDialog, CDialogEx)

CChooseDialog::CChooseDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChooseDialog::IDD, pParent)
	, m_Vnumber(_T(""))
{

}

CChooseDialog::~CChooseDialog()
{
}

void CChooseDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Choosenumber, C_Cnumber);
	DDX_Text(pDX, IDC_Choosenumber, m_Vnumber);
}


BEGIN_MESSAGE_MAP(CChooseDialog, CDialogEx)
	ON_BN_CLICKED(IDC_CANCLE, &CChooseDialog::OnBnClickedCancle)
	ON_BN_CLICKED(IDC_RADIO1, &CChooseDialog::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CChooseDialog::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CChooseDialog::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_OK, &CChooseDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CChooseDialog 消息处理程序

int op, n;
bool start;

BOOL CChooseDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	C_Cnumber.EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CChooseDialog::OnBnClickedCancle()
{
	// TODO:  在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE);
	start = false;
}


void CChooseDialog::OnBnClickedRadio1()
{
	// TODO:  在此添加控件通知处理程序代码
	op = 1;
	C_Cnumber.EnableWindow(false);
}


void CChooseDialog::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
	op = 2;
	C_Cnumber.EnableWindow(false);
}


void CChooseDialog::OnBnClickedRadio3()
{
	// TODO:  在此添加控件通知处理程序代码
	op = 3;
	C_Cnumber.EnableWindow(true);
}


void CChooseDialog::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	if (op == 1 || op == 2) {
		start = true;
		SendMessage(WM_CLOSE);
		return;
	}
	if (op == 3) {
		UpdateData(true);
		bool flag = false;
		int len = m_Vnumber.GetLength();
		if (len >= 4) {
			MessageBox(_T("请输入2~100的整数"), _T("提示"));
			return;
		}
		n = 0;
		for (int i = 0; i < len; i++) {
			if (!(m_Vnumber[i] - '0' >= 0 && m_Vnumber[i] - '0' <= 9)) {
				flag = true; break;
			}
			else {
				n = n * 10 + (m_Vnumber[i] - '0');
			}
		}
		if (flag || (!flag && (n <= 1 || n > 100))) {
			MessageBox(_T("请输入2~100的整数"), _T("提示"));
		}
		else {
			start = true;
			SendMessage(WM_CLOSE);
		}
	}
}


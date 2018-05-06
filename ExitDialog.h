#pragma once
#include "afxwin.h"


// ExitDialog 对话框

class ExitDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ExitDialog)

public:
	ExitDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ExitDialog();

// 对话框数据
	enum { IDD = IDD_Exit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_sure;
	virtual BOOL OnInitDialog();
private:
	CFont m_Font, m_Font1;
public:
	CButton m_ok;
	CButton m_cancle;
};

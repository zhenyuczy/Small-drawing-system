#pragma once
#include "afxwin.h"


// CChooseDialog 对话框

class CChooseDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseDialog)

public:
	CChooseDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChooseDialog();

// 对话框数据
	enum { IDD = IDD_Choose };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit C_Cnumber;
	afx_msg void OnBnClickedCancle();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedOk();
	CString m_Vnumber;
};

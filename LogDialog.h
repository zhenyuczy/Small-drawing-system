#pragma once
#include "afxwin.h"


// CLogDialog 对话框

class CLogDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CLogDialog)

public:
	CLogDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLogDialog();

// 对话框数据
	enum { IDD = IDD_LogDialog };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_teacher;
	CStatic m_student;
	virtual BOOL OnInitDialog();
private:
	CFont m_Font, m_Font1, m_Font2;
public:
	afx_msg void OnEnter();
	afx_msg void OnExit();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_enter;
	CButton m_exit;
	afx_msg void OnClose();
	CStatic m_title;
};

extern bool Enter;
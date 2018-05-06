
// ChildFrm.cpp : CChildFrame 类的实现
//

#include "stdafx.h"
#include "Graphics_Work.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CChildFrame 构造/析构

CChildFrame::CChildFrame()
{
	// TODO:  在此添加成员初始化代码
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs) // 视图子窗口
{
	// TODO:  在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.style &= ~FWS_ADDTOTITLE | WS_VISIBLE | WS_MAXIMIZE;//取消窗口上的文档标题
	cs.style |= WS_VISIBLE | WS_MAXIMIZE; // 最大化
	return TRUE;
}

// CChildFrame 诊断

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// CChildFrame 消息处理程序


int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	// 隐藏最大化，最小化，关闭按钮  
	ModifyStyle(WS_SYSMENU, 0);


	// 隐藏标题栏  
	ModifyStyle(WS_CAPTION, 0);

	// 去掉菜单栏  
	// SetMenu(NULL);
	return 0;
}

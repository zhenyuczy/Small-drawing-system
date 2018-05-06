
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Graphics_Work.h"

#include "MainFrm.h"
#include "LogDialog.h"
#include "ExitDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

bool Enter;
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.ShowWindow(SW_HIDE);//隐藏工具栏
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	//全屏显示
	RECT rc;
	::GetWindowRect(::GetDesktopWindow(), &rc);
	this->MoveWindow(&rc);
	
	CLogDialog Dlg; // 开始界面
	Dlg.DoModal();

	SetTimer(1, 10, NULL);
	if (!Enter) {
		exit(0);
	}


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.style &= ~FWS_ADDTOTITLE | WS_VISIBLE | WS_MAXIMIZE;//取消窗口上的文档标题
	cs.lpszName = _T("小型绘图系统"); // 文件上方标题重命名
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序
// 分层
/*BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
	m_splitter.CreateStatic(this, 1, 1); // 行数，列数，不能超过16
	m_splitter.CreateView(0, 1, RUNTIME_CLASS(CGraphics_WorkView), CSize(520, 600), pContext);
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	}
}
*/

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("当前时间 %H:%M:%S");

	CClientDC dc(this); 
	CSize sz = dc.GetTextExtent(str);
	int index = 0;
	index = m_wndStatusBar.CommandToIndex(ID_INDICATOR_NUM);
	m_wndStatusBar.SetPaneInfo(index, ID_INDICATOR_NUM, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(index, str);

	CMDIFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	ExitDialog dlg;
	if (dlg.DoModal() == IDCANCEL) {
		return;
	}
	CMDIFrameWnd::OnClose();
}

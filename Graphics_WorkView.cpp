
// Graphics_WorkView.cpp : CGraphics_WorkView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Graphics_Work.h"
#endif

#include "Graphics_WorkDoc.h"
#include "Graphics_WorkView.h"
#include "MainFrm.h"
#include "ChooseDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGraphics_WorkView

IMPLEMENT_DYNCREATE(CGraphics_WorkView, CView)

BEGIN_MESSAGE_MAP(CGraphics_WorkView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_32772, &CGraphics_WorkView::OnOneOne)
	ON_COMMAND(ID_32773, &CGraphics_WorkView::OnOneTwo)
	ON_COMMAND(ID_32777, &CGraphics_WorkView::OnOneThreeOne)
	ON_COMMAND(ID_32778, &CGraphics_WorkView::OnOneThreeTwo)
	ON_COMMAND(ID_32776, &CGraphics_WorkView::OnTwoOne)
	ON_COMMAND(ID_32779, &CGraphics_WorkView::OnTwoTwo)
	ON_COMMAND(ID_32786, &CGraphics_WorkView::OnThreeOneTwo)
	ON_COMMAND(ID_32783, &CGraphics_WorkView::OnThreeTwo)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_COMMAND(ID_32785, &CGraphics_WorkView::OnThreeOneOne)
	//ON_COMMAND(ID_32780, &CGraphics_WorkView::OnTwoThree)
	ON_COMMAND(ID_32787, &CGraphics_WorkView::OnThreeThreeOne)
	ON_COMMAND(ID_32788, &CGraphics_WorkView::OnThreeThreeTwo)
	ON_COMMAND(ID_32790, &CGraphics_WorkView::OnFourOne)
	ON_COMMAND(ID_32791, &CGraphics_WorkView::OnFourTwo)
	ON_COMMAND(ID_32792, &CGraphics_WorkView::OnFourThree)
	ON_COMMAND(ID_32794, &CGraphics_WorkView::OnFiveOne)
	ON_COMMAND(ID_32795, &CGraphics_WorkView::OnFiveTwo)
	ON_COMMAND(ID_32797, &CGraphics_WorkView::OnFiveThreeOne)
	ON_COMMAND(ID_32800, &CGraphics_WorkView::OnSixOne)
	ON_COMMAND(ID_32798, &CGraphics_WorkView::OnFiveThreeTwo)
	ON_COMMAND(ID_32801, &CGraphics_WorkView::OnSixTwo)
	ON_COMMAND(ID_32802, &CGraphics_WorkView::OnSixThree)
	ON_COMMAND(ID_32809, &CGraphics_WorkView::OnDrawColor)
	ON_COMMAND(ID_32810, &CGraphics_WorkView::OnDrawLine)
	ON_COMMAND(ID_32811, &CGraphics_WorkView::OnDrawTriangle)
	ON_COMMAND(ID_32815, &CGraphics_WorkView::OnDrawClear)
	ON_COMMAND(ID_32812, &CGraphics_WorkView::OnDrawRectangle)
	ON_COMMAND(ID_32813, &CGraphics_WorkView::OnDrawCycle)
	ON_COMMAND(ID_32814, &CGraphics_WorkView::OnDrawFreeLine)
	ON_COMMAND(ID_32817, &CGraphics_WorkView::OnUpdo)
	ON_COMMAND(ID_32816, &CGraphics_WorkView::OnRedo)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32818, &CGraphics_WorkView::OnTwoThree)
	ON_WM_CLOSE()
	ON_COMMAND(ID_32819, &CGraphics_WorkView::OnEraser)
	ON_WM_KEYUP()
END_MESSAGE_MAP()
int Operator = 6;

extern bool start;

int Draw_Operator[100000], Stack_top = 0;
// CGraphics_WorkView 构造/析构

CGraphics_WorkView::CGraphics_WorkView()
{
	// TODO:  在此处添加构造代码
	Case = 0;

}

CGraphics_WorkView::~CGraphics_WorkView()
{
}

BOOL CGraphics_WorkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

// CGraphics_WorkView 绘制

void CGraphics_WorkView::OnDraw(CDC* /*pDC*/)
{
	CGraphics_WorkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO:  在此处为本机数据添加绘制代码

	// 清除颜色  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 绘制场景  
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	DrawPicture();
	glPopMatrix();
	// 交换缓冲区  
	SwapBuffers(wglGetCurrentDC());
}


// CGraphics_WorkView 打印

BOOL CGraphics_WorkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGraphics_WorkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CGraphics_WorkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CGraphics_WorkView 诊断

#ifdef _DEBUG
void CGraphics_WorkView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphics_WorkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphics_WorkDoc* CGraphics_WorkView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphics_WorkDoc)));
	return (CGraphics_WorkDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphics_WorkView 消息处理程序


int CGraphics_WorkView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  在此添加您专用的创建代码
	// 创建DC  

	m_pDC = new CClientDC(this);
	ASSERT(m_pDC != NULL);
	// 选择像素格式  
	if (!bSetDCPixelFormat()) return -1;
	// 创建渲染环境, 并使它成为当前渲染环境  
	m_hRC = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);
	return 0;
}


void CGraphics_WorkView::OnDestroy()
{
	CView::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
	// 释放资源  
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_hRC);
	delete m_pDC;
}


void CGraphics_WorkView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	// 设置视口  
	/*glViewport(0, 0, cx, cy);
	// 设置投影矩阵(透视投影)  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
	// 设置模型视图矩阵  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); */
}


void CGraphics_WorkView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	// glClearColor(0, 0, 0, 1);
}


bool CGraphics_WorkView::bSetDCPixelFormat() {
	// 设置像素格式  
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR), // 结构的大小  
		1, // 结构的版本  
		PFD_DRAW_TO_WINDOW | // 在窗口(而不是位图)中绘图  
		PFD_SUPPORT_OPENGL | // 支持在窗口中进行OpenGL调用  
		PFD_DOUBLEBUFFER, // 双缓冲模式  
		PFD_TYPE_RGBA, // RGBA颜色模式  
		32, // 需要32位颜色  
		0, 0, 0, 0, 0, 0, // 不用于选择模式  
		0, 0, // 不用于选择模式  
		0, 0, 0, 0, 0, // 不用于选择模式  
		16, // 深度缓冲区的大小  
		0, // 在此不使用  
		0, // 在此不使用  
		0, // 在此不使用  
		0, // 在此不使用  
		0, 0, 0 // 在此不使用  
	};
	// 选择一种与pfd所描述的最匹配的像素格式  
	int nPixelFormat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);
	if (0 == nPixelFormat) return false;
	// 为设备环境设置像素格式  
	return SetPixelFormat(m_pDC->GetSafeHdc(), nPixelFormat, &pfd);
}

OneOne m_oneone; // 1
OneTwo m_onetwo; // 2
OneThreeOne m_onethreeone; // 3
OneThreeTwo m_onethreetwo; // 4
TwoOne m_twoone; // 5
TwoTwo m_twotwo; // 6
TwoThree m_twothree; // 7

ThreeOneOne m_threeoneone; // 8
ThreeOneTwo m_threeonetwo; // 9
ThreeTwo m_threetwo; // 10
ThreeThreeOne m_threethreeone; // 11
ThreeThreeTwo m_threethreetwo; // 12
FourOne m_fourone; // 13
FourTwo m_fourtwo; // 14
FourThree m_fourthree; // 15
FiveOne m_fiveone; // 16
FiveTwo m_fivetwo; // 17
FiveThreeOne m_fivethreeone; // 18
FiveThreeTwo m_fivethreetwo; // 19
SixOne m_sixone; // 20
SixTwo m_sixtwo; // 21
SixThree m_sixthree; // 22
Draw m_draw; // 

LINE m_line;
TRIANGLE m_triangle;
RECTANGLE m_rectangle;
CYCLE m_cycle;
FREELINE m_freeline;
Eraser m_eraser;

REDO_STACK m_redo;

// 将绘制的图形分段，用vector保存，记录每段的终点
vector<int> mark_line;
vector<int> mark_triangle;
vector<int> mark_rectangle;
vector<int> mark_cycle;
vector<int> mark_freeline;
vector<int> mark_eraser;

int mark_id[100000];

double Move_x, Move_y, Move_z;
void CGraphics_WorkView::DrawPicture()
{
	// TODO:  在此添加命令处理程序代码
	CRect rc; GetWindowRect(&rc);
	int cx = rc.Width(); int cy = rc.Height();
	int ID;
	if (Case == 0) {
		if (Stack_top > 0) {
			Clear(); m_draw.Init(); m_draw.Reshape(cx, cy);
			// 打标记，维护绘图的先后次序
			for (int i = 0; i < Stack_top; i++) {
				ID = mark_id[i];
				switch (Draw_Operator[i]) {
				case 1:
					m_draw.Line_Work(ID); m_line.Display(); break;
				case 2:
					m_draw.Triangle_Work(ID); m_triangle.Display(); break;
				case 3:
					m_draw.Rectangle_Work(ID); m_rectangle.Display(); break;
				case 4:
					m_draw.Cycle_Work(ID); m_cycle.Display(); break;
				case 5:
					m_draw.FreeLine_Work(ID); m_freeline.Display(); break;
				case 6:
					m_draw.Eraser_Work(ID); m_eraser.Display(); break;
				}
			}
		}
		return;
	}
	Draw_Clear();
	switch (Case) {
	case 1: 
		Clear(); 
		if(m_oneone.init) { 
			m_oneone.Init(); 
		}
		if (m_oneone.reshape) { 
			m_oneone.Reshape(cx, cy); 
		} 
		m_oneone.Display(); break;
	case 2: 
		Clear(); 
		if (m_onetwo.init) { 
			m_onetwo.Init(); 
		}
		if (m_onetwo.reshape) { 
			m_onetwo.Reshape(cx, cy); 
		} 
		m_onetwo.Display(); break;
	case 3: 
		Clear(); 
		if (m_onethreeone.init) { 
			m_onethreeone.Init(); 
		}
		if (m_onethreeone.reshape) { 
			m_onethreeone.Reshape(cx, cy); 
		} 
		m_onethreeone.Display(); break;
	case 4: 
		Clear(); 
		if (m_onethreetwo.init) { 
			m_onethreetwo.Init();
		} 
		if (m_onethreetwo.reshape) { 
			m_onethreetwo.Reshape(cx, cy); 
		} 
		m_onethreetwo.Display(); break;
	case 5: 
		Clear(); 
		if (m_twoone.init) { 
			m_twoone.Init(); 
		} 
		if (m_twoone.reshape) { 
			m_twoone.Reshape(cx, cy);
		} 
		m_twoone.Display(); break;
	case 6: 
		Clear(); 
		if (m_twotwo.init) { 
			m_twotwo.Init(); 
		}
		if (m_twotwo.reshape) { 
			m_twotwo.Reshape(cx, cy); 
		} 
		m_twotwo.Display(); break;
	case 7: 
		Clear(); 
		if (m_twothree.init) { 
			m_twothree.Init(); 
		}
		if (m_twothree.reshape) { 
			m_twothree.Reshape(cx, cy); 
		} 
		m_twothree.Display(); break;
	case 8: 
		Clear(); 
		if (m_threeoneone.init) { 
			m_threeoneone.Init(); 
		}
		if (m_threeoneone.reshape) { 
			m_threeoneone.Reshape(cx, cy); 
		} 
		m_threeoneone.Display(); break;
	case 9: 
		Clear(); 
		if (m_threeonetwo.init) { 
			m_threeonetwo.Init(); 
		}
		if (m_threeonetwo.reshape) { 
			m_threeonetwo.Reshape(cx, cy); 
		} 
		m_threeonetwo.Display(); break;
	case 10: 
		Clear(); 
		if (m_threetwo.init) { 
			m_threetwo.Init(); 
		}
	    if (m_threetwo.reshape) { 
			m_threetwo.Reshape(cx, cy); 
		} 
		m_threetwo.Display(); break;
	case 11: 
		Clear(); 
		if (m_threethreeone.init) { 
			m_threethreeone.Init(); 
		}
		if (m_threeoneone.reshape) { 
			m_threethreeone.Reshape(cx, cy); 
		} 
		m_threethreeone.Display(); break;
	case 12: 
		Clear(); 
		if (m_threethreetwo.init) { 
			m_threethreetwo.Init(); 
		} 
		if (m_threethreetwo.reshape) { 
			m_threethreetwo.Reshape(cx, cy); 
		} 
		m_threethreetwo.Display(); break;
	case 13: 
		Clear(); 
		if (m_fourone.init) { 
			m_fourone.Init(); 
		} 
		if (m_fourone.reshape) { 
			m_fourone.Reshape(cx, cy); 
		} 
		m_fourone.Recover(); 
   	    if (m_fourone.Cut) {
			Line L = Line(Point(m_fourone.x1, m_fourone.y1), Point(m_fourone.x2, m_fourone.y2), m_fourone.C);
			m_fourone.Cohen_Sutherland(L, Point(-0.5, -0.5), Point(0.5, 0.5));
		}
		break;
	case 14:
		Clear();
		if (m_fourtwo.init) { 
			m_fourtwo.Init();
		}
		if (m_fourtwo.reshape) { 
			m_fourtwo.Reshape(cx, cy);	
		} 
		m_fourtwo.Recover();
		if (m_fourtwo.Cut) {
			Line L = Line(Point(m_fourtwo.x1, m_fourtwo.y1), Point(m_fourtwo.x2, m_fourtwo.y2), m_fourtwo.C);
			m_fourtwo.Cohen_Sutherland(L, Point(-0.5, -0.5), Point(0.5, 0.5));
			L = Line(Point(m_fourtwo.x3, m_fourtwo.y3), Point(m_fourtwo.x4, m_fourtwo.y4), m_fourtwo.C1);
			m_fourtwo.Cohen_Sutherland(L, Point(-0.5, -0.5), Point(0.5, 0.5));
			L = Line(Point(m_fourtwo.x5, m_fourtwo.y5), Point(m_fourtwo.x6, m_fourtwo.y6), m_fourtwo.C2);
			m_fourtwo.Cohen_Sutherland(L, Point(-0.5, -0.5), Point(0.5, 0.5));
		}
		break;
	case 15:
		Clear(); 
		if (m_fourthree.init) { 
			m_fourthree.Init(); 
		}
		if (m_fourthree.reshape) { 
			m_fourthree.Reshape(cx, cy); 
		} 
		m_fourthree.Recover();
		if (m_fourthree.Left) {
			for (int i = 0; i < m_fourthree.Id; i++) {
				Line L = m_fourthree.G[i]; m_fourthree.Cohen_Sutherland(L, Point(-0.5, -0.5), Point(0.5, 0.5));
			}
			for (int i = m_fourthree.Id; i < (int)m_fourthree.G.size(); i++) { 
				m_fourthree.Insert(m_fourthree.G[i]); 
			}
			if (m_fourthree.NewLine) {
				m_fourthree.Draw();
			}
		}
		if (m_fourthree.Right) {
			m_fourthree.Id = m_fourthree.G.size();
			for (int i = 0; i < m_fourthree.Id; i++) {
				Line L = m_fourthree.G[i]; m_fourthree.Cohen_Sutherland(L, Point(-0.5, -0.5), Point(0.5, 0.5));
			}	
		}
		if (m_fourthree.Middle) { 
			m_fourthree.G.clear(); m_fourthree.Id = 0; 
		} 
		break;
	case 16:
		Clear(); 
		if (m_fiveone.init) { 
			m_fiveone.Init(); 
		}
		if (m_fiveone.reshape) {
			m_fiveone.Reshape(cx, cy); 
		} 
		m_fiveone.Display(); break;
	case 17:
		Clear(); 
		if (m_fivetwo.init) { 
			m_fivetwo.Init(); 
		} 
		if (m_fivetwo.reshape) { 
			m_fivetwo.Reshape(cx, cy); 
		} 
		m_fivetwo.Display(); break;
	case 18:
		Clear(); 
		if (m_fivethreeone.init) { 
			m_fivethreeone.Init(); 
		}
		if (m_fivethreeone.reshape) { 
			m_fivethreeone.Reshape(cx, cy); 
		} 
		m_fivethreeone.Display(); break;
	case 19:
		Clear(); 
		if (m_fivethreetwo.init) { 
			m_fivethreetwo.Init(); 
		}
		if (m_fivethreetwo.reshape) { 
			m_fivethreetwo.Reshape(cx, cy); 
		} 
		m_fivethreetwo.Display(); break;
	case 20:
		Clear(); 
		if (m_sixone.init) { 
			m_sixone.Init(); 
		}
		if (m_sixone.reshape) { 
			m_sixone.Reshape(cx, cy); 
		} 
		m_sixone.Display(); break;
	case 21:
		Clear(); 
		if (m_sixtwo.init) {
			m_sixtwo.Init(); 
		}
		if (m_sixtwo.reshape) { 
			m_sixtwo.Reshape(cx, cy);
		} 
		m_sixtwo.Display(); break;
	case 22:
		if (m_sixthree.loopr) {
			SetTimer(22, 1, NULL);
		}
		Clear(); 
		if (m_sixthree.init) {
			m_sixthree.Init(); 
		}
		if (m_sixthree.reshape) { 
			m_sixthree.Reshape(cx, cy); 
		} 
		m_sixthree.Display();  break;
	}
}
void CGraphics_WorkView::OnOneOne() 
{
	// TODO:  在此添加命令处理程序代码
	Case = 1; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnOneTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 2; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnOneThreeOne() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 3; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnOneThreeTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 4; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnTwoOne() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 5; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnTwoTwo()
{
	// TODO:  在此添加命令处理程序代码
	Case = 6; ClearMove();
	MessageBox(_T("  请选择直线与点的颜色"), _T("提示"));
	COLORREF color = RGB(255, 0, 0);
	CColorDialog colorDlg(color);
	if (IDOK == colorDlg.DoModal()) {
		// 获取颜色对话框中选择的颜色值
		color = colorDlg.GetColor();
		// 获取R、G、B分量
		m_twotwo.R = GetRValue(color);
		m_twotwo.G = GetGValue(color);
		m_twotwo.B = GetBValue(color);
	}
	InvalidateRect(NULL, FALSE);
	/*CDialog* dlg = new CDialog;
	dlg->Create(MAKEINTRESOURCE(IDD_DIALOG1)); // 对话框ID
	dlg->ShowWindow(1);
	m_twothree.op = Operator;*/
}

void CGraphics_WorkView::OnTwoThree() { 
	// TODO:  在此添加命令处理程序代码
	CChooseDialog dlg;
	dlg.DoModal();
	if (start) {
		Case = 7; ClearMove();
		SendMessage(WM_PAINT);
	}
}
void CGraphics_WorkView::OnThreeOneOne() 
{
	// TODO:  在此添加命令处理程序代码
	Case = 8; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnThreeOneTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 9; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnThreeTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 10; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnThreeThreeOne() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 11; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnThreeThreeTwo() 
{
	// TODO:  在此添加命令处理程序代码
	Case = 12; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnFourOne() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 13; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnFourTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 14; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnFourThree() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 15;	ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnFiveOne() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 16; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnFiveTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 17; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnFiveThreeOne() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 18; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnFiveThreeTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 19; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnSixOne() 
{
	// TODO:  在此添加命令处理程序代码
	Case = 20; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnSixTwo() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 21; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnSixThree() 
{ 
	// TODO:  在此添加命令处理程序代码
	Case = 22; ClearMove(); 
	InvalidateRect(NULL, FALSE); 
}

//stack<int> COLOR;
void CGraphics_WorkView::OnDrawColor()
{
	// TODO:  在此添加命令处理程序代码
	// MessageBox(_T("  请选择画笔的颜色"), _T("提示"));
	COLORREF color = RGB(255, 0, 0);
	CColorDialog colorDlg(color);
	if (IDOK == colorDlg.DoModal()) {
		// 获取颜色对话框中选择的颜色值
		color = colorDlg.GetColor();
		// 获取R、G、B分量
		m_rectangle.R = m_line.R = m_freeline.R = m_draw.R = m_cycle.R = m_triangle.R
			= GetRValue(color);
		m_rectangle.G = m_line.G = m_freeline.G = m_draw.G = m_cycle.G = m_triangle.G
			= GetGValue(color);
		m_rectangle.B = m_line.B = m_freeline.B = m_draw.B = m_cycle.B = m_triangle.B
			= GetBValue(color);
	}
	InvalidateRect(NULL, FALSE);
}

void CGraphics_WorkView::OnDrawLine() 
{ 
	// TODO:  在此添加命令处理程序代码
	mark_line.push_back(0);
	mark_id[Stack_top] = (int)mark_line.size() - 1;
	Case = 0; Draw_Operator[Stack_top++] = 1; 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnDrawTriangle() 
{ 
	// TODO:  在此添加命令处理程序代码
	mark_triangle.push_back(0);
	mark_id[Stack_top] = (int)mark_triangle.size() - 1;
	Case = 0; Draw_Operator[Stack_top++] = 2; 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnDrawRectangle() 
{ 
	// TODO:  在此添加命令处理程序代码
	mark_rectangle.push_back(0);
	mark_id[Stack_top] = (int)mark_rectangle.size() - 1;
	Case = 0; Draw_Operator[Stack_top++] = 3; 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnDrawCycle() 
{ 
	// TODO:  在此添加命令处理程序代码
	mark_cycle.push_back(0);
	mark_id[Stack_top] = (int)mark_cycle.size() - 1;
	Case = 0; Draw_Operator[Stack_top++] = 4; 
	InvalidateRect(NULL, FALSE); 
}

void CGraphics_WorkView::OnDrawFreeLine() 
{ 
	// TODO:  在此添加命令处理程序代码
	// int top = (int)mark_freeline.size() - 1;
	mark_freeline.push_back(0); Case = 0;
	mark_id[Stack_top] = (int)mark_freeline.size() - 1;
	Draw_Operator[Stack_top++] = 5; 
	InvalidateRect(NULL, FALSE); 
}

bool Not_Operator[10000];
void CGraphics_WorkView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	CRect rc; GetWindowRect(&rc);
	int cx = rc.Width(); int cy = rc.Height();
	if (Case == 0) {
		if (Stack_top > 0) {
			switch (Draw_Operator[Stack_top - 1]) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			}
		}
		return;
	}
	switch (Case) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10: // 10
		m_threetwo.Left = true;
		m_threetwo.Right = false;
		SetTimer(10, 1, NULL);
		InvalidateRect(NULL, FALSE);
		break;
	case 11: // 11
		m_threethreeone.Left = true;
		m_threethreeone.Right = false;
		SetTimer(11, 1, NULL);
		InvalidateRect(NULL, FALSE);
		break;
	case 12: // 1 2 3
		KillTimer(2); KillTimer(3); 
		if (m_threethreetwo.flag[1]) return;
		m_threethreetwo.flag[1] = m_threethreetwo.flag[2] = m_threethreetwo.flag[3] = false;
		//m_threethreetwo.r[1] = m_threethreetwo.r[2] = m_threethreetwo.r[3] = 0;
		m_threethreetwo.flag[1] = true;
		SetTimer(1, 1, NULL);
		InvalidateRect(NULL, FALSE);
		break;
	case 13:
		m_fourone.Cut = false;
		InvalidateRect(NULL, FALSE);
		break;
	case 14:
		m_fourtwo.Cut = false;
		InvalidateRect(NULL, FALSE);
		break;
	case 15:
		m_fourthree.Left = m_fourthree.NewLine = true;
		m_fourthree.Middle = m_fourthree.Right = false;
		InvalidateRect(NULL, FALSE);
		break;
	case 16:
		if ((int)m_fiveone.Pt.size() == 4) {
			if (m_fiveone.flag) {
				m_fiveone.Pt.clear();
				m_fiveone.flag = false;
				Move_x = Move_y = 0;
				m_fiveone.Pt.push_back(Point(point.x, cy - point.y));
				InvalidateRect(NULL, FALSE);
			}
			else {
				m_fiveone.flag = true;
				SendMessage(WM_PAINT, 0, 0); // priority 
			}
			//InvalidateRect(NULL, FALSE);	
		}
		else {
			m_fiveone.Pt.push_back(Point(point.x, cy - point.y));
			InvalidateRect(NULL, FALSE);
		}
		break;
	case 17:
		if ((int)m_fivetwo.Pt.size() == 4) {
			if (m_fivetwo.flag) {
				m_fivetwo.Pt.clear();
				m_fivetwo.flag = false;
				Move_x = Move_y = 0;
				m_fivetwo.Pt.push_back(Point(point.x, cy - point.y));
				InvalidateRect(NULL, FALSE);
			}
			else {
				m_fivetwo.flag = true;
				SendMessage(WM_PAINT, 0, 0); // priority 
			}
			//InvalidateRect(NULL, FALSE);	
		}
		else {
			m_fivetwo.Pt.push_back(Point(point.x, cy - point.y));
			InvalidateRect(NULL, FALSE);
		}
		break;
	case 18:
		if (m_fivethreeone.Start) {
			GLuint selectBuffer[100];//存放物体名称的栈
			int hits;//存放被选中对象个数
			int viewport[4];//存放可视区参数
			hits = 0;
			m_fivethreeone.Change = true;
			glGetIntegerv(GL_VIEWPORT, viewport); // 获取当前视口坐标参数
			glSelectBuffer(100, selectBuffer); // 选择名称栈存放被选中的名称
			glRenderMode(GL_SELECT); // 设置当前为 选择模式
			//初始化名称栈
			glInitNames();
			glPushName(0);
			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluPickMatrix(point.x, viewport[3] - point.y, 10, 10, viewport);//创建用于选择的投影矩阵栈
			gluOrtho2D(0, cx, 0, cy);//设置投影方式
			//SendMessage(WM_PAINT, 0, 0);
			m_fivethreeone.Draw(GL_SELECT); // 绘制场景
			glPopMatrix();
			glFlush();
			hits = glRenderMode(GL_RENDER);
			glMatrixMode(GL_MODELVIEW);
			if (hits > 0) m_fivethreeone.ID = selectBuffer[3];
			//m_fivethreeone.processHits(hits, selectBuffer);
			InvalidateRect(NULL, FALSE);
		}
		else {
			m_fivethreeone.ID = -1;
			m_fivethreeone.Start = m_fivethreeone.Change = false;
			if (m_fivethreeone.flag) {
				m_fivethreeone.Pt.clear();
				m_fivethreeone.flag = false;
				Move_x = Move_y = Move_z = 0;
			}
			m_fivethreeone.Pt.push_back(Point(point.x, cy - point.y));
			InvalidateRect(NULL, FALSE);
		}
		break;
	case 19: 
		m_fivethreetwo.mouseisdown = true; m_fivethreetwo.loopr = false; InvalidateRect(NULL, FALSE); KillTimer(19); break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		m_sixthree.loopr = false;
		InvalidateRect(NULL, FALSE); KillTimer(22); break;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CGraphics_WorkView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//m_MouseDownPoint = CPoint(0, 0);
	ReleaseCapture();
	m_fivethreeone.ID = -1;
	if (Case == 18 && m_fivethreeone.Start) {
		m_fivethreeone.Change = false; glRenderMode(GL_RENDER); 
		m_fivethreeone.Draw(GL_RENDER);  InvalidateRect(NULL, FALSE);
	}
	if (Case == 19) {
		m_fivethreetwo.mouseisdown = false; InvalidateRect(NULL, FALSE);
	}
	if (Case == 0 && Stack_top > 0) {
		switch (Draw_Operator[Stack_top - 1]) {
		case 1:
			m_draw.Line_Pt.push_back(m_line);
			m_line.Line.clear();
			mark_line[(int)mark_line.size() - 1] = (int)m_draw.Line_Pt.size();
			break;
		case 2:
			m_draw.Triangle_Pt.push_back(m_triangle);
			m_triangle.Triangle.clear();
			mark_triangle[(int)mark_triangle.size() - 1] = (int)m_draw.Triangle_Pt.size();
			break;
		case 3:
			m_draw.Rectangle_Pt.push_back(m_rectangle);
			m_rectangle.Rectangle.clear();
			mark_rectangle[(int)mark_rectangle.size() - 1] = (int)m_draw.Rectangle_Pt.size();
			break;
		case 4:
			m_draw.Cycle_Pt.push_back(m_cycle);
			m_cycle.Cycle.clear();
			mark_cycle[(int)mark_cycle.size() - 1] = (int)m_draw.Cycle_Pt.size();
			break;
		case 5:
			m_draw.FreeLine_Pt.push_back(m_freeline);
			m_freeline.FreeLine.clear();
			mark_freeline[(int)mark_freeline.size() - 1] = (int)m_draw.FreeLine_Pt.size();
			break;
		case 6:
			m_draw.Eraser_Pt.push_back(m_eraser);
			m_eraser.EraserLine.clear();
			mark_eraser[(int)mark_eraser.size() - 1] = (int)m_draw.Eraser_Pt.size();
			break;
		}	
	}
	if (Case == 15) {
		m_fourthree.NewLine = false;
	}
 	CView::OnLButtonUp(nFlags, point);
}


void CGraphics_WorkView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CRect rc; GetWindowRect(&rc);
	int cx = rc.Width(); int cy = rc.Height();

	//实时显示鼠标坐标
	/*CDC *pDc;
	pDc = GetDC();
	static CString str;
	str.Format(_T("x:%d  y:%d"), point.x, cy - point.y);
	pDc->DrawText(str, CRect(2, 2, 100, 100), DT_SINGLELINE);*/
	int top;
	if (GetCapture() == this && Case == 0 && Stack_top > 0) {

		// IDC_ICON 隐形 系统自定义图标
		/*HCURSOR hCur = LoadCursor(NULL, IDC_SIZE);
		::SetCursor(hCur);*/

		HCURSOR hCur1 = LoadCursor(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDC_CURSOR1));
		HCURSOR hCur2 = LoadCursor(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDC_CURSOR2));
		switch (Draw_Operator[Stack_top - 1]) {
		case 1:
			::SetCursor(hCur1);
			top = (int)m_line.Line.size();
			if (top <= 1) {
				m_line.Line.push_back(Color_Point(point.x, cy - point.y, m_line.R, m_line.G, m_line.B));
			}
			else {
				m_line.Line[top - 1] = Color_Point(point.x, cy - point.y, m_line.R, m_line.G, m_line.B);
			}
			InvalidateRect(NULL, FALSE);
			break;
		case 2:
			::SetCursor(hCur1);
			top = (int)m_triangle.Triangle.size();
			if (top <= 1) {
				m_triangle.Triangle.push_back(Color_Point(point.x, cy - point.y, m_triangle.R, m_triangle.G, m_triangle.B));
			}
			else {
				m_triangle.Triangle[top - 1] = Color_Point(point.x, cy - point.y, m_triangle.R, m_triangle.G, m_triangle.B);
			}
			InvalidateRect(NULL, FALSE);
			break;
		case 3:
			::SetCursor(hCur1);
			top = (int)m_rectangle.Rectangle.size();
			if (top <= 1) {
				m_rectangle.Rectangle.push_back(Color_Point(point.x, cy - point.y, m_rectangle.R, m_rectangle.G, m_rectangle.B));
			}
			else {
				m_rectangle.Rectangle[top - 1] = Color_Point(point.x, cy - point.y, m_rectangle.R, m_rectangle.G, m_rectangle.B);
			}
			InvalidateRect(NULL, FALSE);
			break;
		case 4:
			::SetCursor(hCur1);
			top = (int)m_cycle.Cycle.size();
			if (top <= 1) {
				m_cycle.Cycle.push_back(Color_Point(point.x, cy - point.y, m_cycle.R, m_cycle.G, m_cycle.B));
			}
			else {
				m_cycle.Cycle[top - 1] = Color_Point(point.x, cy - point.y, m_cycle.R, m_cycle.G, m_cycle.B);
			}
			InvalidateRect(NULL, FALSE);
			break;
		case 5:
			::SetCursor(hCur1);
			m_freeline.FreeLine.push_back(Color_Point(point.x, cy - point.y, m_freeline.R, m_freeline.G, m_freeline.B));
			InvalidateRect(NULL, FALSE); 
			break;
		case 6:
			::SetCursor(hCur2);
			m_eraser.EraserLine.push_back(Point(point.x, cy - point.y));
			SendMessage(WM_PAINT);
			break;
		}
		return;
	}
	if (GetCapture() == this) {
		switch (Case) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break; 
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			if (m_fivethreeone.Change) {
				if (m_fivethreeone.ID == -1) break;
				m_fivethreeone.Pt[m_fivethreeone.ID].x = point.x;
				m_fivethreeone.Pt[m_fivethreeone.ID].y = cy - point.y;
				SendMessage(WM_PAINT, 0, 0);
			}
			break;
		case 19:
			if (m_fivethreetwo.mouseisdown == true) {
				m_fivethreetwo.ry += point.x - m_fivethreetwo.mx;
				m_fivethreetwo.rx += point.y - m_fivethreetwo.my;
				m_fivethreetwo.mx = point.x;
				m_fivethreetwo.my = point.y;
				InvalidateRect(NULL, FALSE);
			}
			break;
		case 20:
			break;
		case 21:
			break;
		case 22:
			break;
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CGraphics_WorkView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	// SetCapture();
	/*if (Case == 0) {
		if (!Draw_Operator.empty()) {
			switch (Draw_Operator.top()) {
			case 1:
				break;
			}
		}
		return;
	}*/
	switch (Case) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10: // -10
		m_threetwo.Right = true;
		m_threetwo.Left = false;
		SetTimer(-10, 1, NULL);
		InvalidateRect(NULL, FALSE);
		break;
	case 11: // -11
		m_threethreeone.Right = true;
		m_threethreeone.Left = false;
		SetTimer(-11, 1, NULL);
		InvalidateRect(NULL, FALSE);
		break;
	case 12: // 1 2 3
		KillTimer(1); KillTimer(3); 
		if (m_threethreetwo.flag[2]) return;
		m_threethreetwo.flag[1] = m_threethreetwo.flag[2] = m_threethreetwo.flag[3] = false;
		//m_threethreetwo.r[1] = m_threethreetwo.r[2] = m_threethreetwo.r[3] = 0;
		m_threethreetwo.flag[2] = true;
		SetTimer(2, 1, NULL);
		InvalidateRect(NULL, FALSE);
		break;
	case 13:
		m_fourone.Cut = true;
		InvalidateRect(NULL, FALSE);
		break;
	case 14:
		m_fourtwo.Cut = true;
		InvalidateRect(NULL, FALSE);
		break;
	case 15:
		m_fourthree.Right = true;
		m_fourthree.Left = m_fourthree.Middle = false;
		InvalidateRect(NULL, FALSE);
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		m_fivethreeone.ID = -1;
		if (m_fivethreeone.Start) {
			m_fivethreeone.Start = m_fivethreeone.Change = false; m_fivethreeone.flag = true; m_fivethreeone.Pt.clear();
			Move_x = Move_y = Move_z = 0;
		}
		else {
			m_fivethreeone.Start = m_fivethreeone.Change = false; m_fivethreeone.flag = true; 
		}
		InvalidateRect(NULL, FALSE); break;
	case 19:
		m_fivethreetwo.loopr = true; SetTimer(19, 1, NULL); InvalidateRect(NULL, FALSE);
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		m_sixthree.loopr = true; InvalidateRect(NULL, FALSE);
		break;
	}
	CView::OnRButtonDown(nFlags, point);
}


void CGraphics_WorkView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	// ReleaseCapture();
	m_fivethreeone.ID = -1;
	CView::OnRButtonUp(nFlags, point);
}


void CGraphics_WorkView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	switch (Case) {
	case 1: 
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		if (m_threetwo.Left == true && nIDEvent == 10) {
			m_threetwo.rtri += 6;
			InvalidateRect(NULL, FALSE);
			SetTimer(10, 1, NULL);
		}
		if (m_threetwo.Right == true && nIDEvent == -10) {
			m_threetwo.rtri -= 6;
			InvalidateRect(NULL, FALSE);
			SetTimer(-10, 1, NULL);
		}
		break;
	case 11:
		if (m_threethreeone.Left == true && nIDEvent == 11) {
			m_threethreeone.Angle_earth_to_sun += PI / 360;
			TPoint NewAngle = { m_threethreeone.Angle_earth_to_sun, 0, 0 };
			m_threethreeone.earth = m_threethreeone.D_sun_to_earth * NewAngle;

			m_threethreeone.Angle_moon_to_earth += PI / 90;
			NewAngle = { m_threethreeone.Angle_moon_to_earth, 0, 0 };
			m_threethreeone.moon = m_threethreeone.D_moon_to_earth * NewAngle + m_threethreeone.earth;
			m_threethreeone.Angle += 1;
			InvalidateRect(NULL, FALSE);
			SetTimer(11, 1, NULL);
		}
		if (m_threethreeone.Right == true && nIDEvent == -11) {
			m_threethreeone.Angle_earth_to_sun -= PI / 360;
			TPoint NewAngle = { m_threethreeone.Angle_earth_to_sun, 0, 0 };
			m_threethreeone.earth = m_threethreeone.D_sun_to_earth * NewAngle;

			m_threethreeone.Angle_moon_to_earth -= PI / 90;
			NewAngle = { m_threethreeone.Angle_moon_to_earth, 0, 0 };
			m_threethreeone.moon = m_threethreeone.D_moon_to_earth * NewAngle + m_threethreeone.earth;
			m_threethreeone.Angle += 1;
			InvalidateRect(NULL, FALSE);
			SetTimer(-11, 1, NULL);
		}
		break;
	case 12: // 1 2 3
		m_threethreetwo.r[nIDEvent] += 5; InvalidateRect(NULL, FALSE);
		if (m_threethreetwo.flag[nIDEvent]) {
			SetTimer(nIDEvent, 1, NULL);
		}
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		m_fivethreetwo.ry -= 1; InvalidateRect(NULL, FALSE);
		if (m_fivethreetwo.loopr) {
			SetTimer(nIDEvent, 1, NULL);
		}
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		m_sixthree.roangles += 6.0; InvalidateRect(NULL, FALSE); SetTimer(22, 1, NULL); break;
	}

	CView::OnTimer(nIDEvent);
}


void CGraphics_WorkView::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	// SetCapture();
	switch (Case) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		ClearNow();
		InvalidateRect(NULL, FALSE);
		break;
	case 11:
		ClearNow();
		InvalidateRect(NULL, FALSE);
	case 12:
		KillTimer(1); KillTimer(2);
		if (m_threethreetwo.flag[3]) return;
		m_threethreetwo.flag[1] = m_threethreetwo.flag[2] = m_threethreetwo.flag[3] = false;
		//m_threethreetwo.r[1] = m_threethreetwo.r[2] = m_threethreetwo.r[3] = 0;
		m_threethreetwo.flag[3] = true;
		SetTimer(3, 1, NULL);
		InvalidateRect(NULL, FALSE);
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		m_fourthree.Middle = true;
		m_fourthree.Left = m_fourthree.Right = false;
		InvalidateRect(NULL, FALSE);
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		m_fivethreeone.ID = -1; m_fivethreeone.Start = true; break;
	case 19:
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		break;
	}
	CView::OnMButtonDown(nFlags, point);
}


void CGraphics_WorkView::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	// ReleaseCapture();
	m_fivethreeone.ID = -1;
	CView::OnMButtonUp(nFlags, point);
}


void CGraphics_WorkView::Clear() // 清空其它图形学实验的设置
{
	for (int i = 1; i <= 22; i++) {
		if (Case == i) 
			continue; 
		switch (i) {
		case 1: 
			break;
		case 2: 
			break;
		case 3:
			break;
		case 4: 
			break;
		case 5:
			break;
		case 6: 
			break;
		case 7: 
			start = false; break;
		case 8: 
			break;
		case 9: 
			break;
		case 10:
			KillTimer(10); KillTimer(-10); m_threetwo.rtri = 1; m_threetwo.Left = m_threetwo.Right = false; break;
		case 11: 
			KillTimer(11); KillTimer(-11); 
			m_threethreeone.D_sun_to_earth = { 35, 0, 0 }, m_threethreeone.D_moon_to_earth = { 15, 0, 0 };
			m_threethreeone.sun = { 0, 0, 0 }, m_threethreeone.earth = { 35, 0, 0 }, m_threethreeone.moon = { 50, 0, 0 };
			m_threethreeone.Left = m_threethreeone.Right = false;
			m_threethreeone.Angle_earth_to_sun = 0; // 地球绕太阳的公转角度
			m_threethreeone.Angle_moon_to_earth = 0; // 月亮绕地球的公转角度
			m_threethreeone.Angle = 10; // 自转角度
			break;
		case 12:
			KillTimer(1); KillTimer(2); KillTimer(3);
			m_threethreetwo.Left = m_threethreetwo.Right = false;
			m_threethreetwo.flag[1] = m_threethreetwo.flag[2] = m_threethreetwo.flag[3] = false;
			m_threethreetwo.r[1] = m_threethreetwo.r[2] = m_threethreetwo.r[3] = 0;
			break;
		case 13: 
			m_fourone.Cut = false; break;
		case 14: 
			m_fourtwo.Cut = false; break;
		case 15: 
			m_fourthree.Left = m_fourthree.Right = m_fourthree.Middle = false; 
			m_fourthree.NewLine = false;  m_fourthree.Id = 0; m_fourthree.G.clear(); break;
		case 16: 
			m_fiveone.flag = false; m_fiveone.Pt.clear(); break;
		case 17: 
			m_fivetwo.flag = false; m_fivetwo.Pt.clear(); break;
		case 18: 
			m_fivethreeone.flag = true; m_fivethreeone.Start = false; m_fivethreeone.Change = false; 
			m_fivethreeone.ID = -1; m_fivethreeone.Pt.clear();  break;
		case 19: 
			m_fivethreetwo.mouseisdown = false; m_fivethreetwo.loopr = false; KillTimer(19);
			m_fivethreetwo.mx = 0, m_fivethreetwo.my = 0; m_fivethreetwo.ry = 30; m_fivethreetwo.rx = 30;
			break;
		case 20: 
			break;
		case 21: 
			break;
		case 22: 
			m_sixthree.loopr = true; m_sixthree.mouseisdown = false; m_sixthree.roangles = 45; KillTimer(22); break;
		}
	}
}

void CGraphics_WorkView::Draw_Clear() // 清空 前面所保留的图案
{
	while (!m_redo.Stack.empty()) {
		m_redo.Stack.pop();
	}
	m_draw.Line_Pt.clear();
	m_line.Line.clear();

	m_draw.Triangle_Pt.clear();
	m_triangle.Triangle.clear();
	
	m_draw.Rectangle_Pt.clear();
	m_rectangle.Rectangle.clear();

	m_draw.Cycle_Pt.clear();
	m_cycle.Cycle.clear();

	m_draw.FreeLine_Pt.clear();
	m_freeline.FreeLine.clear();

	m_draw.Eraser_Pt.clear();
	m_eraser.EraserLine.clear();

	mark_line.clear();
	mark_rectangle.clear();
	mark_cycle.clear();
	mark_freeline.clear();
	mark_eraser.clear();
	if (Stack_top - 1 >= 0) {
		Draw_Operator[0] = Draw_Operator[Stack_top - 1];
		Stack_top = 1; //清空 不可以 清空选择操作，只保留最后一个
		switch (Draw_Operator[0]) {
		case 1:
			mark_line.push_back(0);
			break;
		case 5:
			mark_freeline.push_back(0);
			break;
		case 6:
			mark_eraser.push_back(0);
			break;
		}
	}
}


void CGraphics_WorkView::OnDrawClear()
{
	// TODO:  在此添加命令处理程序代码
	Draw_Clear();
	InvalidateRect(NULL, FALSE);
}


vector<Point> ::iterator it;

// bool mark_Operator[10000];

void CGraphics_WorkView::OnUpdo() // 两种撤销操作 可选择
{
	// TODO:  在此添加命令处理程序代码
	
	//第一种：撤销操作 可以撤销图形 和 选择操作
	/*int N;
	if (Stack_top > 0) {
		switch (Draw_Operator[Stack_top - 1]) {
		case 1:
			N = (int)m_draw.Line_Pt.size();
			if (N > 0) {
				m_redo.Stack.push(REDO(1, 0, m_draw.Line_Pt[N - 1], m_freeline, 0, 0, 0));
				m_draw.Line_Pt.pop_back();
			} 
			else {
				m_redo.Stack.push(REDO(0, 1, Color_Point(0, 0, 0, 0, 0), m_freeline, 0, 0, 0));
				Stack_top--;
			}
			break;
		case 2:
			N = (int)m_draw.Triangle_Pt.size();
			if (N > 0) {
				m_redo.Stack.push(REDO(2, 0, m_draw.Triangle_Pt[N - 1], m_freeline, 0, 0, 0));
				m_draw.Triangle_Pt.pop_back();
			}
			else {
				m_redo.Stack.push(REDO(0, 2, Color_Point(0, 0, 0, 0, 0), m_freeline, 0, 0, 0));
				Stack_top--;
			}
			break;
		case 3:
			N = (int)m_draw.Rectangle_Pt.size();
			if (N > 0) {
				m_redo.Stack.push(REDO(3, 0, m_draw.Rectangle_Pt[N - 1], m_freeline, 0, 0, 0));
				m_draw.Rectangle_Pt.pop_back();
			}
			else {
				m_redo.Stack.push(REDO(0, 3, Color_Point(0, 0, 0, 0, 0), m_freeline, 0, 0, 0));
				Stack_top--;
			}
			break;
		case 4:
			N = (int)m_draw.Cycle_Pt.size();
			if (N > 0) {
				m_redo.Stack.push(REDO(4, 0, m_draw.Cycle_Pt[N - 1], m_freeline, 0, 0, 0));
				m_draw.Cycle_Pt.pop_back();
			}
			else {
				m_redo.Stack.push(REDO(0, 4, Color_Point(0, 0, 0, 0, 0), m_freeline, 0, 0, 0));
				Stack_top--;
			}
			break;
		case 5:
			N = (int)m_freeline.FreeLine.size();
			if (N == 0) {
				int M = (int)m_draw.FreeLine_Pt.size();
				if (M == 0) {
					m_redo.Stack.push(REDO(0, 5, Color_Point(0, 0, 0, 0, 0), m_freeline, 0, 0, 0));
					Stack_top--;
				}
				else {
					m_redo.Stack.push(REDO(5, 0, Color_Point(0, 0, 0, 0, 0), m_draw.FreeLine_Pt[M - 1], 0, 0, 0));
					m_draw.FreeLine_Pt.pop_back(); 
				}
			}
			else {
				m_redo.Stack.push(REDO(5, 0, Color_Point(0, 0, 0, 0, 0), m_freeline, 0, 0, 0));
				m_freeline.FreeLine.clear();
			}
			break;
		}
	}*/
	// 撤销操作只对图形有用，不能撤销选择操作
	bool IsDo = false;
	int N, ID;
	for (int i = Stack_top - 1; i >= 0 && !IsDo; i--) {
		// if (mark_Operator[i]) continue;
		ID = mark_id[i]; // 标记当前的操作 位于vector里面的 序号
		switch (Draw_Operator[i]) {
		case 1:
			N = (int)m_draw.Line_Pt.size();
			if (N > 0) {
				if (ID >= 0) {
					int l, r = mark_line[ID];
					if (ID == 0) {
						l = 0;
					}
					else {
						l = mark_line[ID - 1];
					}
					for (int j = r - 1; j >= l; j--) {
						m_redo.Stack.push(REDO(1, i, m_draw.Line_Pt[j], m_triangle, m_rectangle, m_cycle, 
							m_freeline, m_eraser, 0, 0, 0));
						m_draw.Line_Pt.pop_back();
						--mark_line[ID];
						if (l + 1 == r) {
							mark_line[ID] = 0;
						}
						IsDo = true; break;
					}
				}
			}
			break;
		case 2:
			N = (int)m_draw.Triangle_Pt.size();
			if (N > 0) {
				if (ID >= 0) {
					int l, r = mark_triangle[ID];
					if (ID) {
						l = mark_triangle[ID - 1];
					}
					else {
						l = 0;
					}
					for (int j = r - 1; j >= l; j--) {
						m_redo.Stack.push(REDO(2, i, m_line, m_draw.Triangle_Pt[j], m_rectangle, m_cycle,
							m_freeline, m_eraser, 0, 0, 0));
						m_draw.Triangle_Pt.pop_back();
						--mark_triangle[ID];
						if (l + 1 == r) {
							mark_triangle[ID] = 0;
						}
						IsDo = true; break;
					}
				}	
			}
			break;
		case 3:
			N = (int)m_draw.Rectangle_Pt.size();
			if (N > 0) {
				if (ID >= 0) {
					int l, r = mark_rectangle[ID];
					if (ID) {
						l = mark_rectangle[ID - 1];
					}
					else {
						l = 0;
					}
					for (int j = r - 1; j >= l; j--) {
						m_redo.Stack.push(REDO(3, i, m_line, m_triangle, m_draw.Rectangle_Pt[j], m_cycle, 
							m_freeline, m_eraser, 0, 0, 0));
						m_draw.Rectangle_Pt.pop_back();
						--mark_rectangle[ID];
						if (l + 1 == r) {
							mark_rectangle[ID] = 0;
						}
						IsDo = true; break;
					}
				}
			}
			break;
		case 4:
			N = (int)m_draw.Cycle_Pt.size();
			if (N > 0) {
				if (ID >= 0) {
					int l, r = mark_cycle[ID];
					if (ID == 0) {
						l = 0;
					}
					else {
						l = mark_cycle[ID - 1];
					}
					for (int j = r - 1; j >= l; j--) {
						m_redo.Stack.push(REDO(4, i, m_line, m_triangle, m_rectangle, m_draw.Cycle_Pt[j], 
							m_freeline, m_eraser, 0, 0, 0));
						m_draw.Cycle_Pt.pop_back();
						--mark_cycle[ID];
						if (l + 1 == r) {
							mark_cycle[ID] = 0;
						}
						IsDo = true; break;
					}
				}
			}
			break;
		case 5:
			N = (int)m_draw.FreeLine_Pt.size();
			if (N > 0) {
				if (ID >= 0) {
					int l, r = mark_freeline[ID];
					if (ID > 0) {
						l = mark_freeline[ID - 1];
					}
					else {
						l = 0;
					}
					for (int j = r - 1; j >= l; j--) {
						m_redo.Stack.push(REDO(5, i, m_line, m_triangle, m_rectangle, m_cycle, 
							m_draw.FreeLine_Pt[j], m_eraser, 0, 0, 0));
						m_draw.FreeLine_Pt.pop_back();
						--mark_freeline[ID];
						if (l + 1 == r) {
							mark_freeline[ID] = 0;
						}
						IsDo = true; break;
					}
				}
			}
			
			/*N = (int)m_freeline.FreeLine.size();
			if (N == 0) {
				M = (int)m_draw.FreeLine_Pt.size();
				if (M > 0) {
					m_redo.Stack.push(REDO(5, 0, Color_Point(0, 0, 0, 0, 0), m_draw.FreeLine_Pt[M - 1], m_eraser, 0, 0, 0));
					m_draw.FreeLine_Pt.pop_back();
					IsDo = true; 
				}
			}
			else {
				m_redo.Stack.push(REDO(5, 0, Color_Point(0, 0, 0, 0, 0), m_freeline, m_eraser, 0, 0, 0));
				m_freeline.FreeLine.clear();
				IsDo = true;
			}
			break;*/
		case 6:
			N = (int)m_draw.Eraser_Pt.size();
			if (N > 0) {
				int l, r = mark_eraser[ID];
				if (ID > 0) {
					l = mark_eraser[ID - 1];
				}
				else {
					l = 0;
				}
				for (int j = r - 1; j >= l; j--) {
					m_redo.Stack.push(REDO(6, i, m_line, m_triangle, m_rectangle, m_cycle, 
						m_freeline, m_draw.Eraser_Pt[j], 0, 0, 0));
					m_draw.Eraser_Pt.pop_back(); 
					--mark_eraser[ID];
					if (l + 1 == r) {
						mark_eraser[ID] = 0;
					}
					IsDo = true; break;
				}
			}
			
			/*N = (int)m_eraser.EraserLine.size();
			if (N == 0) {
				M = (int)m_draw.Eraser_Pt.size();
				if (M > 0) {
					m_redo.Stack.push(REDO(6, 0, Color_Point(0, 0, 0, 0, 0), m_freeline, m_draw.Eraser_Pt[M - 1], 0, 0, 0));
					m_draw.Eraser_Pt.pop_back();
					IsDo = true;
				}
			}
			else {
				m_redo.Stack.push(REDO(5, 0, Color_Point(0, 0, 0, 0, 0), m_freeline, m_eraser, 0, 0, 0));
				m_eraser.EraserLine.clear();
				IsDo = true;
			}*/
			break;
		}
	}
	InvalidateRect(NULL, FALSE);
}


void CGraphics_WorkView::OnRedo() // 恢复操作
{
	// TODO:  在此添加命令处理程序代码
	int ID;
	if (!m_redo.Stack.empty()) {
		if (m_redo.Stack.empty()) return;
		ID = mark_id[m_redo.Stack.top().drawoperator];
		switch (m_redo.Stack.top().op) {
		case 0:
			Draw_Operator[Stack_top++] = m_redo.Stack.top().drawoperator; 
			break;
		case 1:
			m_draw.Line_Pt.push_back(m_redo.Stack.top().line); 
			if (mark_line[ID] != 0) {
				mark_line[ID]++;
			}
			else {
				if (ID == 0) {
					mark_line[ID] = 1;
				}
				else {
					mark_line[ID] = mark_line[ID - 1] + 1;
				}
			}
			break;
		case 2:
			m_draw.Triangle_Pt.push_back(m_redo.Stack.top().triangle);
			if (mark_triangle[ID]) {
				mark_triangle[ID]++;
			}
			else {
				if (ID) {
					mark_triangle[ID] = mark_triangle[ID - 1] + 1;
				}
				else {
					mark_triangle[ID] = 1;
				}
			}
			break;
		case 3:
			m_draw.Rectangle_Pt.push_back(m_redo.Stack.top().rectangle); 
			if (mark_rectangle[ID]) {
				mark_rectangle[ID]++;
			}
			else {
				if (ID) {
					mark_rectangle[ID] = mark_rectangle[ID - 1] + 1;
				}
				else {
					mark_rectangle[ID] = 1;
				}
			}
			break;
		case 4:
			m_draw.Cycle_Pt.push_back(m_redo.Stack.top().cycle); 
			if (mark_cycle[ID] == 0) {
				if (ID == 0) {
					mark_cycle[ID] = 1;
				}
				else {
					mark_cycle[ID] = mark_cycle[ID] + 1;
				}
			}
			else {
				mark_cycle[ID]++;
			}
			break;
		case 5:
			m_draw.FreeLine_Pt.push_back(m_redo.Stack.top().freeline); 
			if (mark_freeline[ID] != 0) {
				mark_freeline[ID]++;
			}
			else {
				if (ID > 0) {
					mark_freeline[ID] = mark_freeline[ID - 1] + 1;
				}
				else {
					mark_freeline[ID] = 1;
				}
			}
			break;
		case 6:
			m_draw.Eraser_Pt.push_back(m_redo.Stack.top().eraser); 
			if (mark_eraser[ID] != 0) {
				mark_eraser[ID]++;
			}
			else {
				if (ID > 0) {
					mark_eraser[ID] = mark_eraser[ID - 1] + 1;
				}
				else {
					mark_eraser[ID] = 1;
				}
			}
			break;
		}
		m_redo.Stack.pop();
	}
	InvalidateRect(NULL, FALSE);
}

void CGraphics_WorkView::OnEraser() // 橡皮擦操作
{
	// TODO:  在此添加命令处理程序代码
	if (Case) { // 上一界面是图形学实验 不进行操作
		return;
	}
	mark_eraser.push_back(0);
	mark_id[Stack_top] = (int)mark_eraser.size() - 1;
	Case = 0; Draw_Operator[Stack_top++] = 6; // Operator = 6 
	InvalidateRect(NULL, FALSE);
}

void CGraphics_WorkView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (Case == 0) {
		return;
	}
	else if (Case == 9 || Case == 10 || Case == 11 || Case == 12 || Case == 20 || Case == 21 || Case == 22 || Case == 19 || Case == 20
		|| Case == 21 || Case == 22) {
		switch (nChar) {
		case VK_UP:
			if (Case == 11) {
				Move_z -= 1;
			}
			else {
				if (Case == 20 || Case == 21 || Case == 22) Move_y += 0.5;
				else Move_y += 0.1;
			}
			break;
		case VK_DOWN:
			if (Case == 11) {
				Move_z += 1;
			}
			else {
				if (Case == 20 || Case == 21 || Case == 22) Move_y -= 0.5;
				else Move_y -= 0.1;
			}
			break;
		case VK_LEFT:
			if (Case == 11) {
				Move_x -= 1;
			}
			else {
				if (Case == 20 || Case == 21 || Case == 22) Move_x -= 0.5;
				else Move_x -= 0.1;
			}
			break;
		case VK_RIGHT:
			if (Case == 11) {
				Move_x += 1;
			}
			else {
				if (Case == 20 || Case == 21 || Case == 22) Move_x += 0.5;
				else Move_x += 0.1;
			}
			break;
		case VK_SPACE:
			if (Case == 11) {
				Move_y += 1;
			}
			else {
				if (Case == 20 || Case == 21 || Case == 22) Move_z += 0.5;
				else Move_z += 0.1;
			}
			break;
		case VK_BACK:
			if (Case == 11) {
				Move_y -= 1;
			}
			else {
				if (Case == 20 || Case == 21 || Case == 22) Move_z -= 0.5;
				else Move_z -= 0.1;
			}
			break;
		default:
			MessageBox(_T("请选择正确的按键！"), _T("提示"));
			break;
		}
	}
	else {
		switch (nChar) {
		case VK_UP:
			if (Case == 5 || Case == 6 || Case == 16 || Case == 17 || Case == 18) {
				Move_y += 10;
			}
			else if (Case == 11) {
				Move_y += 1;
			}
			else {
				Move_y += 0.1;
			}
			break;
		case VK_DOWN:
			if (Case == 5 || Case == 6 || Case == 16 || Case == 17 || Case == 18) {
				Move_y -= 10;
			}
			else if (Case == 11) {
				Move_y -= 1;
			}
			else {
				Move_y -= 0.1;
			}
			break;
		case VK_LEFT:
			if (Case == 5 || Case == 6 || Case == 16 || Case == 17 || Case == 18) {
				Move_x -= 10;
			}
			else if (Case == 11) {
				Move_x -= 1;
			}
			else {
				Move_x -= 0.1;
			}
			break;
		case VK_RIGHT:
			if (Case == 5 || Case == 6 || Case == 16 || Case == 17 || Case == 18) {
				Move_x += 10;
			}
			else if (Case == 11) {
				Move_x += 1;
			}
			else {
				Move_x += 0.1;
			}
			break;
		default:
			MessageBox(_T("请选择正确的按键！"), _T("提示"));
			break; 
		}
	}
	InvalidateRect(NULL, FALSE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CGraphics_WorkView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

// 实现组合键
BOOL CGraphics_WorkView::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (Case) return FALSE;
	static bool Ctrl = false;
	if (pMsg->message == WM_KEYDOWN) {
		switch (pMsg->wParam) {
		case 'Z'://Ctrl + Z
			if (Ctrl) {
				OnUpdo(); return TRUE;
			}
			break;
		case 'R':
			if (Ctrl) {
				OnRedo(); return TRUE;
			}
			break;
		case 'A':
			if (Ctrl) {
				OnDrawClear(); return TRUE;
			}
			break;
		case 'E':
			if (Ctrl) {
				OnEraser(); return TRUE;
			}
			break;
		case VK_CONTROL:
			Ctrl = true; return TRUE;
			break;
		default:
			return TRUE;
		}
	}
	if (pMsg->message == WM_KEYUP) {
		switch (pMsg->wParam) {
		case VK_CONTROL:
			Ctrl = false; return TRUE;
		}
	}
	return CView::PreTranslateMessage(pMsg);
}


void CGraphics_WorkView::ClearMove()
{
	Move_x = Move_y = Move_z = 0;
}


void CGraphics_WorkView::ClearNow()
{
	switch (Case) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		case 7: break;
		case 8: break;
		case 9: break;
		case 10:
			KillTimer(10); KillTimer(-10); m_threetwo.rtri = 1; m_threetwo.Left = m_threetwo.Right = false; break;
		case 11:
			KillTimer(11); KillTimer(-11);
			m_threethreeone.D_sun_to_earth = { 35, 0, 0 }, m_threethreeone.D_moon_to_earth = { 15, 0, 0 };
			m_threethreeone.sun = { 0, 0, 0 }, m_threethreeone.earth = { 35, 0, 0 }, m_threethreeone.moon = { 50, 0, 0 };
			m_threethreeone.Left = m_threethreeone.Right = false;
			m_threethreeone.Angle_earth_to_sun = 0; // 地球绕太阳的公转角度
			m_threethreeone.Angle_moon_to_earth = 0; // 月亮绕地球的公转角度
			m_threethreeone.Angle = 10; // 自转角度
			break;
		case 12:
			KillTimer(1); KillTimer(2); KillTimer(3);
			m_threethreetwo.Left = m_threethreetwo.Right = false;
			m_threethreetwo.flag[1] = m_threethreetwo.flag[2] = m_threethreetwo.flag[3] = false;
			m_threethreetwo.r[1] = m_threethreetwo.r[2] = m_threethreetwo.r[3] = 0;
			break;
		case 13: 
			m_fourone.Cut = false; break;
		case 14: 
			m_fourtwo.Cut = false; break;
		case 15:
			m_fourthree.Left = m_fourthree.Right = m_fourthree.Middle = false; m_fourthree.Id = 0; break;
		case 16: 
			m_fiveone.flag = false; m_fiveone.Pt.clear(); break;
		case 17: 
			m_fivetwo.flag = false; m_fivetwo.Pt.clear(); break;
		case 18:
			m_fivethreeone.flag = true; m_fivethreeone.Start = false; m_fivethreeone.Change = false;
			m_fivethreeone.ID = -1; m_fivethreeone.Pt.clear();  break;
		case 19:
			m_fivethreetwo.mouseisdown = false; m_fivethreetwo.loopr = false; KillTimer(19);
			m_fivethreetwo.mx = 0, m_fivethreetwo.my = 0; m_fivethreetwo.ry = 30; m_fivethreetwo.rx = 30;
			break;
		case 20: 
			break;
		case 21: 
			break;
		case 22: 
			m_sixthree.loopr = true; m_sixthree.mouseisdown = false; m_sixthree.roangles = 45; KillTimer(22); break;
	}
}
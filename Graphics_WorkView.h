
// Graphics_WorkView.h : CGraphics_WorkView 类的接口
//

#pragma once

class CGraphics_WorkView : public CView
{
public:
	int Case;
private:
	HGLRC m_hRC;
	CClientDC* m_pDC;
protected: // 仅从序列化创建
	CGraphics_WorkView();
	DECLARE_DYNCREATE(CGraphics_WorkView)

// 特性
public:
	CGraphics_WorkDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CGraphics_WorkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
	bool bSetDCPixelFormat();
	void DrawPicture();
	afx_msg void OnOneOne();
	afx_msg void OnOneTwo();
	afx_msg void OnOneThreeOne();
	afx_msg void OnOneThreeTwo();
	afx_msg void OnTwoOne();
	afx_msg void OnTwoTwo();
	afx_msg void OnThreeOneTwo();
	afx_msg void OnThreeTwo();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnThreeOneOne();
	afx_msg void OnThreeThreeOne();
	afx_msg void OnThreeThreeTwo();
	afx_msg void OnFourOne();
	void Clear();
	afx_msg void OnFourTwo();
	afx_msg void OnFourThree();
	afx_msg void OnFiveOne();
	afx_msg void OnFiveTwo();
	afx_msg void OnFiveThreeOne();
	afx_msg void OnSixOne();
	afx_msg void OnFiveThreeTwo();
	afx_msg void OnSixTwo();
	afx_msg void OnSixThree();
	afx_msg void OnDrawColor();
	afx_msg void OnDrawLine();
	void Draw_Clear();
	afx_msg void OnDrawTriangle();
	afx_msg void OnDrawClear();
	afx_msg void OnDrawRectangle();
	afx_msg void OnDrawCycle();
	afx_msg void OnDrawFreeLine();
	afx_msg void OnUpdo();
	afx_msg void OnRedo();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//void All_x_add(int op);
	void ClearMove();
	void ClearNow();
	afx_msg void OnTwoThree();
	afx_msg void OnEraser();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
#ifndef _DEBUG  // Graphics_WorkView.cpp 中的调试版本
inline CGraphics_WorkDoc* CGraphics_WorkView::GetDocument() const
   { return reinterpret_cast<CGraphics_WorkDoc*>(m_pDocument); }
#endif

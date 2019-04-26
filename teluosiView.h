// teluosiView.h : interface of the CTeluosiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TELUOSIVIEW_H__7E1A7CDA_99A3_42A8_9AB1_83028241EF22__INCLUDED_)
#define AFX_TELUOSIVIEW_H__7E1A7CDA_99A3_42A8_9AB1_83028241EF22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Russia.h"
class CTeluosiView : public CView
{
protected: // create from serialization only
	CTeluosiView();
	DECLARE_DYNCREATE(CTeluosiView)

// Attributes
public:
	CTeluosiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeluosiView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int net;
	//CRussia0 russia0;
	int player;	//几个人
	int view;	//哪种界面
	CRussia russia2;
	CRussia russia;	//俄罗斯类
	bool start;	//开始
	CBitmap fenmian;	//封面
	CBitmap xuanze[4];	//选择三种图形
	int ixuanze; //选择哪一种游戏
	bool m_bPause;	//暂停
	virtual ~CTeluosiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTeluosiView)
	afx_msg void OnMenuStart();
	afx_msg void OnMenuPause();
	afx_msg void OnUpdateMenuPause(CCmdUI* pCmdUI);
	afx_msg void OnView1();
	afx_msg void OnView2();
	afx_msg void OnUpdateView1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateView2(CCmdUI* pCmdUI);
	afx_msg void OnMenuDstart();
	afx_msg void OnMenuTstart();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in teluosiView.cpp
inline CTeluosiDoc* CTeluosiView::GetDocument()
   { return (CTeluosiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TELUOSIVIEW_H__7E1A7CDA_99A3_42A8_9AB1_83028241EF22__INCLUDED_)

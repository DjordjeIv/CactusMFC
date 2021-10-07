
// 16597_Djordje_Ivanovic_Druga_Lab_VezbaView.h : interface of the CMy16597DjordjeIvanovicDrugaLabVezbaView class
//

#pragma once


class CMy16597DjordjeIvanovicDrugaLabVezbaView : public CView
{
protected: // create from serialization only
	CMy16597DjordjeIvanovicDrugaLabVezbaView() noexcept;
	DECLARE_DYNCREATE(CMy16597DjordjeIvanovicDrugaLabVezbaView)

// Attributes
public:
	CMy16597DjordjeIvanovicDrugaLabVezbaDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy16597DjordjeIvanovicDrugaLabVezbaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in 16597_Djordje_Ivanovic_Druga_Lab_VezbaView.cpp
inline CMy16597DjordjeIvanovicDrugaLabVezbaDoc* CMy16597DjordjeIvanovicDrugaLabVezbaView::GetDocument() const
   { return reinterpret_cast<CMy16597DjordjeIvanovicDrugaLabVezbaDoc*>(m_pDocument); }
#endif


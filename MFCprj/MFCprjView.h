
// MFCprjView.h : interface of the CMFCprjView class
//

#pragma once


class CMFCprjView : public CView
{
protected: // create from serialization only
	CMFCprjView();
	DECLARE_DYNCREATE(CMFCprjView)

// Attributes
public:
	CMFCprjDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCprjView();
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
    afx_msg void OnToolsTestoption();
};

#ifndef _DEBUG  // debug version in MFCprjView.cpp
inline CMFCprjDoc* CMFCprjView::GetDocument() const
   { return reinterpret_cast<CMFCprjDoc*>(m_pDocument); }
#endif


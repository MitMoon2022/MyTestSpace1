
// MFCprjView.cpp : implementation of the CMFCprjView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCprj.h"
#endif

#include "MFCprjDoc.h"
#include "MFCprjView.h"
#include "Ctest1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCprjView

IMPLEMENT_DYNCREATE(CMFCprjView, CView)

BEGIN_MESSAGE_MAP(CMFCprjView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
    ON_COMMAND(ID_TOOLS_TESTOPTION, &CMFCprjView::OnToolsTestoption)
END_MESSAGE_MAP()

// CMFCprjView construction/destruction

CMFCprjView::CMFCprjView()
{
	// TODO: add construction code here

}

CMFCprjView::~CMFCprjView()
{
}

BOOL CMFCprjView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCprjView drawing

void CMFCprjView::OnDraw(CDC* /*pDC*/)
{
	CMFCprjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CMFCprjView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCprjView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCprjView diagnostics

#ifdef _DEBUG
void CMFCprjView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCprjView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCprjDoc* CMFCprjView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCprjDoc)));
	return (CMFCprjDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCprjView message handlers


void CMFCprjView::OnToolsTestoption()
{
    // TODO: Add your command handler code here
    Ctest1 dlgtest;
    dlgtest.DoModal();
}

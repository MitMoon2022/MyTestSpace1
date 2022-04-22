#if !defined(AFX_DYNLEDDLG_H__6CB9EDB4_CF28_4E98_B4D1_1127E576600D__INCLUDED_)
#define AFX_DYNLEDDLG_H__6CB9EDB4_CF28_4E98_B4D1_1127E576600D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"
#include "DynamicLED.h"

class CDynLEDDlg : public CDialog
{
public:
	CDynLEDDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDynLEDDlg)
	enum { IDD = IDD_DYNLED_DIALOG };

	CDynamicLED	m_dynLEDRed;
	CDynamicLED	m_dynLEDGreen;
	CDynamicLED	m_dynLEDBlue;
	CDynamicLED	m_dynLEDYellow;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynLEDDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDynLEDDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual void OnOK();
	afx_msg void OnBtnSwitchon();
	afx_msg void OnBtnSwitchoff();
	afx_msg void OnBtnChangeshape();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNLEDDLG_H__6CB9EDB4_CF28_4E98_B4D1_1127E576600D__INCLUDED_)

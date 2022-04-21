
// MFCDialogThreadL51Dlg.h : header file
//

#pragma once

//Step1: Define the thread prototype:
UINT ThreadProcA(LPVOID pParam);
UINT ThreadProcB(LPVOID pParam);




// CMFCDialogThreadL51Dlg dialog
class CMFCDialogThreadL51Dlg : public CDialogEx
{
// Construction
public:
	CMFCDialogThreadL51Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDIALOGTHREADL51_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
};


// MFCDialogThreadDlg.h : header file
//

#pragma once

//Step1: start by definition of a thread process prototype here:
UINT DemoA(LPVOID pParam);

// CMFCDialogThreadDlg dialog
class CMFCDialogThreadDlg : public CDialogEx
{
// Construction
public:
	CMFCDialogThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDIALOGTHREAD_DIALOG };

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
    afx_msg void OnStnClickedOutput2();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButton4();
    afx_msg void OnBnClickedButton5();
    afx_msg void OnBnClickedButton6();
};

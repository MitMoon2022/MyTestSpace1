
// MFC_Dialog1Dlg.h : header file
//

#pragma once


// CMFC_Dialog1Dlg dialog
class CMFC_Dialog1Dlg : public CDialogEx
{
// Construction
public:
	CMFC_Dialog1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_DIALOG1_DIALOG};

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    CString m_text;
};

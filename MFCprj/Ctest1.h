#pragma once


// Ctest1 dialog

class Ctest1 : public CDialog
{
	DECLARE_DYNAMIC(Ctest1)

public:
	Ctest1(CWnd* pParent = NULL);   // standard constructor
	virtual ~Ctest1();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    // input text from the textbox
    CString m_text;
};

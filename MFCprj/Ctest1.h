#pragma once


#define EMPTY_POCKET        'E'
#define FILL_POCKET         'X'
#define INSPECT_POCKET      'P'
#define INSPECT_POCKET_PS   'S'
#define LEADER_POCKET       'L'
#define TRAILER_POCKET      'T'


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
    CString m_ReelMap;
};

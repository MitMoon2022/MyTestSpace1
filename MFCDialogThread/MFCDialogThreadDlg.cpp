
// MFCDialogThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDialogThread.h"
#include "MFCDialogThreadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//For Lesson50 control of CWinThread
//Step1: Declare a CWinThread ptr_object
CWinThread* g_pThreadA;     //instantiate it with a name. remember to null it.
//if you want to suspend and resume or check it.
BOOL g_bRunningA;   //track the thread



//Step2: Create the implement of the thread DemoA
UINT DemoA(LPVOID pParam)
{
    //just like function call:
     for(int m=1; m<=100; m++)
    {
        //SetDlgItemInt(IDC_OUTPUT1,i);
        if(!g_bRunningA) break;
        ::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd,IDC_OUTPUT2,m,false);
        Sleep(100);
    }
    g_pThreadA = NULL;  //Need to null it after complete of the process.
    return 0;
}
//Step (repeated): create another one.
UINT DemoB(LPVOID pParam)   //pParam is currently NULL, as it was pass during AfxBegin(1,NULL).
{
    //just like function call:
     for(int n=100; n>=1; n--)
    {
        //SetDlgItemInt(IDC_OUTPUT1,i);
        ::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd,IDC_OUTPUT3,n,false);
        Sleep(555);
    }

    return 0;
}


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCDialogThreadDlg dialog




CMFCDialogThreadDlg::CMFCDialogThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDialogThreadDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    //L50: step2: null the ptr.
    g_pThreadA = NULL;
    g_bRunningA = FALSE;

}

void CMFCDialogThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDialogThreadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CMFCDialogThreadDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CMFCDialogThreadDlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &CMFCDialogThreadDlg::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &CMFCDialogThreadDlg::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &CMFCDialogThreadDlg::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_BUTTON6, &CMFCDialogThreadDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMFCDialogThreadDlg message handlers

BOOL CMFCDialogThreadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCDialogThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDialogThreadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDialogThreadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDialogThreadDlg::OnBnClickedButton1()
{
    // TODO: Add your control notification handler code here
       for(int i=1; i<=100; i++)
    {
        SetDlgItemInt(IDC_OUTPUT1,i);
        Sleep(200);
    }

}



void CMFCDialogThreadDlg::OnBnClickedButton2()      //Start Thread
{
    // TODO: Add your control notification handler code here
    //Lesson50 - control of CWinThread implement
    if(g_pThreadA == NULL)
    {
        g_pThreadA = AfxBeginThread(DemoA, NULL);
        g_bRunningA = TRUE;
    }
    else
    {
        AfxMessageBox(_T("Thread is already running!"));
    }
}


void CMFCDialogThreadDlg::OnBnClickedButton3()
{
    // TODO: Add your control notification handler code here

    AfxBeginThread(DemoB, NULL);

}


void CMFCDialogThreadDlg::OnBnClickedButton4()  //Suspend
{
    // TODO: Add your control notification handler code here
    if(g_pThreadA == NULL)
    {
        AfxMessageBox(_T("Thread does not exit!"));
    }
    else
    {
        g_pThreadA->SuspendThread();    //Suspend.
    }


}


void CMFCDialogThreadDlg::OnBnClickedButton5()      //Resume.
{
    // TODO: Add your control notification handler code here
    if(g_pThreadA == NULL)
    {
        AfxMessageBox(_T("Thread does not exit!"));
    }
    else
    {
        //g_pThreadA->
        g_pThreadA->ResumeThread(); //Resume.  
    }
}


void CMFCDialogThreadDlg::OnBnClickedButton6()  //EndThread
{
    // TODO: Add your control notification handler code here
    if(g_pThreadA == NULL)
    {
        AfxMessageBox(_T("Thread does not exit!"));
    }
    else
    {
        g_bRunningA = FALSE;
        //g_pThreadA->ResumeThread(); //Resume.  
    }


}

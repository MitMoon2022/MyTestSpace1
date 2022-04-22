
// MFCDialogThreadL51Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDialogThreadL51.h"
#include "MFCDialogThreadL51Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//051,2 VC++ MFC Using Mutex,Semaphone to lock the shared resources
//Step2 where to implement the thread function:
int k = 1;      //share resource - could be any datatype like class, doc.
int total=0;    //share resource

//L52
//CCriticalSection
//CMutex
//CSemahore
//CEvent

//Easiest is CCritialSection
CCriticalSection* g_pCS;    //step1: declare a ptr with datatype CCriticalSection
CMutex* g_pMutex;           //another method.
CSemaphore* g_pSemaphore;   //
CEvent* g_pEvent;


UINT ThreadProcA(LPVOID pParam)
{   
    //Work done by the thread
    // Using CCsection
    //for(int i=1; i<=100000000; i++)
    //{
    //    //Add Lock the shared resources
    //    g_pCS->Lock();
    //    k = k*2;
    //    k = k/2;
    //    total +=k;
    //    //Add Unlock
    //    g_pCS->Unlock();
    //}

    //For Mutex - using singleLock
    //CSingleLock singleLock(g_pMutex);
    // for(int i=1; i<=100000000; i++)
    //{
    //    //Add Lock the shared resources
    //    singleLock.Lock();      //Lock it so no one could access to the shared resources
    //    if(singleLock.IsLocked())
    //    {
    //        k = k*2;
    //        k = k/2;
    //        total +=k;
    //        //Add Unlock
    //        singleLock.Unlock();
    //    }
    //   
    //}

    //For Semaphore
    // CSingleLock singleLock(g_pSemaphore);
    // for(int i=1; i<=100000000; i++)
    //{
    //    //Add Lock the shared resources
    //    singleLock.Lock();      //Lock it so no one could access to the shared resources
    //    if(singleLock.IsLocked())
    //    {
    //        k = k*2;
    //        k = k/2;
    //        total +=k;
    //        //Add Unlock
    //        singleLock.Unlock();
    //    }
    //   
    //}
//-----For CEvent -------------------------------
     CSingleLock singleLock(g_pEvent);
     for(int i=1; i<=100000; i++)
    {
        //Add Lock the shared resources
        singleLock.Lock();      //Lock it so no one could access to the shared resources
        if(singleLock.IsLocked())
        {
            k = k*2;
            k = k/2;
            total +=k;
            //Add Unlock
            singleLock.Unlock();
            g_pEvent->SetEvent();
        }
      
    }//end_for
//------------------------------------------------

    ::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd,IDC_OUTPUT,total,false);
    return 0;
}
UINT ThreadProcB(LPVOID pParam)
{   
    //Work done by the thread
  /*  for(int j=1; j<=100000000; j++)
    {
        g_pCS->Lock();
        k = k*2;
        k = k/2;
        total +=k;
        g_pCS->Unlock();
    }*/

    //For Mutex - using singleLock
    CSingleLock singleLock(g_pMutex);
    for(int j=1; j<=100000000; j++)
    {
       //add your control/Lock
        singleLock.Lock();      //Lock it so no one could access to the shared resources
        if(singleLock.IsLocked())
        {
            k = k*2;
            k = k/2;
            total +=k;
            singleLock.Unlock();    //rem to unlock it.
        }
       
    }

    ::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd,IDC_OUTPUT,total,false);
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


// CMFCDialogThreadL51Dlg dialog




CMFCDialogThreadL51Dlg::CMFCDialogThreadL51Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDialogThreadL51Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

   // g_pCS = new CCriticalSection(); //step2 after declaration. (whenever using new - need to delete it.
    g_pMutex = new CMutex();
    g_pSemaphore = new CSemaphore(1,1);
    g_pEvent = new CEvent(TRUE);
}

CMFCDialogThreadL51Dlg::~CMFCDialogThreadL51Dlg()
{
    //Remember to delete *ptr
    delete g_pCS;
    g_pCS = NULL;

    //for CMutex
    delete g_pMutex;
    g_pMutex = NULL;

    //delete CSemaphore
    delete g_pSemaphore;
    g_pSemaphore =NULL;

    //delete CEvent
    delete g_pEvent;
    g_pEvent = NULL;


}
void CMFCDialogThreadL51Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDialogThreadL51Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CMFCDialogThreadL51Dlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CMFCDialogThreadL51Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCDialogThreadL51Dlg message handlers

BOOL CMFCDialogThreadL51Dlg::OnInitDialog()
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

void CMFCDialogThreadL51Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCDialogThreadL51Dlg::OnPaint()
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
HCURSOR CMFCDialogThreadL51Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDialogThreadL51Dlg::OnBnClickedButton1()
{
    // TODO: Add your control notification handler code here
    AfxBeginThread(ThreadProcA,NULL);

}


void CMFCDialogThreadL51Dlg::OnBnClickedButton2()
{
    // TODO: Add your control notification handler code here
    AfxBeginThread(ThreadProcB,NULL);
}

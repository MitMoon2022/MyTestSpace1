
// MFC_Dialog1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Dialog1.h"
#include "MFC_Dialog1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define Timer1 1    //Timer with 200msec
#define Timer2 2    //Timer with 500msec

// CMFC_Dialog1Dlg dialog




CMFC_Dialog1Dlg::CMFC_Dialog1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_Dialog1Dlg::IDD, pParent)
    , m_text(_T("Hello World!"))
    , m_strTimer1(_T("0"))
    , m_CurrentTime(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    num = 0;
}

void CMFC_Dialog1Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_text);
    DDX_Text(pDX, IDC_STATIC_T1, m_strTimer1);
    DDX_Text(pDX, IDC_CURRENT_TIME, m_CurrentTime);
}

BEGIN_MESSAGE_MAP(CMFC_Dialog1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_TStart1, &CMFC_Dialog1Dlg::OnBnClickedTstart1)
    ON_BN_CLICKED(IDC_TStop1, &CMFC_Dialog1Dlg::OnBnClickedTstop1)
    ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFC_Dialog1Dlg message handlers

BOOL CMFC_Dialog1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_Dialog1Dlg::OnPaint()
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
HCURSOR CMFC_Dialog1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Dialog1Dlg::OnBnClickedTstart1()
{
    // TODO: Add your control notification handler code here
    //SetTimer(Timer1,200,NULL);  //T1

    SetTimer(Timer2,1000,NULL); //T2
}


void CMFC_Dialog1Dlg::OnBnClickedTstop1()
{
    // TODO: Add your control notification handler code here
    KillTimer(1);
    num = 0;
}


void CMFC_Dialog1Dlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default

    if(nIDEvent == Timer1)  //200msec per tick
    {
        //num++;
        m_strTimer1.Format(_T("%d"),num);
        num++;
    }

    if(nIDEvent == Timer2)  //1000 msec per tick
    {
        //num++;
        m_strTimer1.Format(_T("%d"),num);
        num++;
    }
    //-------------------------------------------------------------------
    CTime CurrentTime = CTime::GetCurrentTime();

    int iHours   = CurrentTime.GetHour();
    int iMinutes = CurrentTime.GetMinute();
    int iSeconds = CurrentTime.GetSecond();
    CString strHours, strMinutes, strSeconds;

    if( iHours < 10 )
	strHours.Format(_T("0%d"), iHours);
    else
	strHours.Format(_T("%d"), iHours);

    if( iMinutes < 10 )
	strMinutes.Format(_T("0%d"), iMinutes);
    else
	strMinutes.Format(_T("%d"), iMinutes);

    if( iSeconds < 10 )
	strSeconds.Format(_T("0%d"), iSeconds);
    else
	strSeconds.Format(_T("%d"), iSeconds);

    m_CurrentTime.Format(_T("%s:%s:%s"), strHours, strMinutes, strSeconds);


    //-------------------------------------------------------------------
    UpdateData(FALSE);  //Need there to update the count number
    CDialogEx::OnTimer(nIDEvent);
}

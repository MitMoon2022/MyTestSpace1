#include "stdafx.h"
#include "DynLED.h"
#include "DynLEDDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynLEDDlg dialog

CDynLEDDlg::CDynLEDDlg(CWnd* pParent /*=NULL*/) : CDialog(CDynLEDDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDynLEDDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CDynLEDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynLEDDlg)
	DDX_Control(pDX, IDC_STATIC_LED_RED,	m_dynLEDRed);
	DDX_Control(pDX, IDC_STATIC_LED,		m_dynLEDGreen);
	DDX_Control(pDX, IDC_STATIC_LED_YELLOW, m_dynLEDYellow);
	DDX_Control(pDX, IDC_STATIC_LED_BLUE,	m_dynLEDBlue);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDynLEDDlg, CDialog)
	//{{AFX_MSG_MAP(CDynLEDDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_SWITCHON, OnBtnSwitchon)
	ON_BN_CLICKED(IDC_BTN_SWITCHOFF, OnBtnSwitchoff)
	ON_BN_CLICKED(IDC_BTN_CHANGESHAPE, OnBtnChangeshape)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDynLEDDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd *pWndRed = (CWnd *)GetDlgItem(IDC_STATIC_LED_RED);
	m_dynLEDRed.SetLED(pWndRed,ID_LED_RED,ID_SHAPE_ROUND,500);

	CWnd *pWndGreen = (CWnd *)GetDlgItem(IDC_STATIC_LED);
	m_dynLEDGreen.SetLED(pWndGreen,ID_LED_GREEN,ID_SHAPE_ROUND,500);

	CWnd *pWndYellow = (CWnd *)GetDlgItem(IDC_STATIC_LED_YELLOW);
	m_dynLEDYellow.SetLED(pWndYellow,ID_LED_YELLOW,ID_SHAPE_ROUND,500);

	CWnd *pWndBlue = (CWnd *)GetDlgItem(IDC_STATIC_LED_BLUE);
	m_dynLEDBlue.SetLED(pWndBlue,ID_LED_BLUE, ID_SHAPE_ROUND,200);

	return TRUE;
}

void CDynLEDDlg::OnPaint() 
{
	CDialog::OnPaint();
}

void CDynLEDDlg::OnOK() 
{
	// Change the time interval of the Blue LED from 100 to 1000
	CWnd *pWndBlue = (CWnd *)GetDlgItem(IDC_STATIC_LED_BLUE);
	m_dynLEDBlue.SetLED(pWndBlue,ID_LED_BLUE, ID_SHAPE_ROUND,1000);
}

void CDynLEDDlg::OnBtnChangeshape() 
{
	// Change the shape of the Blue LED from round to square
	CWnd *pWndBlue = (CWnd *)GetDlgItem(IDC_STATIC_LED_BLUE);
	m_dynLEDBlue.SetLED(pWndBlue,ID_LED_BLUE, ID_SHAPE_SQUARE,1000);
}

void CDynLEDDlg::OnBtnSwitchon() 
{
	// Switch ON the Blue LED
	CWnd *pWndBlue = (CWnd *)GetDlgItem(IDC_STATIC_LED_BLUE);
	m_dynLEDBlue.SwitchOn();
}

void CDynLEDDlg::OnBtnSwitchoff() 
{
	// Switch OFF the Blue LED
	CWnd *pWndBlue = (CWnd *)GetDlgItem(IDC_STATIC_LED_BLUE);
	m_dynLEDBlue.SwitchOff();
}	
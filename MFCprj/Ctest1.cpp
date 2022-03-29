// Ctest1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCprj.h"
#include "Ctest1.h"
#include "afxdialogex.h"


// Ctest1 dialog

IMPLEMENT_DYNAMIC(Ctest1, CDialog)

Ctest1::Ctest1(CWnd* pParent /*=NULL*/)
	: CDialog(Ctest1::IDD, pParent)
    , m_text(_T("Please typo your name here."))
{

}

Ctest1::~Ctest1()
{
}

void Ctest1::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_text);
}


BEGIN_MESSAGE_MAP(Ctest1, CDialog)
END_MESSAGE_MAP()


// Ctest1 message handlers

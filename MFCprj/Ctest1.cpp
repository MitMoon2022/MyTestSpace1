// Ctest1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCprj.h"
#include "Ctest1.h"
#include "afxdialogex.h"
#include "afx.h"


// Ctest1 dialog

IMPLEMENT_DYNAMIC(Ctest1, CDialog)

Ctest1::Ctest1(CWnd* pParent /*=NULL*/)
	: CDialog(Ctest1::IDD, pParent)
    , m_text(_T("Please typo your name here."))
    , m_ReelMap("ETabTab")
{
        int iPos = m_ReelMap.ReverseFind(TRAILER_POCKET);
            if (iPos != -1) //return -1 when it cannot found it.
            {
                //Trace("Found No T");
                //m_text = ("Found T at ");
                //_tprintf_s(_T("%s %d.\n"), (LPCTSTR)m_text, howmany);  
                m_text.Format(L"T is at %d",iPos);
                
            }
            else
            {
                //Trace("Found T at %d.", iPos);
                m_text = _T("Found no T.");
            }
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

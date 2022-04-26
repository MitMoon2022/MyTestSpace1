// Ctest1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCprj.h"
#include "Ctest1.h"
#include "afxdialogex.h"
#include "afx.h"

//This is a Single document SDI - then i create/add a new dialog 
// Ctest1 dialog

IMPLEMENT_DYNAMIC(Ctest1, CDialog)

Ctest1::Ctest1(CWnd* pParent /*=NULL*/)
	: CDialog(Ctest1::IDD, pParent)
    , m_text(_T("Please typo your name here."))
    , m_ReelMap("ETabTab")
    , m_letter("01.02.01")
{
        int iPos = m_ReelMap.ReverseFind(TRAILER_POCKET);
        //int ilen = m_ReelMap.GetLength();
            if (iPos != -1) //return -1 when it cannot found it.
            {
                //Trace("Found No T");
                //m_text = ("Found T at ");
                //_tprintf_s(_T("%s %d.\n"), (LPCTSTR)m_text, howmany);  
                m_text.Format(L"T is at %d.\r\n",iPos);         //Windows require line ends to be the combination of \r\n, and not just \n. Add the \r and your lines will break properly.
                
                CString strLen;
                int length = m_ReelMap.GetLength();
                strLen.Format(L"\nm_ReelMap contains %d characters", length);

                m_text.Append(strLen);
                //CString string2("lenght is %d\n", ilen);
               // m_text.Append(string2);


             int nIndex = 16;

             CString csTestVersion;
             csTestVersion.Format(L"%c", 'A' + nIndex - 1);  //csTestVersion
             m_letter += csTestVersion;
             m_text.Append(L"\r\n");
             m_text.Append(m_letter);

                
            }
            else
            {
                //Trace("Found T at %d.", iPos);
                m_text = _T("Found no T.");
            }
    //----------------------------------------------------------------
           


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

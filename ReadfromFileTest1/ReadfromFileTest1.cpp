// ReadfromFileTest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
//#include <atlstr.h>
#include "afx.h"
//#include "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\include\iosfwd"
#include <fstream>

using namespace std;

enum ULTPara {
    ULT_IPWAFER = 0,
    ULT_IPROW = 1,
    ULT_IPCOL = 2,
    ULT_OPWAFER = 3,
    ULT_OPROW = 4,
    ULT_OPCOL = 5,
    ULT_IPSUBID = 6,
    ULT_IPWAFERID = 7,
    MAX_ULTPara,
};
//=========================================
typedef struct _stDieTraceInfo {
    CString csIpWafer;
    CString csOpWafer;
    CString csIpRow;
    CString csIpCol;
    CString csOpRow;
    CString csOpCol;
    CString csIpSubId;
    CString csIpWaferId;
    _stDieTraceInfo() {
        csIpWafer, csOpWafer,
            csIpRow, csIpCol,
            csOpRow, csOpCol, csIpSubId, csIpWaferId = "";
    }

} stDieTraceInfo;

int main()
{
    cout << "Testing Starts!\n";

   // CDieTraceOutputFormat::ReadLineByLine(CString csFile)

    CString csFile = _T("D:\\Trace\\DieTrace\\58074CE.txt");

    if (csFile.IsEmpty())
        return false;

    CFileFind finder;

    // File is Found
    if (!finder.FindFile(csFile))
    {
        return false;
    }

    std::vector<stDieTraceInfo> m_vecDieTraceInfo;        //SCT file decode to simple

    m_vecDieTraceInfo.clear();
    std::vector<CString> vecTempSCT;

    fstream sfile;
    sfile.open(csFile);

    CString csFiltered = "";
    CString csTemp = "";
    CString csText = "";
    CString csLineData = "";

    int     iLine = 0;
    int     iTemp = 0;
    std::string line;
    int nMaxULTInfoNo = MAX_ULTPara;// ULT_MAX;
    stDieTraceInfo _stDieTraceInfo;
    m_vecDieTraceInfo.clear();
    while (std::getline(sfile, line))
    {
        iLine++;
        if (iLine < 1 || line == "")
        {
            continue;
        }

        vecTempSCT.clear();
        csFiltered = line.c_str();
        for (int i = 0; i < nMaxULTInfoNo; i++)
        {
            if (csFiltered.IsEmpty())
            {   //resolved "vc/include/xtring Line xxx
                continue;
            }

            csTemp = csFiltered;
#pragma warning(suppress : 4996)
            //line = strtok(csTemp.GetBuffer(), ";");
            char* pch;
            char * pch = strtok(csTemp.GetBuffer(), ";");
            iTemp = line.length() + 1;
            csFiltered = csFiltered.Right(csFiltered.GetLength() - iTemp);

            if (i == ULT_IPWAFER)
            {
                _stDieTraceInfo.csIpWafer = line.c_str();
            }
            if (i == ULT_OPWAFER)
            {
                _stDieTraceInfo.csOpWafer = line.c_str();
            }
            else if (i == ULT_IPROW)
            {
                _stDieTraceInfo.csIpRow = line.c_str();
            }
            else if (i == ULT_IPCOL)
            {
                _stDieTraceInfo.csIpCol = line.c_str();
            }
            else if (i == ULT_OPROW)
            {
                _stDieTraceInfo.csOpRow = line.c_str();
            }
            else if (i == ULT_OPCOL)
            {
                _stDieTraceInfo.csOpCol = line.c_str();
            }
            else if (i == ULT_IPSUBID)
            {
                _stDieTraceInfo.csIpSubId = line.c_str();
                //m_vecDieTraceInfo.push_back(_stDieTraceInfo);
            }
            else if (i == ULT_IPWAFERID)
            {
                _stDieTraceInfo.csIpWaferId = line.c_str();
                m_vecDieTraceInfo.push_back(_stDieTraceInfo);
            }
        }
    }

    sfile.close();
    delete sfile;

    //=============================================================================================
//    CString csFiltered = "";
//    CString csTemp = "";
//    CString csText = "";
//    CString csLineData = "";
//
//    csTemp = ";";
//
//    std::string line;
//
//    //line = strtok(csTemp.GetBuffer(), ";");
//
//    char str[] = "- This, a sample string.";
//    char* pch;
//    printf("Splitting string \"%s\" into tokens:\n", str);
//#pragma warning(suppress : 4996)
//    pch = strtok(str, " ,.-");
//    while (pch != NULL)
//    {
//        printf("%s\n", pch);
//#pragma warning(suppress : 4996)
//        pch = strtok(NULL, " ,.-");
//    }


    return 0;

}


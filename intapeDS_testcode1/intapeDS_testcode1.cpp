// intapeDS_testcode1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlstr.h> //for CString MFC
#include <stdio.h>
#include <iostream>

using namespace std;

bool DecodeIntapeDS(char *cBuffer,double &dResult1,double &dResult2)
{
	CString csBuffer;
    //double dResult1;
    //double dResult2;

    // Truncate end of message
    //csBuffer.Format("%s", cBuffer);
    csBuffer.Format(_T("%s"), cBuffer);

    CString csSubField = "";
   /* if (iSize < 1)
    {
        return false;
    }*/

	if (strstr(cBuffer, "M0") != NULL)
    {
		char *token1 = NULL;
		char *temp = &cBuffer[0];
		temp = cBuffer;
        cout<<"cBuffer is : "<<cBuffer<<endl;
		temp += 3;
        token1 = strtok(temp, ",");

        cout<<"1st time - token 1 is "<<token1<<endl;

		//M0,+12345678,-12345678
        for (int iCount = 0; iCount < 2; iCount++)
        {
			if (token1 != NULL)
            {
                if (iCount == 0)
                {
					dResult1 = atof(token1);
                }
                else if (iCount == 1)
                {
					dResult2 = atof(token1);
                }
              
				token1 = strtok(NULL, ",");
                if (token1 == NULL)
                {
					//SetEvent(m_hResultReady);
                    break;
                }
            }
		}
	}
    return true;
}



int _tmain(int argc, _TCHAR* argv[])
{
    double dResult1;
    double dResult2;

    char m_cReceiveData[] = "M0,+000000968,+000000046";
    bool Done = DecodeIntapeDS(m_cReceiveData, dResult1, dResult2);
    cout<<"Result 1 is "<<dResult1<<endl;
    cout<<"Result 2 is "<<dResult2<<endl;


	return 0;
}


// test3Win32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
//#include <syncop.h>
//#include <WinBase.h>


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
    cout<<"Start of program"<<endl;
    //------------------------------------------------------------------------------
    //Local variables defined
    bool m_bReelNoAck = false;
    bool bBoxNoReceived = false;
    int count = 0;

            while (!bBoxNoReceived)
            {
                cout<<"SendSecsGemEvent(RequestBoxNoEvent)\n";

                int timeLimit = 60000; //in msec
                while (timeLimit > 0)
                {
                    cout<<"timeLimit is now: "<<timeLimit<<endl;
                    Sleep(500);
                    timeLimit -= 500;
                    cout<<"key in:";
                    cin>>count;
                    if (count > 0)   //m_bReelNoAck == TRUE
                    {
                        cout<<"timeLimit breaks\n";
                        m_bReelNoAck = true;
                        break;
                    }

                    cout<<"In timeLimit whileLoop.\n";
                }//end_of_while timeLimit.

                cout<<"In while - bBoxNoReceived\n";

                if (m_bReelNoAck == true)
                {
                     cout<<"Inside ReelNoACK is True.\n";
                    bBoxNoReceived = true;
                    break;
                }

                /*if (AfxMessageBox("Request Box No Timeout. Ensure Box No. is Generated in Mamtstsi. Retry?", MB_YESNO | MB_SYSTEMMODAL) != IDYES)
                {
                    break;
                }*/
            }//end_while

            cout<<"Out of the WhileLoop\n";
  

    cout<<"TheEnd"<<endl;
    system("pause");
    return 0;
}


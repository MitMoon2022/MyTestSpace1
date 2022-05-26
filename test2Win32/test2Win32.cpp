// test2Win32.cpp : Defines the entry point for the console application.
//
// Taken from RunARC

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "KeyValue.h"   //user-defined

using namespace std;

enum ARC_RECEIVED_CMD
{
    RECEIVED_ALARM,
    RECEIVED_REELBARCODE,
    RECEIVED_REELLABEL,
    RECEIVED_LOAD,
    RECEIVED_UNLOAD,
    MAX_RECEIVED_CMD,
};

const string m_ArrMSGfromARC[MAX_RECEIVED_CMD]=
{
    "ALARM",
    "REELBARCODE",
    "REELLABEL",
    "LOAD",
    "UNLOAD",
};

void ReceiveMsg(string &msg)
{
    CKeyValue keyValue;
    std::vector<std::string> vecToken;
    vecToken = keyValue.split(msg,';');

    string      m_strReelBarcode;

    cout<<"ReceiveMsg : "<<msg<<endl;

    if (vecToken[0] == m_ArrMSGfromARC[RECEIVED_ALARM])
    {
        //CallJam(E6603_ARC_ALARM_STATE);
        cout<<"CallJam(E6603_ARC_ALARM_STATE)"<<endl;

        if (vecToken.size()>=2)
        {
            string msg = const_cast<char *>(vecToken[1].c_str());
            //GUIEventLog((LPSTR)msg);
            //CMessageBox box(msg);
            //box.DoModal();
            cout<<msg<<endl;
        }
    }
    else if (vecToken[0] == m_ArrMSGfromARC[RECEIVED_REELBARCODE])
    {
        CKeyValue keyValue;
        std::vector<std::string> vecToken;
        vecToken = keyValue.split(msg,';');

        cout<<vecToken[0]<<endl;

        if (vecToken.size()>=2)
        {
           // m_LocalSharedVariables->m_strReelBarcode = vecToken[1];
            m_strReelBarcode = vecToken[1];
            cout<<m_strReelBarcode<<endl;
           // m_evtReelBarcodeReady.Set();
            cout<<"Set EvtReelBarcodeReady\n";
            
        }
    }
    else if (vecToken[0] == m_ArrMSGfromARC[RECEIVED_REELLABEL])
    {
        CKeyValue keyValue;
        std::vector<std::string> vecToken;
        vecToken = keyValue.split(msg,';');

        if (vecToken.size()>=2)
        {
            if (vecToken[1] == "OK")
            {
                cout<<"call return from RECEIVED_REELLABEL\n";
                //return;
            }
        }
        //CallJam(E6606_ARC_REELLABEL_FAIL);
    }
    else if (vecToken[0] == m_ArrMSGfromARC[RECEIVED_LOAD])
    {
        //CSGManagerSingleton::Instance().SendEvent(ARCLoadEmptyReelsEvent);
        cout<<"SendEvent(ARCLoadEmptyReelsEvent) from RECEIVED_LOAD.\n";

    }
    else if (vecToken[0] == m_ArrMSGfromARC[RECEIVED_UNLOAD])
    {
        /*CSGManagerSingleton::Instance().SetVariableValue(ARCGoodReelQtyOfCurrentLot, S2_U4, GetStatus(SVID_GOODREELQTY));
        CSGManagerSingleton::Instance().SetVariableValue(ARCNGReelQtyOfCurrentLot, S2_U4, GetStatus(SVID_NGREELQTY));
        CSGManagerSingleton::Instance().SetVariableValue(ARCUnitQtyOfCurrentReel, S2_U4, GetStatus(SVID_UNITREELQTY));
        CSGManagerSingleton::Instance().SendEvent(ARCUnloadCompletedReelsEvent);*/
    }
    cout<<"End of ReceiveMsg()- Invalid.\n";
    //end_of_function
}
//Gobal variables:
 

int _tmain(int argc, _TCHAR* argv[])
{
    cout<<"Start of program"<<endl;
    //------------------------------------------------------------------------------
    //Local variables defined
    string strRet = "ABC;DFG";
    strRet = "´";
    strRet = "REELBARCODE;12345678";
    strRet = "ALARM;check!";

    strRet = " ´ï";     //real error code from log
    //call function - ReceiveMsg to decode it.
    for(auto count = 0; count <100 ; count++)
    {
        ReceiveMsg(strRet);
    }


    cout<<"TheEnd"<<endl;

    system("pause");
	return 0;
}


// ARCsimulation01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <stdlib.h>
#include <string>
#include <vector>
#include "KeyValue.h"
//#include "ARC_Protocal.h"


using namespace std;

enum CMDtoARC
{
    CMD_START,              //ret: AK/NK
    CMD_STOP,               //ret: AK/NK
    CMD_RESET,              //ret: AK/NK
    CMD_INIT,               //ret: AK/NK
    CMD_STARTLOT,           //Send: STARTLOT;<Lot Number>           //ret: AK/NK
    CMD_ENDLOT,             //ret: AK/NK
    CMD_SWITCHRECIPE,       //Send: SWITCHRECIPE;<Recipe Name>      //ret: AK/NK
    CMD_NEWREEL,            //Send: NEWREEL;<Reel ID>;<Reel Qty>    //ret: AK/NK
    CMD_ENDREEL,            //ret: AK/NK
    CMD_REELBCODEACK,       //Send: REELBARCODEACK;<ReelID>;<Status>     status 0-Grant 1-Reject    //ret:NA
    CMD_STATUS,             //Send: STATUS;<SVID>
    CMD_MAX_ARC
};

const string m_ArrCMDtoARC[] =
{
    "START",            //ret: AK/NK
    "STOP",             //ret: AK/NK
    "RESET",            //ret: AK/NK
    "INITIALIZE",       //ret: AK/NK
    "STARTLOT",         //Send: STARTLOT;<Lot Number>           //ret: AK/NK
    "ENDLOT",           //ret: AK/NK
    "SWITCHRECIPE",     //Send: SWITCHRECIPE;<Recipe Name>      //ret: AK/NK
    "NEWREEL",          //Send: NEWREEL;<Reel ID>;<Reel Qty>    //ret: AK/NK
    "ENDREEL",          //ret: AK/NK
    "REELBARCODEACK",   //Send: REELBARCODEACK;<ReelID>;<Status>     status 0-Grant 1-Reject    //ret:NA
    "STATUS",            //Send: STATUS;<SVID>
};

const string m_ArrGoodRet[] =
{
    "AK",
    "SYSTEMREADY",
    "ALARMSTATE",
    //"REELBARCODE",
    "GOODREELQTY",
    "NGREELQTY",
    "UNIQREELQTY",
};

const string m_ArrBadRet[] =
{
    "NK",
};

enum ARC_RECEIVED_CMD
{
    RECEIVED_ALARM,
    RECEIVED_REELBARCODE,
    RECEIVED_REELLABEL,
    RECEIVED_LOAD,
    RECEIVED_UNLOAD,
    MAX_RECEIVED_CMD,
};

const string m_ArrMSGfromARC[MAX_RECEIVED_CMD] =
{
    "ALARM",
    "REELBARCODE",
    "REELLABEL",
    "LOAD",
    "UNLOAD",
};

enum ARC_STATUS_SVID
{
    SVID_SYSTEMREADY,
    SVID_ALARMSTATE,
    SVID_REELBARCODE,
    SVID_GOODREELQTY,
    SVID_NGREELQTY,
    SVID_UNITREELQTY,
    MAX_STATUS_SVID
};

const string m_ArrStatusSVID[MAX_STATUS_SVID] =
{
    "SYSTEMREADY",
    "ALARMSTATE",
    "REELBARCODE",
    "GOODREELQTY",
    "NGREELQTY",
    "UNITREELQTY",
};


enum SYSTEM_READY_STATUS
{
    STATUS_NOT_READY,
    STATUS_READY,
    STATUS_CHANGING_REEL,
    STATUS_REEL_READY,
};

#define SYSTEM_NO_ALARM "0"
#define SYSTEM_ALARM "1"
//------------------------------------------
/************************************************************************************************
    Send message To Host.
************************************************************************************************/
bool SendCMD(string csMsg, double dwTimeout /*=0*/, bool bWait /*=true*/)
{
    csMsg = csMsg + '\r';
    cout <<"SendCMD>> " << csMsg << endl;
    return true;


    /*if (CNetworkComm::SendMsg(csMsg, dwTimeout, bWait) == TRUE)
    {
        return true;
    }
    else
    {
        AddTraceMessage("Failed to send CMD: %s", csMsg);
        CallJam(E6601_ARC_FAILED_TO_SEND_CMD);
        return false;
    }*/
}

int GetStatus(int nSVID)
{
    //SYSTEM_NOT_READY,
    //SYSTEM_READY,
    //SYSTEM_CHANGING_REEL,
    //SYSTEM_REEL_READY,
    int nStatus = 0;

    string strChkstatus = m_ArrCMDtoARC[CMD_STATUS] + ";" + m_ArrStatusSVID[nSVID];

    if (SendCMD(strChkstatus.c_str(), 100, true))    //added 100msec timeout
    {
        //string strRet = CNetworkComm::GetLastMsg();
        //AddTraceMessage("CNetworkComm::GetLastMsg(): %s", strRet);

        //string strRet2 = m_strLastRet;   //inherited m_strLastRet from parent class
        //AddTraceMessage("inherited m_strLastRet: %s", strRet2);

        //string strRet = "GOODREELQTY;555";
        //string strRet = "NGREELQTY;1234";
        string strRet = "UNITREELQTY;4836";

        CKeyValue keyValue;
        std::vector<std::string> vecToken;
        vecToken = keyValue.split(strRet, ';');

        if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_SYSTEMREADY].c_str()) == 0)
        {
            nStatus = stoi(vecToken[1]);
        }
        //Added SVID_GOODREELQTY, SVID_NGREELQTY, SVID_UNITREELQTY
        if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_GOODREELQTY].c_str()) == 0)
        {
            nStatus = stoi(vecToken[1]);
            //AddTraceMessage("SVID_GOODREELQTY: %d", nStatus);
            printf("SVID_GOODREELQTY: %d.\n", nStatus);
        }
        if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_NGREELQTY].c_str()) == 0)
        {
            nStatus = stoi(vecToken[1]);
            //AddTraceMessage("SVID_NGREELQTY: %d", nStatus);
            printf("SVID_NGREELQTY: %d.\n", nStatus);
        }
        if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_UNITREELQTY].c_str()) == 0)
        {
            nStatus = stoi(vecToken[1]);
            //AddTraceMessage("SVID_UNITREELQTY: %d", nStatus);
            printf("SVID_UNITREELQTY: %d.\n", nStatus);
        }

    }

    return nStatus;
}





int main()
{
    std::cout << "Start of Program!\n";

    printf("RECEIVED_UNLOAD.\n");
   /* int Goodreelqty = GetStatus(SVID_GOODREELQTY);
    cout << "Goodreelqty is " << Goodreelqty << endl;*/

    /*int Ngreelqty = GetStatus(SVID_NGREELQTY);
    cout << "Ngreelqty is " << Ngreelqty << endl;*/

    int Unitreelqty = GetStatus(SVID_UNITREELQTY);
    cout << "Unitreelqty is " << Unitreelqty << endl;

}


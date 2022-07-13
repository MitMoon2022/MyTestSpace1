// ExploreSscanf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atlcomtime.h" //For class COLeDateTime and COLeDateTimeSpan

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    cout << "Start of Program!\n";
    int day, iyear, imonth, hour, minute;
    char weekday[20], month[20], dtm[100];
    char m_sLastTestDate[20];
   
    strcpy(dtm, "Saturday March 25 1989");

    int i = sscanf(dtm, "%s %s %d  %d", weekday, month, &day, &iyear);

    cout << "i-number of variables filled :" << i << endl;

    printf("%s %d, %d = %s\n", month, day, iyear, weekday);
    cout << "=================================================================================\n";
    //Dealing with real example:

    
   /* int  month;
    int  hour;
    int  minute;*/

    strcpy(m_sLastTestDate, "2022.05.24.16.33");
    //printf("%s\n",m_sLastTestDate);
    cout<<m_sLastTestDate<<endl;

    bool bInvalid = false;

    i = sscanf(m_sLastTestDate, "%04d.%02d.%02d.%02d.%02d", &iyear, &imonth, &day, &hour, &minute);
    cout << "i-number of variables filled :" << i << endl;

    if(sscanf(m_sLastTestDate, "%04d.%02d.%02d.%02d.%02d", &iyear, &imonth, &day, &hour, &minute) != 5)
     {
        bInvalid = true;
     }

    if (bInvalid)
     {
        cout<<"Check Component Height Cal Date: Invalid Last-Test Date!"<<endl;
     }
    else
    {
        cout<<"Year: "<<iyear<<endl;
        cout<<"Month: "<<imonth<<endl;
        cout<<"day: "<<day<<endl;
        cout<<"hour: "<<hour<<endl;
        cout<<"Min: "<<minute<<endl;
    }
    //=====================================================================================
   //https://docs.microsoft.com/en-us/cpp/atl-mfc-shared/reference/coledatetime-class?view=msvc-170  
   
    COleDateTime     LastTestDate(iyear, imonth, day, hour, minute, 0);
    if (LastTestDate.m_status == COleDateTime::invalid)
     {
       printf("Check Component Height (COleDateTime): Invalid Last-Test Date!");
       cout<<"return false\n";
     }
    else
    {
        //CString str = LastTestDate.Format(_T("%H:%M:%S %A, %B %d, %Y"));    //16:33:00 Tuesday, May 24, 2022
        CString str = LastTestDate.Format(_T("%H:%M:%S  %d-%m-%Y"));
        cout<<str<<endl;
        //printf("%s\n",str);
    }

    
    COleDateTimeSpan Interval = COleDateTime::GetCurrentTime() - LastTestDate;
    //Checking
    CString str1 = Interval.Format(_T("Total days: %D, hours: %H, mins: %M, secs: %S"));
    cout<<str1<<endl;

    //declare control variables
    int  iDayCondition =0;      //get from the config.ini is 0. Time-Triggered by hour:mins
    char m_sHourOfDesTest[20];



    // Check If No of Days and Destinated Hour is reached
    if(Interval.GetDays() >= iDayCondition)
    {
        // Get the designated Hour of Test
        //GetPrivateProfileString(COMPONENT_HEIGHT, "Time_Hour", "", m_sHourOfDesTest, sizeof(m_sHourOfDesTest), CONFIG_INI);
        strcpy(m_sHourOfDesTest, "01:01");
        i = sscanf(m_sHourOfDesTest, "%02d:%02d", &hour, &minute);
        cout << "i-number of m_sHourOfDesTest filled :" << i << endl;
        if (sscanf(m_sHourOfDesTest, "%02d:%02d", &hour, &minute) != 2)
        {
            //AddTraceMessage("Getting the Hour and Minute Format wrong!");
            cout<<"Getting the Hour and Minute Format wrong!"<<endl;
            sscanf(m_sHourOfDesTest, "%02d%02d", &hour, &minute);
        }

        int curr_hour, curr_min;
        curr_hour = Interval.GetHours();
        curr_min  = Interval.GetMinutes();

        if (curr_hour > hour || ((curr_hour == hour) && (curr_min >  minute)))
        {
            //bTime = true;
            cout<<"bTime is set True - Time Condition Triggered!"<<endl;
        }
    }//end_of_if(Interval)


    system("pause");
	return 0;
}


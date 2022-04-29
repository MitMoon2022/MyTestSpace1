#include <iostream>
#include <cstring>      // for c-style string functions
#include <cctype>       // for character-based functions
//#include <chrono>
#include "stdafx.h"

using namespace std;    

struct MonitorAlarm
{
    int iCurrCount;             //monitor the current Count
    CTime stTimeRecord[10];
    CTime stMinExpire[10];       //expired timing = Start + time limit
};

struct Time {
  int hour;
  int mins;
  int secs;     //in my application case no need to use secs.
};


Time findTimeDifference(Time t1, Time t2){
    
    Time diff;

    if(t2.secs > t1.secs){
        --t1.mins;
        t1.secs += 60;
    }
 
    diff.secs = t1.secs - t2.secs;
    if(t2.mins > t1.mins) {
        --t1.hour;
        t1.mins += 60;
    }
     
    diff.mins = t1.mins-t2.mins;
    diff.hour = t1.hour-t2.hour;
     
    return diff;
}


int main() {
    
    const int m_iMaxCount = 5;
    //new user-defined parameters
   const int m_iUJamCount = 3;  //monitor the Consecutive MJ probe count limit it to 10 counts
   const int m_iUJamTimeL = 2; //in mins limit
   //------------------------------
   bool bEnd = false;
   bool m_bConsvFail;
   int m_iConsvFailCount3D;    

   MonitorAlarm m_Monitor3Dprobe;
   //initilaize;
   m_Monitor3Dprobe.iCurrCount =0;
  // m_Monitor3Dprobe.iMinStartT= 0;
  // m_Monitor3Dprobe.iMinNextT =0;

 

    cout<<"Start of Program"<<endl;

    m_bConsvFail = true;    //Consecutive fail is enabled
    
    while(!bEnd)
   {
    if(m_bConsvFail)
    {

        cout<<"key the Consv Fail Count 3D\n";
        cin>>m_iConsvFailCount3D;

        if(m_iConsvFailCount3D>=m_iMaxCount)    //test iMaxCount is 5.
        {
            cout<<"Reach Max count\n";
            m_Monitor3Dprobe.iCurrCount++;
            cout<<"Monitoring currCount is : "<<m_Monitor3Dprobe.iCurrCount<<endl;
            CTime CurrentTime = CTime::GetCurrentTime();    //get current Time
            //int iHours   = CurrentTime.GetHour();
            //int iMinutes = CurrentTime.GetMinute();
            m_Monitor3Dprobe.stTimeRecord[ m_Monitor3Dprobe.iCurrCount-1] = CTime::GetCurrentTime(); //some time function to get the current time. 

            m_Monitor3Dprobe.stMinExpire[ m_Monitor3Dprobe.iCurrCount-1]= m_Monitor3Dprobe.stTimeRecord[m_Monitor3Dprobe.iCurrCount-1] + CTimeSpan(0, 0, m_iUJamTimeL, 0);    // 1 hour later m_iUJamTimeL;
        }
        //------------------------------------------------------------------------------------------------------------------------
        if( m_Monitor3Dprobe.iCurrCount == m_iUJamCount)    //Must inform user max is 10.
        {
            //check all the time records
            for(int i = 0; i < m_Monitor3Dprobe.iCurrCount; i++)
            {
                cout<<"print out iTime Hour of ["<<i<<"] = "<<m_Monitor3Dprobe.stTimeRecord[i].GetHour()<<endl;
                cout<<"print out iTime Mins of ["<<i<<"] = "<<m_Monitor3Dprobe.stTimeRecord[i].GetMinute()<<endl;
                cout<<"\n";
                cout<<"print out iMiEXp Hour of["<<i<<"] ="<<m_Monitor3Dprobe.stMinExpire[i].GetHour()<<endl;
                cout<<"print out iMiEXp Mins of["<<i<<"] ="<<m_Monitor3Dprobe.stMinExpire[i].GetMinute()<<endl;
                cout<<"\n";
            
            //Time Limit check
                CTime tLastOne = m_Monitor3Dprobe.stTimeRecord[m_Monitor3Dprobe.iCurrCount-1];  //LastCount Timing which trigger 
                
                CTimeSpan tspan = tLastOne - m_Monitor3Dprobe.stTimeRecord[i];             // Subtract 2 CTimes
                long min = tspan.GetMinutes();
                cout<<"print out time minute interval is "<<min<<endl;
            
                if(min > m_iUJamTimeL)
                {
                    //clear the array Time elapsed is greater than the monitor Time.
                    cout<<"Time expired\n";
                    m_Monitor3Dprobe.stTimeRecord[i] = NULL;

                }else
                {
                    //Both conditions Jam Count reached and Time limit are fulfilled.
                    //output: AfxMessageBox("Jam Count and time limit reached!", MB_OK | MB_SYSTEMMODAL);
                    //if (m_pDoc->GetUserLevel() > LOGIN_OPERATOR) to reset.
                    cout<<"Print out - Jam Count and time limit hit! "<<endl;

                }
            
            }



            bEnd =true; //end the whileLoop
        }


           // if(m_Monitor3Dprobe.iCurrCount ==1)
           // {
           //     //start saving the time of the 1st trigger.
           //     m_Monitor3Dprobe.iTimeRecord[0] = 10; 
           //     m_Monitor3Dprobe.iMinExpire = m_Monitor3Dprobe.iTimeRecord[0] + m_iUJamTimeL;
           // }
           // else if(m_Monitor3Dprobe.iCurrCount ==2){
           //     //saving the 2nd time trigger
           //     m_Monitor3Dprobe.iTimeRecord[m_Monitor3Dprobe.iCurrCount-1] = 15;

           //}

        
        
        
        
        


    }//end_ifConsvFail

    }//end_whileLoop
    system("pause");
    return 0;
}

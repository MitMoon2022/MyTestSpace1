#include <iostream>
#include <cstring>      // for c-style string functions
#include <cctype>       // for character-based functions
#include <vector>       //make use of vector
//#include <chrono>
#include "stdafx.h"

using namespace std;    

struct MonitorAlarm
{
    int iCurrCount;             //monitor the current Count
    vector<CTime> stTimeRecord;      //CTime stTimeRecord[10];
    vector<CTime> stMinExpire;      //CTime stMinExpire[10];       //expired timing = Start + time limit
};

struct Time {
  int hour;
  int mins;
  int secs;     //in my application case no need to use secs.
};

/**********************
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
****************/
bool MonitorCheckTime(MonitorAlarm &RejTimeCheck, int iTimeLimit)
{
     CTime tLastOne = RejTimeCheck.stTimeRecord.back();     //*gets the timing of the Lastone.
  //check all the time records
  for(int i = 0; i < RejTimeCheck.iCurrCount; i++)
 {
      cout<<"print out iTime Hour of ["<<i<<"] = "<<RejTimeCheck.stTimeRecord[i].GetHour()<<endl;
      cout<<"print out iTime Mins of ["<<i<<"] = "<<RejTimeCheck.stTimeRecord[i].GetMinute()<<endl;
      cout<<"\n";
      cout<<"print out iMiEXp Hour of["<<i<<"] ="<<RejTimeCheck.stMinExpire[i].GetHour()<<endl;
      cout<<"print out iMiEXp Mins of["<<i<<"] ="<<RejTimeCheck.stMinExpire[i].GetMinute()<<endl;
      cout<<"\n";
      //---------------------------------------------------------------------------
      
     //Time Limit check
    
     CTimeSpan tspan = tLastOne - RejTimeCheck.stTimeRecord[i];             // Subtract 2 CTimes
     long min = tspan.GetMinutes();

     //Special Case:
     if(i == RejTimeCheck.stTimeRecord.size()-1)
     {
         cout<<"Last count - Now the count i = "<<i<<endl;
         cout<<"Clear all the vector records - StTimeRecord and stMinExpire"<<endl;
         RejTimeCheck.stTimeRecord.clear();
         RejTimeCheck.stMinExpire.clear();
         break;
     }

       if(min >= iTimeLimit)
        {
         //clear the array Time elapsed is greater than the monitor Time.
         cout<<"Time expired. min is more than the TimeLimit\n";
         //RejTimeCheck.stTimeRecord.erase(RejTimeCheck.stTimeRecord.begin()+i);                      //v.erase(v.begin()+6);

         //int sizeOfVect = m_Monitor3Dprobe.stTimeRecord.size();
         //cout<<"Currently the size of the Vector is "<<sizeOfVect<<endl;
         if (i >= RejTimeCheck.stTimeRecord.size()-1) //check that it reaches the last element then clear all.
         {
          //clear the all elements in vectors.
          cout<<"Clear all the vector records - StTimeRecord and stMinExpire"<<endl;
          RejTimeCheck.stTimeRecord.clear();
          RejTimeCheck.stMinExpire.clear();
         }
         continue;                                       //return false;

        }else  //lesser than the time limit
           {
                    //Both conditions Jam Count reached and Time limit are fulfilled.
                    //output: AfxMessageBox("Jam Count and time limit reached!", MB_OK | MB_SYSTEMMODAL);
                    //if (m_pDoc->GetUserLevel() > LOGIN_OPERATOR) to reset.

                    cout<<"Print out - Jam Count and time limit hit! "<<endl;
                    //vector<int>::iterator it = i;
                   /* int j = i;
                    while(j<RejTimeCheck.stTimeRecord.size()-1)
                    {
                        RejTimeCheck.stTimeRecord[j] = RejTimeCheck.stTimeRecord[j+1];
                        RejTimeCheck.stMinExpire[j] = RejTimeCheck.stMinExpire[j+1];
                        j++;
                        cout<<"Transfer completed!\n";
                    }*/
                    //RejTimeCheck.stTimeRecord.pop_back();   //remove the TimeRecord last element.
                    //RejTimeCheck.stMinExpire.pop_back();    //remove the MinExpire last element.
                    //transfer the last element will become the first element.
                    RejTimeCheck.stTimeRecord.erase(RejTimeCheck.stTimeRecord.begin(),RejTimeCheck.stTimeRecord.end()-1);
                    RejTimeCheck.stMinExpire.erase(RejTimeCheck.stMinExpire.begin(), RejTimeCheck.stMinExpire.end()-1);
                    cout<<"Now the size of RejTimeCheck is "<<RejTimeCheck.stTimeRecord.size()<<endl;
                    return true;
             }

           
 }//end_of_forLoop
  return false;
}//MonitorCheckTime() End 


int main() {
    
    const int m_iMaxCount = 5;
    //new user-defined parameters
   const int m_iUJamCount = 3;  //monitor the Consecutive MJ probe count limit it to 10 counts
   const int m_iUJamTimeL = 1; //in mins limit
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
    bool bTriggerMonitor = false;

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
            //m_Monitor3Dprobe.stTimeRecord[ m_Monitor3Dprobe.iCurrCount-1] = CTime::GetCurrentTime(); //some time function to get the current time. 
            m_Monitor3Dprobe.stTimeRecord.push_back(CTime::GetCurrentTime());
            m_Monitor3Dprobe.stMinExpire.push_back(m_Monitor3Dprobe.stTimeRecord.back() + CTimeSpan(0,0,m_iUJamTimeL,0));
             
            //m_Monitor3Dprobe.stTimeRecord[m_Monitor3Dprobe.iCurrCount]= CTime::GetCurrentTime();

            //m_Monitor3Dprobe.stMinExpire[ m_Monitor3Dprobe.iCurrCount-1]= m_Monitor3Dprobe.stTimeRecord[m_Monitor3Dprobe.iCurrCount-1] + CTimeSpan(0, 0, m_iUJamTimeL, 0);    // 1 hour later m_iUJamTimeL;
            //CTime TimeTemp = m_Monitor3Dprobe.stTimeRecord[m_Monitor3Dprobe.iCurrCount] + CTimeSpan(0, 0, m_iUJamTimeL, 0);
            //CTime TimeTemp = m_Monitor3Dprobe.stTimeRecord.back() + CTimeSpan(0, 0, m_iUJamTimeL, 0);
            //m_Monitor3Dprobe.stMinExpire.push_back(TimeTemp);
           
            //m_Monitor3Dprobe.stMinExpire[m_Monitor3Dprobe.iCurrCount] = TimeTemp;
            
        }
    //------------------------------------------------------------------------------------------------------------------------
        if( m_Monitor3Dprobe.iCurrCount == m_iUJamCount)    //Must inform user max is 10.
        {
            bTriggerMonitor = MonitorCheckTime(m_Monitor3Dprobe, m_iUJamTimeL);

        }//end_if_hit the jamcount


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

        if(bTriggerMonitor)
        {
            cout<<"TriggerMonitor - True!\n";
            bEnd =true; //end the whileLoop
            m_Monitor3Dprobe.iCurrCount =0;     //reset count
            break;
        }else
        {
            cout<<"TiggerMonitor - False!\n";
            if(m_Monitor3Dprobe.iCurrCount == m_iUJamCount)
            {
                 m_Monitor3Dprobe.iCurrCount =0;     //reset count
                 /*vector <CTime>::iterator it1;
                 it1 = m_Monitor3Dprobe.stTimeRecord.begin();

                 for(int j = 0 ; j < m_Monitor3Dprobe.stTimeRecord.size(); j++)
                 {
                     if(CTime::GetCurrentTime() > m_Monitor3Dprobe.stMinExpire[j])
                     {
                         m_Monitor3Dprobe.stTimeRecord.erase(it1);
                         m_Monitor3Dprobe.stMinExpire.erase(it1);
                     }
                     it1++;
                 }*/

                 m_Monitor3Dprobe.stTimeRecord.erase(m_Monitor3Dprobe.stTimeRecord.begin(),m_Monitor3Dprobe.stTimeRecord.end()-1);
                 m_Monitor3Dprobe.stMinExpire.erase(m_Monitor3Dprobe.stMinExpire.begin(), m_Monitor3Dprobe.stMinExpire.end()-1);
                 cout<<"Now the size of RejTimeCheck is "<<m_Monitor3Dprobe.stTimeRecord.size()<<endl;


            }//end_if
        }


    }//end_ifConsvFail

    }//end_whileLoop
    system("pause");
    return 0;
}

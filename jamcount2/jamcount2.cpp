// jamcount2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstring>      // for c-style string functions
#include <cctype>       // for character-based functions
#include <vector>       //make use of vector
#include <iomanip>
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

/*
bool MonitorCheckTime(MonitorAlarm &RejTimeCheck, int iTimeLimit)
{
   CTime tLastOne = RejTimeCheck.stTimeRecord.back();
  //check all the time records
  for(int i = 0; i < RejTimeCheck.stTimeRecord.size(); i++)
 {
     //Time Limit check
     CTimeSpan tspan = tLastOne - RejTimeCheck.stTimeRecord[i];             // Subtract 2 CTimes
     long min = tspan.GetMinutes();

    if(min < iTimeLimit) //lesser than the time limit
      {
         //RejTimeCheck.stTimeRecord.erase(RejTimeCheck.stTimeRecord.begin(),RejTimeCheck.stTimeRecord.end()-1);
         //RejTimeCheck.stMinExpire.erase(RejTimeCheck.stMinExpire.begin(), RejTimeCheck.stMinExpire.end()-1);
       return true;
      }      
  }//end_of_for
  return false;
}
*/
//-------------Modify from the top or Simply it Original Erase all to the last element--
bool MonitorCheckTime(vector<int> &RejTime, int iTimeLimit)
{
   //CTime tLastOne = RejTimeCheck.stTimeRecord.back();
    int iLastOne = RejTime.back();

  //check all the time records
  for(int i = 0; i < RejTime.size()-1; i++)
 {
     //Time Limit check
     int tspan = iLastOne - RejTime[i];             // Subtract 2 CTimes
     //long min = tspan.GetMinutes();
     cout<<tspan<<endl;
    if(tspan < iTimeLimit) //lesser than the time limit
      {
          cout<<"At [i] is: "<<i<<endl;
         //RejTimeCheck.stTimeRecord.erase(RejTimeCheck.stTimeRecord.begin(),RejTimeCheck.stTimeRecord.end()-1);
         //RejTimeCheck.stMinExpire.erase(RejTimeCheck.stMinExpire.begin(), RejTimeCheck.stMinExpire.end()-1);
       return true;
      }      
  }//end_of_for
  return false;
}
//----Modidfy version 2 clear/erase until it 1st hit the TimeLimit -------
//--------------------------------------------------------------------
bool MonitorCheckTime2(vector<int> &RejTime, int iTimeLimit)
{
   //CTime tLastOne = RejTimeCheck.stTimeRecord.back();
    int iLastOne = RejTime.back();

  //check all the time records
  for(int i = 0; i < RejTime.size()-1; i++)
 {
     //Time Limit check
     int tspan = iLastOne - RejTime[i];             // Subtract 2 CTimes
     //long min = tspan.GetMinutes();
     cout<<tspan<<endl;
    if(tspan < iTimeLimit) //lesser than the time limit
      {
          cout<<"At [i] is: "<<i<<endl;
          i++;  //stop at i+1;
         RejTime.erase(RejTime.begin(),RejTime.begin()+i);
         //RejTimeCheck.stMinExpire.erase(RejTimeCheck.stMinExpire.begin(), RejTimeCheck.stMinExpire.end()-1);
       return true;
      }      
  }//end_of_for
  return false;
}
//--------------------------------------------------------------------
// Search for the highest count instead of stopping at 1st detect triggered/hit
bool MonitorCheckTime3(vector<int> &RejTime, int iTimeLimit)
{
    int ihitCount = 0;      //store in the highest count which triggered.
   //CTime tLastOne = RejTimeCheck.stTimeRecord.back();
    int iLastOne = RejTime.back();

  //check all the time records
  for(int i = 0; i < RejTime.size()-1; i++)
 {
     //Time Limit check
     int tspan = iLastOne - RejTime[i];             // Subtract 2 CTimes
     //long min = tspan.GetMinutes();
     cout<<tspan<<endl;
    if(tspan < iTimeLimit) //lesser than the time limit
      {
          cout<<"At [i] is: "<<i<<endl;
          ihitCount = i;
          //i++;  //stop at i+1;
         //RejTime.erase(RejTime.begin(),RejTime.begin()+i);
         continue;
       //return true;
      }      
  }//end_of_for

  if(ihitCount > 0)
  {
      cout<<"ihitCount = "<<ihitCount<<endl;
      if(ihitCount == RejTime.size()-1)
      {
          cout<<"Reach the last()-1 count"<<endl;
          //clear until last element to the font();
      }else
      {
         ihitCount++;  //stop at i+1;
         RejTime.erase(RejTime.begin(),RejTime.begin()+ihitCount);
      }
      return true;
  }

  return false;
}
//--------------------------------------------------------------------


void printVtr(const vector<int> &Vtr)
{
    if(Vtr.size() != 0)
    {
      // Printing the Vector
        for (auto it = Vtr.begin(); it != Vtr.end(); ++it)
            cout << *it<<' ';
        cout<<endl;
    }else
        cout<<"The vector is Empty.\n";

}


int main()
{
    cout<<"Start of Program"<<endl;

    int DTimeLimit = 2;    //set the time limit
    vector<int> InTime;

    InTime.push_back(10);
    InTime.push_back(15);
    InTime.push_back(20);
    InTime.push_back(25);
    
    bool CheckFlag = false;

    CheckFlag = MonitorCheckTime(InTime, DTimeLimit);
    std::boolalpha;
    cout<<boolalpha<<CheckFlag<<endl;

   
    if(CheckFlag)
    {
        InTime.erase(InTime.begin(),InTime.end()-1);
        cout<<"Size of InTime is: "<<InTime.size()<<endl;
    }else
    {//meaning all the recorded time has expired so we could erase all.
        InTime.clear();
    }

     //cout<<"Size of InTime is: "<<InTime.size()<<endl;
     printVtr(InTime);
  //--------------------2nd Round -----------------------------------
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"2nd Round of testing."<<endl;
    cout<<"Change the TimeLimit to be 15 and same set of data."<<endl;

    DTimeLimit = 15;    //set the time limit 'x'

    InTime.push_back(10);
    InTime.push_back(15);
    InTime.push_back(20);
    InTime.push_back(25);

    CheckFlag = MonitorCheckTime(InTime, DTimeLimit);
    std::boolalpha;
    cout<<boolalpha<<CheckFlag<<endl;

   
    if(CheckFlag)//when True!
    {
        InTime.erase(InTime.begin(),InTime.end()-1);
        cout<<"Size of InTime is: "<<InTime.size()<<endl;
    }else
    {//meaning all the recorded time has expired so we could erase all.
        InTime.clear();
    }
    
     //cout<<"Size of InTime is: "<<InTime.size()<<endl;
     printVtr(InTime);

     //--------------------3rd Round -----------------------------------
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"3rd Round of testing."<<endl;
    cout<<"Change the TimeLimit to be 15 and same set of data."<<endl;
    cout<<"Change the MonitorCheckTime2 function."<<endl;
    //Erase or remove until the 1st hit timeLimit (inclusive).

    DTimeLimit = 15;    //set the time limit 'x'

    InTime.clear();     //clear the vector.
    InTime.push_back(10);
    InTime.push_back(15);
    InTime.push_back(20);
    InTime.push_back(25);

    //the vector has been rearranged in the function call MonitorCheckTime2();
    CheckFlag = MonitorCheckTime2(InTime, DTimeLimit);
    std::boolalpha;
    cout<<boolalpha<<CheckFlag<<endl;

    if(CheckFlag)
    {
       cout<<"Size of InTime is: "<<InTime.size()<<endl;
    }else
    {//meaning all the recorded time has expired so we could erase all.
        InTime.clear();
    }
    printVtr(InTime);   //Display the result;
    //--------------------4nd Round -----------------------------------
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"4rd Round of testing."<<endl;
    cout<<"Change the TimeLimit to be 15 and same set of data."<<endl;
    cout<<"Change the MonitorCheckTime3 function."<<endl;
    //Erase or remove until the 1st hit timeLimit (inclusive).

    DTimeLimit = 15;    //set the time limit 'x'

    InTime.clear();     //clear the vector.
    InTime.push_back(10);   //0
    InTime.push_back(15);   //1
    InTime.push_back(20);   //2
    InTime.push_back(25);   //3
    InTime.push_back(7);   //4
    InTime.push_back(26);   //5
    InTime.push_back(12);   //6
    InTime.push_back(32);   //7

    //the vector has been rearranged in the function call MonitorCheckTime2();
    CheckFlag = MonitorCheckTime3(InTime, DTimeLimit);
    std::boolalpha;
    cout<<boolalpha<<CheckFlag<<endl;

    if(CheckFlag)
    {
       cout<<"Size of InTime is: "<<InTime.size()<<endl;
    }else
    {//meaning all the recorded time has expired so we could erase all.
        InTime.clear();
    }
    printVtr(InTime);   //Display the result;

    system("pause");
	return 0;
}


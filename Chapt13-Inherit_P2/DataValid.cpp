/*
Problem :- Write A Program To Check Date Validation (Valid Or Not) .
Logic :- Check All the Month And Days valid or not also Special Condition February Month
And Check for Leap Year Calendar.
This C++ Program To Check Year Is Leap Year Or Not.
*/

#include<iostream>
  using namespace std;
  int main()
   {
    int dd,mm,yy;
    cout<<"Enter date in formate Date Month Year:";
    cin>>dd>>mm>>yy;

      if(yy>0)
       {
         if(mm==1 || mm==3 || mm==5|| mm==7|| mm==8||mm==10||mm==12 && dd>0 && dd<=31)
         cout<<"Date is Valide";
         else
       
          if(mm==4 || mm==6 || mm==9|| mm==11 && dd>0 && dd<=30)
            cout<<"Date is Valid";
         else
            if(mm==2)
               {
               if((yy%400==0 || (yy%100!=0 && yy%4==0)) && dd>0 && dd<=29)
                 cout<<"Date is Valide";
               else if(dd>0 && dd<=28)
                  cout<<"Date is Valid";
               else
                  cout<<"Date is Invalid";
               }
         else
               cout<<"Date is Invalid";
      }
    else
        cout<<"Date is Invalid";
  }
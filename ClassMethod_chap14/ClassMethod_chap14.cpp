// ClassMethod_chap14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Every class automatically contains four standard methods :
//■ the default constructor
//■ the destructor
//■ the copy constructor and B{A};
//■ the assignment. (A = B)
//You can use your own definitions to replace these standard methods.As illustrated by
//the sample class Account, the compiler only uses the pre - defined default constructor if
//no other constructor is available.
//The default constructorand the implicit, minimal version of a destructor were introduced
//earlier.

#include <iostream>
#include "account.h"
#include "DayTime.h"
#include <ctime>    //Functions time(), localtime()

const DayTime& currentTime()            // Returns the
{                                       // present time.
    static DayTime curTime;             // declare a static variable - global
    time_t sec; time(&sec);             // Gets the present time.
    
    // Initializes the struct
#pragma warning(suppress : 4996)
    struct tm* time = localtime(&sec);      // tm with it.

    curTime.setTime(time->tm_hour, time->tm_min,time->tm_sec);
    return curTime;
}


using namespace std;

const DayTime& currentTime();   //The current time

int main()
{
    std::cout << "Start of Program!\n";

    Account acc1;
    acc1.display();

    Account giro("Cheers, Mary", 1234567, -1200.99);
            
    Account depot; // Error: no default constructor
                    // defined.
    giro.display(); // To output
  
    Account temp("Funny, Susy", 7777777, 1000000.0);
    acc1 = temp; // ok: Assignment of    // objects possible.
   
    // Or by the presently available method init():
    //save.init("Lucky, Luke", 7654321, 1000000.0);

   //---------------- For DayTime.h --------------------
    DayTime depart1(11, 11, 11), depart2;

    //Calling methods setTime() and isLess()
    depart2.setTime(12, 0, 0);
    if (depart1.isLess(depart2))
        cout << "\nThe 1st plance takes off earlier" << endl;

    //===============================================================
    DayTime cinema(20, 30);
    cout << "\nThe movie starts at ";
    cinema.print();

    DayTime now(currentTime()); // Copy constructor
    cout << "\nThe current time is ";

    now.print();
    cout << "\nThe movie has ";
    if (cinema.isLess(now))
        cout << "already begun!\n" << endl;
    else
        cout << "not yet begun!\n" << endl;




    return 0;

}


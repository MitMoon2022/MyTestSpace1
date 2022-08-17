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


using namespace std;

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
   


    return 0;

}


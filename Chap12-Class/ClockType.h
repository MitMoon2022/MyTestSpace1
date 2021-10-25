//Chapter 12 - Classes and Data Abstraction

//Example 12-2
//The program listing of the program that defines
//and uses the class clockType

/* 
A member function of a class is called a constant function if its heading contains the reserved
word const at the end. For example, the member functions getTime, printTime, and
equalTime of the class clockType are constant functions. A constant member function
of a class cannot modify the member variables of that class, so these are accessor functions.
One thing that should be remembered about constant member functions is that a constant
member function of a class can only call other constant member functions of that class.
Therefore, you should be careful when you make a member function constant.
*/
#ifndef _CLOCKTYPE_H_
#define _CLOCKTYPE_H_

#include<iostream>

using namespace std;

class clockType
{
public:
    void setTime(int, int, int);
    void getTime(int &, int &, int &) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &) const;

private:
    int hr;
    int min;
    int sec;
};

#endif //_CLOCKTYPE_H_
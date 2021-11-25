#ifndef _personInfo_H_
#define _personInfo_H_

#include <string>
#include <iostream>
#include "personType.h"
#include "dataType.h"

using namespace std;
/*
Composition (aggregation) is another way to relate two classes. In composition (aggregation),
one or more members of a class are objects of another class type.
Composition is a ‘‘has-a’’ relation; for example, ‘‘every person has a date of birth.’’
Example 12-9 in Chapter 12 defined a class called personType. The class personType
stores a person’s first name and last name. Suppose we want to keep track of additional
information for a person, such as a personal ID (e.g., a Social Security number)
and a date of birth. Because every person has a personal ID and a date of birth, we can
define a new class, called personalInfo, in which one of the members is an object of
type personType.We can declare additional members to store the personal ID and date
of birth for the class personalInfo.
First, we define another class, dateType, to store only a person’s date of birth.
Then, we construct the class personalInfo from the classes personType and
dateType. This way, we can demonstrate how to define a new class using two
classes.
To define the class dateType, we need three member variables—to store the
month, day number, and year. Some of the operations that need to be performed on
a date are to set the date and to print the date. The following statements define the
class dateType:
*/
class personalInfo
{
public:
    void setpersonalInfo(string first, string last, int month,
                         int day, int year, int ID);
    // Function to set the personal information.
    // The member variables are set according to the
    // parameters.
    // Postcondition: firstName = first; lastName = last;
    //  dMonth = month; dDay = day;
    //  dYear = year; personID = ID;
    void printpersonalInfo() const;
    // Function to print the personal information.
    personalInfo(string first = "", string last = "",
                 int month = 1, int day = 1, int year = 1900,
                 int ID = 0);
    // Constructor
    // The member variables are set according to the
    // parameters.
    // Postcondition: firstName = first; lastName = last;
    //  dMonth = month; dDay = day;
    //  dYear = year; personID = ID;
    //  If no values are specified, the default
    //  values are used to initialize the member
    //  variables.
private:
    personType name;        //has-a personType class
    dateType bDay;          //has-a dateType class
    int personID;
};
    //---------------------------------------.cpp--------------------------------------
void personalInfo::setpersonalInfo(string first, string last, int month, int day, int year, int ID)
{
    name.setName(first, last);
    bDay.setDate(month, day, year);
    personID = ID;
} void personalInfo::printpersonalInfo() const
{
    name.print();
    cout << "'s date of birth is ";
    bDay.printDate();
    cout << endl;
    cout << "and personal ID is " << personID;
}
personalInfo::personalInfo(string first, string last, int month,
                           int day, int year, int ID)
    : name(first, last), bDay(month, day, year)
{
    personID = ID;
}

#endif //_personInfo_H_
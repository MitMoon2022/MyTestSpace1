#ifndef _dataType_H_
#define _dataType_H_

#include <string>
#include <iostream>
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
class dateType
{
public:
    void setDate(int month, int day, int year);
    // Function to set the date.
    // The member variables dMonth, dDay, and dYear are set
    // according to the parameters.
    // Postcondition: dMonth = month; dDay = day;
    //  dYear = year
    int getDay() const;
    // Function to return the day.
    // Postcondition: The value of dDay is returned.
    int getMonth() const;
    // Function to return the month.
    // Postcondition: The value of dMonth is returned.
    int getYear() const;
    // Function to return the year.
    // Postcondition: The value of dYear is returned.
    void printDate() const;
    // Function to output the date in the form mm-dd-yyyy.
    dateType(int month = 1, int day = 1, int year = 1900);
    // Constructor to set the date
    // The member variables dMonth, dDay, and dYear are set
    // according to the parameters.
    // Postcondition: dMonth = month; dDay = day; dYear = year;
    //  If no values are specified, the default
    //  values are used to initialize the member
    //  variables.
private:
    int dMonth; // variable to store the month
    int dDay;   // variable to store the day
    int dYear;  // variable to store the year
};
//---------------------------------------.cpp--------------------------------------
// The definition of the function setDate, before storing the date into the member
// variables, does not check whether the date is valid. That is, it does not confirm whether
// month is between 1 and 12, year is greater than 0, and day is valid (for example, for
// January, day should be between 1 and 31). In Programming Exercise 2 at the end of this
// chapter, you are asked to rewrite the definition of the function setDate so that the date
// is validated before storing it in the member variables
void dateType::setDate(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}
int dateType::getDay() const
{
    return dDay;
}
int dateType::getMonth() const
{
    return dMonth;
}
int dateType::getYear() const
{
    return dYear;
}
void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}
// Constructor with parameters
dateType::dateType(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}



#endif //_dataType_H_
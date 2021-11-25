/*
Suppose that you want to define a class to group the attributes of an employee. There are
both full-time employees and part-time employees. Part-time employees are paid based on
the number of hours worked and an hourly rate. Suppose that you want to define a class to
keep track of a part-time employee’s information, such as name, pay rate, and hours
worked. You can then print the employee’s name together with his or her wages. Because
every employee is a person and Example 12-9 (Chapter 12) defined the class
personType to store the first name and the last name together with the necessary operations
on name, we can define a class partTimeEmployee based on the class personType.
You can also redefine the print function to print the appropriate information.

Example 13-3 pg 740
*/
#ifndef _partTimeEmp_H_
#define _partTimeEmp_H_

#include <string>
#include <iostream>
#include "personType.h"
using namespace std;



class partTimeEmployee: public personType
{
public:
    void print() const;
    // Function to output the first name, last name, and
    // the wages.
    // Postcondition: Outputs
    //  firstName lastName wages are $$$$.$$
    double calculatePay() const;
    // Function to calculate and return the wages.
    // Postcondition: Pay is calculated and returned
    void setNameRateHours(string first, string last,
                          double rate, double hours);
    // Function to set the first name, last name, payRate,
    // and hoursWorked according to the parameters.
    // Postcondition: firstName = first; lastName = last;
    //  payRate = rate; hoursWorked = hours
    partTimeEmployee(string first = "", string last = "",
                     double rate = 0, double hours = 0);
    // Constructor with parameters
    // Sets the first name, last name, payRate, and hoursWorked
    // according to the parameters. If no value is specified,
    // the default values are assumed.
    // Postcondition: firstName = first; lastName = last;
    //  payRate = rate; hoursWorked = hours
private:
    double payRate;     // variable to store the pay rate
    double hoursWorked; // variable to store the hours worked
};
//----------------------------------------------------------------
void partTimeEmployee::print() const
{
    personType::print(); // print the name of the employee
    cout << "'s wages are: $" << calculatePay() << endl;
}
double partTimeEmployee::calculatePay() const
{
    return (payRate * hoursWorked);
}
void partTimeEmployee::setNameRateHours(string first,
                                        string last, double rate, double hours)
{
    personType::setName(first, last);
    payRate = rate;
    hoursWorked = hours;
}
// Constructor
partTimeEmployee::partTimeEmployee(string first, string last,
                                   double rate, double hours)
    : personType(first, last)
{
    if (rate >= 0)
        payRate = rate;
    else
        payRate = 0;
        
    if (hours >= 0)
        hoursWorked = hours;
    else
        hoursWorked = 0;
}

#endif //_partTimeEmp_H_
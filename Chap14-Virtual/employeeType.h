#include "personType.h"

#pragma once  //Getting redefinition of Class error!

class employeeType : public personType
{
public:
    virtual void print() const = 0;
    // Function to output employee's data.
    virtual double calculatePay() const = 0;
    // Function to calculate and return the wages.
    // Postcondition: Pay is calculated and returned

    //Not virtual Functions:

    void setId(long id);
    // Function to set the salary.
    // Postcondition: personId = id;
    long getId() const;
    // Function to retrieve the id.
    // Postcondition: returns personId
    employeeType(string first = "", string last = "",
                 long id = 0);
    // Constructor with parameters
    // Sets the first name, last name, payRate, and
    // hoursWorked according to the parameters. If
    // no value is specified, the default values are
    // assumed.
    // Postcondition: firstName = first;
    //  lastName = last; personId = id;
private:
    long personId; // stores the id
};
//----------------------implementation----------------------------------
void employeeType::setId(long id)
{
    personId = id;
}
long employeeType::getId() const
{
    return personId;
}
employeeType::employeeType(string first, string last, long id)
    : personType(first, last)
{
    personId = id;
}
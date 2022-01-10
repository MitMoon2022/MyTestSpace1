#include "Person.h"
#include <iostream>     //By right, this lib should be declared in the main.

// constructor
personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}
void personType::print() const
{
    std::cout << firstName << " " << lastName<<endl;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}


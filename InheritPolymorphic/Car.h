#pragma once
// car.h: Definition of baseclass Car and
// of the derived class PassCar
// --------------------------------------------------
#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>
using namespace std;

class Car		//Base class
{
private:
	long nr;
	string producer;
public:
	Car(long n = 0L, const string& prod = "");	//Constructor
	virtual ~Car();										// Virtual destructor

	long getNr(void) const { return nr; }
	void setNr(long n) { nr = n; }

	const string& getProd() const { return producer; }
	void setProd(const string& p) { producer = p; }
	virtual void display(void) const; // Display a car after putting virtual to show polymorphic



};

#endif
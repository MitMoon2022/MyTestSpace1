#pragma once
#include "Car.h"
class PassCar :    public Car		// Derived class
{
private:
	string passCarType;
	bool sunRoof;
public: // Constructor:
	PassCar(const string& tp, bool sd,int n = 0, const string& h = "");
	~PassCar();


	// Access methods:
	const string& getType() const { return passCarType; }
	void setType(const string s) { passCarType = s; }
	bool getSunRoof() const { return sunRoof; }
	void setSunRoof(bool b) { sunRoof = b; }
	void display() const;

};


// ------------------------------------------------------
// car.cpp
// Implements the methods of Car, PassCar, and Truck
// ------------------------------------------------------
#include "car.h"
// ------------------------------------------------------
// The methods of base class Car:

Car::Car(long n, const string& prod)
{
	cout << "Construct an object of type car.\n";
	nr = n;
	producer = prod;
}
Car::~Car()
{
	cout << "Destroying an object of type Car" << endl;
}

void Car::display() const
{
	cout << "\n---------------------------- "
		<< "\nCar number: " << nr
		<< "\nProducer: " << producer
		<< endl;
}
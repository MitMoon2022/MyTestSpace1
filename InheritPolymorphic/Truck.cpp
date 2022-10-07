#include "Truck.h"
//====================================================================
// The methods of the derived class Truck:
Truck::Truck(int a, double t, int n, const string& hs)
	: Car(n, hs),
	axles(a),
	tons(t)
{
	cout << "Create an object of type Truck." << endl;
}
Truck::~Truck()
{
	cout << "\nDestroy an object of type Truck\n";
}
void Truck::display() const
{
	Car::display();
	cout << "Axles: " << axles
		<< "\nCapacity: " << tons << " long tons\n";
}
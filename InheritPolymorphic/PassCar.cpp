#include "PassCar.h"


//Third Version with base class and member initializer
//---------------------------------------------------------
PassCar::PassCar(const string& tp, bool sr, int n, const string& hs)
	:Car(n, hs),
	passCarType(tp),
	sunRoof(sr)
{
	//If there are some variables which involve using functions to initialise.
	//For now, it is done.
	cout << "Create an object of type PassCar." << endl;
}

// The methods of the derived class PassCar:

PassCar::~PassCar()
{
	cout << "\nDestroying an object of type PassCar"
		<< endl;
}

void PassCar::display(void) const
{
	Car::display(); // Method in base class
	cout << "Type: " << passCarType;
	cout << "\nSunroof: ";
	if (sunRoof)
		cout << "yes " << endl;
	else
		cout << "no " << endl;
}
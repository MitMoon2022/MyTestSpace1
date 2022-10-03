// FactoryDP_Nut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ToyFactory.cpp"

using namespace std;

int main()
{
    std::cout << "Start Program!\n";

	// client code starts
	int type;
	while (1) {
		cout << endl << "Enter type or Zero for exit" << endl;
		cin >> type;
		if (!type)
			break;
		Toy* v = ToyFactory::createToy(type);
		if (v) {
			v->showProduct();
			delete v;
		}
	}
	cout << "Exit.." << endl;
	// client code ends
	return 0;


}

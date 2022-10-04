// FactorySimple.cpp : This file contains the 'main' function. Program execution begins and ends there.
// C++ Tutorial: the factory design pattern
// https://www.youtube.com/watch?v=usmdZniV_Yw
// By Professor Hank Stalica

#include <iostream>
#include <string>
#include <vector>
#include "HfactorySimple.h"

using namespace std;

int main()
{
    cout << "Start of Factory Simple from the internet!\n";

	vector <Shape*> shapes;

	// Our factory is responsible for creating Shape objects on demand
	Factory f;

	// Lets create 3 different shape objects and assign their memory addresses to our shapes vector
	shapes.push_back(f.create(TRIANGLE));
	shapes.push_back(f.create(SQUARE));
	shapes.push_back(f.create(CIRCLE));

	// Iterate over each shape object, calling it's getName method using it's pointer
	for (Shape*& s : shapes)
		cout << s->getName() << endl;

	// cleaneup
	for (Shape*& s : shapes)
		delete s;

	shapes.clear();
	return 0;








}



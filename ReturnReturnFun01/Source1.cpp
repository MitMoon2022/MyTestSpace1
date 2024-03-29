// Ref3.cpp Chapt12 References and Pointers
// Demonstrates the use of return values with
// reference type. pg226
// --------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
									// Returns a
double& refMin(double&, double&); 	// reference to
									// the minimum.
//The expression refMin(x1, x2) represents either the object x1 or the object x2, that is, the object
//containing the smaller value.
int main()
{
	double x1 = 1.1, x2 = x1 + 0.5, y;
	y = refMin(x1, x2); 										// Assigns the minimum to y.
	cout << "x1 = " << x1 << " " << "x2 = " << x2 << endl;
	cout << "Minimum: " << y << endl;

	++refMin(x1, x2); 											// ++x1, as x1 is minimal
	cout << "x1 = " << x1 << " " 								// x1 = 2.1
		<< "x2 = " << x2 << endl; 								// x2 = 1.6
	++refMin(x1, x2); 											// ++x2, because x2 is
																// the minimum.
	cout << "x1 = " << x1 << " " 					// x1 = 2.1 
		<< "x2 = " << x2 << endl; 					// x2 = 2.6
	refMin(x1, x2) = 10.1; 							// x1 = 10.1, because
													// x1 is the minimum.
	cout << "x1 = " << x1 << " " 		// x1 = 10.1
		<< "x2 = " << x2 << endl; 		// x2 = 2.6
	refMin(x1, x2) += 5.0; 				// x2 += 5.0, because
										// x2 is the minimum.
	cout << "x1 = " << x1 << " " 		// x1 = 10.1
		<< "x2 = " << x2 << endl; 		// x2 = 7.6

	return 0;
}
double& refMin(double& a, double& b)	// Returns a
{										// reference to
	return a <= b ? a : b;				// the minimum.
}

#include "Singleton.h"
#include <iostream>
#include <corecrt_math.h>

using namespace std;

int main() {
	cout << "Start Program.\n";
	Singleton &s = Singleton::Instance() ;
	s.MethodA() ;

	//Singleton s2 ;
}

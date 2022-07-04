#include "Singleton.h"
#include <iostream>

using namespace std;
Singleton Singleton::m_Instance ;
Singleton& Singleton::Instance() {
	return m_Instance ;
}

void Singleton::MethodA() {

	cout << "MethodA" << endl;
}

void Singleton::MethodB() {
}

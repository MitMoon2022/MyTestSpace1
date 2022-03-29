// projectLset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include <thread>

using namespace std;

void hello(string& s) {
    s = "xyz";
}

int main()
{
    cout << "Hello World!\n";
    //------------------------------
    personType p1("Tom", "Tan");
    p1.print();
    cout<<"First name of the obj-Type PersonType: " << p1.getFirstName() << endl;
    cout<<"Last name of the obj-Type PersonType: " << p1.getLastName() << endl;
    //-----------------------------
    personType p2("Jacky", "Lim");
    p2.print();
    //-----------------------------
    string str{ "abc" };
    thread t{ hello, std::ref(str) };
    t.join();
    cout << "str is now " << str << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// PassStringFNC.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.programiz.com/cpp-programming/strings
//Passing String to a Function
//Strings are passed to a function in a similar way arrays are passed to a function.
//two strings are asked to enter.These are stored in strand str1 respectively, where str is a char arrayand str1 is a string object.
//Then, we have two functions display() that outputs the string onto the string.
//The only difference between the two functions is the parameter.The first display() function takes char array as a parameter, while the second takes string as a parameter.
//This process is known as function overloading.Learn more about Function Overloading.


#include <iostream>
#include <stdlib.h>
#include <string>

//using namespace std::basic_istream;

using namespace std;

void display(char *);
void display(string);

int main()
{
    cout << "Hello World!\n";
    string str1;
    char str[100];

    cout << "Enter a string: ";
    getline(cin, str1);

    cout << "Enter another string: ";
    cin.get(str, 100, '\n');

    display(str1);
    display(str);
    //-----------------------------------------
    // The string member function c_str() will return the string in the form of a char* (with a null-terminator).
    cout << "test of c_str()\n";
    str1.c_str();   //Convert std::string to const char*
    cout << str1;
    cout << "<-Test1 where it is joined\n";

    cout << str1.size() << endl;



    return 0;
}

void display(char s[])
{
    cout << "Entered char array is: " << s << endl;
}

void display(string s)
{
    cout << "Entered string is: " << s << endl;
}
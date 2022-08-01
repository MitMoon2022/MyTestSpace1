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
#include <vector>
#include "KeyValue.h"

//using namespace std::basic_istream;

using namespace std;

enum ARC_STATUS_SVID
{
    SVID_SYSTEMREADY,
    SVID_ALARMSTATE,
    SVID_REELBARCODE,
    SVID_GOODREELQTY,
    SVID_NGREELQTY,
    SVID_UNITREELQTY,
    MAX_STATUS_SVID
};

const string m_ArrStatusSVID[MAX_STATUS_SVID] =
{
    "SYSTEMREADY",
    "ALARMSTATE",
    "REELBARCODE",
    "GOODREELQTY",
    "NGREELQTY",
    "UNITREELQTY",
};



void display(char *);
void display(string);

int main()
{
    //cout << "Hello World!\n";
    //string str1;
    //char str[100];

    //cout << "Enter a string: ";
    //getline(cin, str1);

    //cout << "Enter another string: ";
    //cin.get(str, 100, '\n');

    //display(str1);
    //display(str);
    ////-----------------------------------------
    //// The string member function c_str() will return the string in the form of a char* (with a null-terminator).
    //cout << "test of c_str()\n";
    //str1.c_str();   //Convert std::string to const char*
    //cout << str1;
    //cout << "<-Test1 where it is joined\n";

    //cout << str1.size() << endl;

    //==============================ARC SendCMD============================================
    
    int nStatus = 0;
    string strRet = "GOODREELQTY;555";

    CKeyValue keyValue;
    std::vector<std::string> vecToken;
    vecToken = keyValue.split(strRet, ';');

   /* if (vecToken.size() > 0) {
        for (const auto& item : vecToken) {
            cout << item << "; ";
        }
    }
    cout << endl;*/

    //using strcmp function which compare two strings, return:
    //0	 if strings are equal
    //>0 if the first non-matching character in str1 is greater (in ASCII) than that of str2.
    //<0 if the first non - matching character in str1 is lower(in ASCII) than that of str2.
    if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_SYSTEMREADY].c_str()) == 0)
    {
        nStatus = stoi(vecToken[1]);
    }
    if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_GOODREELQTY].c_str()) == 0)
    {
        nStatus = stoi(vecToken[1]);
    }
    if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_NGREELQTY].c_str()) == 0)
    {
        nStatus = stoi(vecToken[1]);
    }
    if (vecToken.size() >= 2 && strcmp(vecToken[0].c_str(), m_ArrStatusSVID[SVID_UNITREELQTY].c_str()) == 0)
    {
        nStatus = stoi(vecToken[1]);
    }



    cout << "nStatus is " << nStatus << endl;

    string st1 = "Happy";

    string st2 = st1;

    cout << "st2 is " << st2 << endl;


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
// LearnSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.educative.io/answers/what-is-the-stdsort-function-in-cpp
//std::sort() is a built - in function in C++'s Standard Template Library. 
//The function takes in a beginning iterator, an ending iterator, and (by default) sorts the iterable in ascending order.
//The function can also​ be used for custom sorting by passing in a comparator function that returns a boolean.


#include <iostream>
// The following library needs to be included to use std::sort()
#include <algorithm>
// The following library needs to be included to use std::greater<datatype>()
#include <functional>
#include <vector>

using namespace std;

// Custom comparator to sort in descending order
bool comparator(string& a, string& b) {
    return a > b;
}




int main()
{
    cout << "Start Program!\n";
    string coffee[] = { "latte", "cappuccino", "americano", "espresso" };
    int size = sizeof(coffee) / sizeof(coffee[0]);
    //cout << "size is " << size << endl;
    std::sort(coffee, coffee + size);       //by default is ascending order!
    for (int i = 0; i < 4; i++) {
        cout << coffee[i] << endl;
    }
    cout << "======================================================================================\n";
    //===============================================================================================
    //Using a built-in comparator
    std::sort(coffee, coffee + size, std::greater<string>());       //from big to small.
    
    for (int i = 0; i < 4; i++) {
        cout << coffee[i] << endl;
    }
    cout << "======================================================================================\n";
    // Third method using custom comparator.
    string coffee1[] = { "latte", "cappuccino", "americano", "espresso" };
    std::sort(coffee1, coffee1 + 4, comparator);
    for (int i = 0; i < 4; i++) {
        cout << coffee[i] << endl;
    }
    cout << "======================================================================================\n";
    //My example:

    std::vector<string> name{
        "Bala",
        "Mike",
        "Ail",
        "MeePo",
        "Zion",
        "Ken",
        "Jordan"
    };

    //std::sort(begin(name), end(name));  //ascending order

    std::sort(begin(name), end(name), [](string& a, string& b) {
            return a > b;
        }
     );

    std::for_each(begin(name), end(name), [](const string& name) {
        cout << name << endl;
        }
    );




    return 0;
}


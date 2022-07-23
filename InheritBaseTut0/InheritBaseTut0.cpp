// InheritBaseTut0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CShape.h"
#include "CRectangle.h"

int main()
{
    std::cout << "Program Start!\n";

    CShape base;

    base.printName();

    CRectangle rec1;

    rec1.setHeight(2);
    rec1.setWidth(3);

    cout << "Total Area of rec1: " << rec1.getArea() << endl;

    cout << "getHeight: " << rec1.getHeight() << endl;
    cout << "getWidth: " << rec1.getWidth() << endl;


    return 0;
}


#pragma once
//Basic class

#ifndef _CShape_H_
#define _CShape_H_


#include <iostream>
#include <string>

using namespace std;

class CShape
{
public:
    CShape();

    void setWidth(int w);
    void setHeight(int h);

    void printName();

protected:
    int width;
    int height;


private:
    string name;
    int    prv_data{23};    //some private data to simulate


};

#endif  // _CShape_H_
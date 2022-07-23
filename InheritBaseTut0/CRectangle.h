#pragma once
#include "CShape.h"

//Derived Class
class CRectangle :public CShape
{
public:
	CRectangle();

	double getArea();

	int getWidth();
	int getHeight();

private:


};


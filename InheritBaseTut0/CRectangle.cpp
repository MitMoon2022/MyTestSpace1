#include "CRectangle.h"


CRectangle::CRectangle() :CShape()
{
	//default const

}

double CRectangle::getArea()
{
	return (width * height);
}

int CRectangle::getWidth()
{
	return width;
}

int CRectangle::getHeight()
{
	return height;
}
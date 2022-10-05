#pragma once
#include <string>

using namespace std;


class Shape
{
public:
	virtual string getName() = 0;
};

class Triangle : public Shape
{
public:
	string getName() { return "Triangle"; }
};

class Square : public Shape
{
public:
	string getName() { return "Square"; }
};

class Circle : public Shape
{
public:
	string getName() { return "Circle"; }
};

enum Type { TRIANGLE, SQUARE, CIRCLE };


// responsible for creating and returning Shape objects on demand...
class Factory
{
public:
	Shape* create(Type t)  // factory method
	{
		switch (t)
		{
		case TRIANGLE:
			return new Triangle();
		case SQUARE:
			return new Square();
		case CIRCLE:
			return new Circle();
		}
	}
};

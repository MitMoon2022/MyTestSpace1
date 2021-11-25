#include<iostream>

using namespace std;

class boxType : public rectangleType
{
public:
    void setDimension(double l, double w, double h);
    // Function to set the length, width, and height
    // of the box.
    // Postcondition: length = l; width = w; height = h;
    double getHeight() const;
    // Function to return the height of the box.
    // Postcondition: The value of height is returned.
    double area() const;
    // Function to return the surface area of the box.
    // Postcondition: The surface area of the box is
    //  calculated and returned.
     // overide from the parent class
    double volume() const;
    // Function to return the volume of the box.
    // Postcondition: The volume of the box is
    //  calculated and returned.
    void print() const;
    // Function to output the length, width, and height of a box.
    // make use from the parent class - method.
    boxType();
    // Default constructor
    // Postcondition: length = 0; width = 0; height = 0;
    boxType(double l, double w, double h);
    // Constructor with parameters
    // Postcondition: length = l; width = w; height = h;
private:
    double height;
};

//--------------BoxType Implementation--------------------
// To call the member function print of rectangleType(parentClass) in the definition of the
// member function print of boxType, we must use the following statement:
// parentClass::print();
void boxType::print() const
{
    rectangleType::print();
    cout << "; Height = " << height;
}
// Notice the definition of the function setDimension, a call to the
// member function setDimension of the class rectangleType is preceded by the
// name of the class and the scope resolution operator, even though the class boxType
// overloads—not overrides—the function setDimension
void boxType::setDimension(double l, double w, double h)
{
    rectangleType::setDimension(l, w);
    if (h >= 0)
        height = h;
    else
        height = 0;
}

double boxType::getHeight() const
{
    return height;
}
// To determine the surface area of a box, we need to access the length and width of the box,
// which are declared as private members of the class rectangleType. Therefore, we
// use the member functions getLength and getWidth of the class rectangleType to
// retrieve the length and width, respectively.
double boxType::area() const
{
    return 2 * (getLength() * getWidth() 
                + getLength() * height 
                + getWidth() * height);
}
// Make use the member function area of the class rectangleType to determine the area of the
// base. Because the class boxType overrides the member function area, to specify a call
// to the member function area of the class rectangleType, we use the name of the
// base class and the scope resolution operator, as shown in the following definition:
double boxType::volume() const
{
    return rectangleType::area() * height;
}
// Recall that, if a class contains the default constructor and no values are specified when
// the object is declared, the default constructor executes and initializes the object. Because
// the class rectangleType contains the default constructor, when writing the definition
// of the default constructor of the class boxType, we do not specify any constructor
// of the base class.
boxType::boxType()
{
height = 0.0;
}
// write the definitions of constructors with parameters. To trigger
// the execution of a constructor (with parameters) of the base class, you specify the name of
// a constructor of the base class with the parameters in the heading of the definition of the
// constructor of the derived class.
boxType::boxType(double l, double w, double h)
    : rectangleType(l, w)
{
    if (h >= 0)
        height = h;
    else
        height = 0;
}

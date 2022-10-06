// FunctionObj.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.quantstart.com/articles/Function-Objects-Functors-in-C-Part-1/#:~:text=A%20function%20pointer%20allows%20a,%22called%22%20like%20a%20function.

//A function object allows an instance object of a class to be called or invoked as if 
//it were an ordinary function.In C++ this is carried out by overloading operator().
//The main benefit of using function objects is that they are objects and
//hence can contain state, either statically across all instances of 
//the function objects or individually on a particular instance.
//Here is a C++ example of a function object(in fact a function object hierarchy),
//which replaces the function pointer syntax from the version above, with functors :

#include <iostream>


// Abstract base class                                                                                                                                                                                                  
class BinaryFunction {
public:
    BinaryFunction() {};
    virtual double operator() (double left, double right) = 0;
};

// Add two doubles                                                                                                                                                                                                      
class Add : public BinaryFunction {
public:
    Add() {};
    virtual double operator() (double left, double right) { return left + right; }
};

// Multiply two doubles                                                                                                                                                                                                 
class Multiply : public BinaryFunction {
public:
    Multiply() {};
    virtual double operator() (double left, double right) { return left * right; }
};

double binary_op(double left, double right, BinaryFunction* bin_func) {
    return (*bin_func)(left, right);
}

int main()
{
    std::cout << "Start of C++ Function Objects (Functors)!\n";

    double a = 5.0;
    double b = 10.0;

    BinaryFunction* pAdd = new Add();           //declare or create a Function class (object)
    BinaryFunction* pMultiply = new Multiply();

    std::cout << "Add: " << binary_op(a, b, pAdd) << std::endl;
    std::cout << "Multiply: " << binary_op(a, b, pMultiply) << std::endl;

    delete pAdd;
    delete pMultiply;

    return 0;

}


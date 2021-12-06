/*
For classes with pointer member variables, three things are normally done:
1. Include the destructor in the class.
2. Overload the assignment operator for the class.
3. Include the copy constructor.
Chapter 15 discusses overloading the assignment operator. Until then, whenever we
discuss classes with pointer member variables, out of the three items in the previous list,
we will implement only the destructor and the copy constructor.

Start reading from pg 818
Classes and Pointers: Some Peculiarities
Example 14-7 illustrates how to include the copy constructor in a class and how it works.

*/
#ifndef _ptrMemberVarType_H_
#define _ptrMemberVarType_H_

class ptrMemberVarType
{
public:
    void print() const;
    // Function to output the data stored in the array p.
    void insertAt(int index, int num);
    // Function to insert num into the array p at the
    // position specified by index.
    // If index is out of bounds, the program is terminated.
    // If index is within bounds, but greater than the index
    // of the last item in the list, num is added at the end
    // of the list.
    ptrMemberVarType(int size = 10);
    // Constructor
    // Creates an array of the size specified by the
    // parameter size; the default array size is 10.
    ~ptrMemberVarType();
    // Destructor
    // deallocates the memory space occupied by the array p.
    ptrMemberVarType(const ptrMemberVarType &otherObject);
    // Copy constructor
private:
    int maxSize; // variable to store the maximum size of p
    int length;  // variable to store the number elements in p
    int *p;      // pointer to an int array
};

#endif //_ptrMemberVarType_H_
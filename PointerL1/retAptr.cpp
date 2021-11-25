//https://www.geeksforgeeks.org/passing-reference-to-a-pointer-in-c/

#include <iostream>

using namespace std;

int global_var = 11;
int global_var2 = 13;

// function to return a pointer
int* returnPointerValue()
{
    //must be an address for ptr to point to->
    return &global_var; //return an & address of identifier.
}
	
// function to return reference value
int& ReturnReference()
{
    return global_var2;
}



int main()
{
	int var = 23;
	int* ptr_to_var = &var;
     cout <<"Ex1 Returning a pointer from a function "<<endl;

	cout << "Return a pointer from a function " << endl;

	cout << "Before :" << *ptr_to_var << endl; // display 23

	ptr_to_var = returnPointerValue(); //fun that returns a ptr type.

	cout << "After :" << *ptr_to_var << endl; // display 42

    //---Ex2 returning reference from function
    cout <<"Ex2 Returning reference from function "<<endl;

    int var2 = 30;
    int* ptr_to_var2 = &var2;
 
    cout << "Returning a Reference " << endl;
 
    cout << "Before :" << *ptr_to_var2 << endl; // display 30
 
    ptr_to_var2 = &ReturnReference();
 
    cout << "After :" << *ptr_to_var2 << endl; // display 13





	return 0;
}

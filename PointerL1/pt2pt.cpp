/*
Passing “pointer to a pointer” as a parameter to function
by passing the address of the pointer to the function instead of a copy
of the actual function. 
For this, the function parameter should accept a “pointer to pointer”.
*/
//https://www.geeksforgeeks.org/passing-reference-to-a-pointer-in-c/

#include <iostream>

using namespace std;

int global_var = 42;

// function to change pointer to pointer value
void changePointerValue(int** ptr_ptr)
{
	*ptr_ptr = &global_var;
}

// function - Refer to pointer Example2
void fun(int &x) {
    x = 20;
}


int main()
{
	int var = 23;
	int* pointer_to_var = &var;

	cout << "Passing a pointer to a pointer to function " << endl;

	cout << "Before :" << *pointer_to_var << endl; // display 23

	changePointerValue(&pointer_to_var);

	cout << "After :" << *pointer_to_var << endl; // display 42

//---- How to call a function with “Reference to pointer” parameter? 
//A reference allows called function to modify a local variable of the caller
//function. For example, consider the following example program where 
//fun() is able to modify local variable x of main(). 

    int x = 10;
    cout<<"At e start the value of x is "<<x<<endl;
    fun(x);
    cout<<"New value of x is "<<x<<endl;



	return 0;
}

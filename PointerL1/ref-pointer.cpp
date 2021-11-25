// Passing pointer to a function
// If a pointer is passed to a function as a parameter
// and tried to be modified then the changes made
// to the pointer does not reflects back outside that function.
// This is because only a copy of the pointer is passed to the function.
// It can be said that “pass by pointer” is passing a pointer by value.
//https://www.geeksforgeeks.org/passing-reference-to-a-pointer-in-c/

#include <iostream>

using namespace std;

int global_Var = 42;

// function to change pointer value
void changePointerValue(int* pp)
{
  cout<<"inside the function start: "<<*pp<<endl;
  //pp = &global_Var;       //but cannot modified the address of the pointer. (value of the pp)
  *pp = 11; //could only moodified the value of the pointer.

  cout<<"inside the function end: "<<*pp<<endl;
}

int main()
{
	int var = 23;
	int* ptr_to_var = &var;

	cout << "Passing Pointer to function:" << endl;

	cout << "Before :" << *ptr_to_var << endl; // display 23

	changePointerValue(ptr_to_var);

	cout << "After :" << *ptr_to_var << endl; // display 23

	return 0;
}

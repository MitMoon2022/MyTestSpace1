// How to return multiple values from a function in C or C++?
/* 
Below are the methods to return multiple values from a function in C:

By using pointers.
By using structures.
By using Arrays.

https://www.geeksforgeeks.org/how-to-return-multiple-values-from-a-function-in-c-or-cpp/

1. Returning multiple values Using pointers: Pass the argument with their address and make changes
in their value using pointer. So that the values get changed into the original argument.

2. Returning multiple values using structures : As the structure is a user-defined datatype.
The idea is to define a structure with two integer variables and store the greater and smaller values
into those variable, then use the values of that structure.

3. Returning multiple values using an array (Works only when returned items are of same types):
When an array is passed as an argument then its base address is passed to the function so 
whatever changes made to the copy of the array, it is changed in the original array.
Below is the program to return multiple values using array i.e. store greater value at arr[0]
and smaller at arr[1].

*/
//Below showing C++ method.
// Modified program using References in C++ C++ only Methods
//1. Returning multiple values Using References: We use references in C++ to store returned values.
#include <stdio.h>
#include <iostream>
using namespace std;

void compare(int a, int b, int &add_great, int &add_small)
{
	if (a > b) {
		add_great = a;
		add_small = b;
	}
	else {
		add_great = b;
		add_small = a;
	}
}
//-------------------------------------------------------------------------------------
/* 2.Returning multiple values using Class and Object : The idea is similar to structures. 
We create a class with two integer variables and store the greater and smaller values into
those variable, then use the values of that structure.
*/

class GreaterSmaller {
public:
    int greater, smaller;
};
  
GreaterSmaller findGreaterSmaller(int a, int b)
{
    GreaterSmaller s;
    if (a > b) {
        s.greater = a;
        s.smaller = b;
    }
    else {
        s.greater = b;
        s.smaller = a;
    }
  
    return s; //return an object
}

//----------------------------------------------------------------------------------------
/* Returning multiple values using STL tuple : The idea is similar to structures.
We create a tuple with two integer variables and return the tuple, 
and then inside main function we use tie function to assign values to min and max that is returned 
by the function.
*/
#include<tuple>

tuple <int, int> findBigSmall(int a, int b)
{
    if (a < b) {
    return make_tuple(a, b);
    }
    else {
    return make_tuple(b, a);
    }
}
//----------------------------------------------------------------------------------------
/*
Returning multiple values using an array (Works only when returned items are of same types):
When an array is passed as an argument then its base address is passed to the function
so whatever changes made to the copy of the array, it is changed in the original array.
*/
// Store the greater element at 0th index
void findGreaterSmaller(int a, int b, int arr[])
{
  
    // Store the greater element at
    // 0th index of the array
    if (a > b) {
        arr[0] = a;
        arr[1] = b;
    }
    else {
        arr[0] = b;
        arr[1] = a;
    }
}
//----------------------------------------------------------------------------------------
void test1(){

  int great, small, x, y;

	printf("Enter two numbers: \n");
	scanf("%d%d", &x, &y);

	// The last two arguments are passed
	// by giving addresses of memory locations
	compare(x, y, great, small);
	printf("\nThe greater number is %d and the"
		"smaller number is %d",
		great, small);

}
void test2(){
  int x, y;
    GreaterSmaller result;
  
    printf("Enter two numbers: \n");
    scanf("%d%d", &x, &y);
  
    // The last two arguments are passed
    // by giving addresses of memory locations
    result = findGreaterSmaller(x, y);
    printf("\nThe greater number is %d and the"
           "smaller number is %d\n.",result.greater, result.smaller);
}
void test3() {
  int x = 5, y= 8;
  int max, min;
    tie(min, max) = findBigSmall(x, y);
  
    printf("\nThe big number is %d and the "
        "small number is %d",max, min);
}
void test4() {
  int x, y;
    int arr[2];
  
    printf("Enter two numbers: \n");
    scanf("%d%d", &x, &y);
  
    findGreaterSmaller(x, y, arr);
  
    printf("\nThe greater number is %d and the"
           "smaller number is %d",arr[0], arr[1]);
}


// Driver code
int main()
{
	test1();
  cout<<"--------------------------"<<endl;
 //test2();
  cout<<"--------------------------"<<endl;
  test3();
  cout<<"--------------------------"<<endl;
  test4();


	return 0;
}



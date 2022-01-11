// pointer to functions
/* 
C++ allows operations with pointers to functions.
The typical use of this is for passing a function as an argument to another function. 
Pointers to functions are declared with the same syntax as a regular function declaration,
except that the name of the function is enclosed between parentheses () and an asterisk (*)
is inserted before the name: 

https://www.cplusplus.com/doc/tutorial/pointers/
*/



#include <iostream>
using namespace std;

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int main ()
{
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<m<<endl;
  cout <<n<<endl;
  return 0;
}
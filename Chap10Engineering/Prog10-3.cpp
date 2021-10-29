#include <iostream>
using namespace std;


int main()
{
    double total = 20.5; // declare and initialize total
    double& sum = total; // declare another name for total
    cout << "sum = " << sum << endl;

    sum = 18.6; // this changes the value in total
    cout << "total = " << total << endl;
    
    return 0;
}
/*
Because the variable sum is simply another reference to the variable total, the first cout
statement in Program 10.3 displays the value stored in total. Changing the value in sum then
changes the value in total, which the second cout statement in Program 10.3 displays.

When constructing references, keep two points in mind. First, the reference should be of
the same data type as the variable it refers to. For example, this sequence of declarations
int num = 5;

double& numref = num; // INVALID - CAUSES A COMPILER ERROR

doesn’t equate numref to num; rather, it causes a compiler error because the two variables are
of different data types.

Second, a compiler error is produced when an attempt is made to equate a reference to a
constant. For example, the following declaration is invalid:
int& val = 5; // INVALID - CAUSES A COMPILER ERROR

After a reference name has been equated to one variable name correctly, the reference
can’t be changed to refer to another variable.

As with all declaration statements, multiple references can be declared in a single statement,
as long as each reference name is preceded by the ampersand. Therefore, the following
declaration creates two reference variables named sum and average:4
double& sum = total, & average;
*/
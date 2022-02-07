// ConsoleIsWithTol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
//-----------------------------------------------------------------
template<class TYPE>
bool IsWithinTol(TYPE Offset, TYPE Tol)
{
    if (Offset > Tol || Offset < -Tol)
    {
        return false;
    }

    return true;
}
//---------------------------------
template<class TYPE>
void CapValue(TYPE& Value, TYPE Min, TYPE Max)
{
    Value = (std::min)(Value, Max);
    Value = (std::max)(Value, Min);
}





int main()
{
    cout << "Hello World!\n";
    cout << myMax<int>(3, 7) << endl;  // Call myMax for int
    //------------------------------------
    // get absolute value of -5.5
    double dvalue = -5.5;
    cout << fabs(dvalue);

    //---------------------Testing with variables------------------
    double m_dCumuMvDist = 7.5;
    double m_dPocketPitch = 8.0;
    double dTolerance = m_dPocketPitch * 2.0; // max 2 pocket pitch 
    cout << std::boolalpha<<endl;



    bool result = IsWithinTol(m_dCumuMvDist, dTolerance);

    cout << result<<endl;
    cout << "---------------------------------" << endl;
    double dTemp = -2.0;
    dTemp = fabs(dTemp);
    CapValue(dTemp, 0.0, 3.0);
    cout << " The capValue of dTemp is: " << dTemp << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

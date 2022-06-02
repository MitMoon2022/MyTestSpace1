// testCstringCompare1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <CString>

#include "stdafx.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    cout<<"Start program\n";

   // example for CString::CompareNoCase
    CString s1( "abc" );
    CString s2( "ABD" );
    ASSERT( s1.CompareNoCase( s2 ) == -1 ); // Compare with a CString.
    ASSERT( s1.Compare( "ABE" ) == -1 ); // Compare with LPTSTR string.

    system("pause");
	return 0;
}


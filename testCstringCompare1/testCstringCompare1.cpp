// testCstringCompare1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <CString>

#include "stdafx.h"
//#include "afxstr.h"
#include "atlstr.h"
#include <cassert>
#include <assert.h>




using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    cout<<"Start program\n";

   // example for CString::CompareNoCase
    CString s1( "abc" );
    CString s2( "ABD" );
    //CompareNoCase - return 0 when it is true!
    assert( s1.CompareNoCase( s2 ) == -1 ); // Compare with a CString.
    //assert(Expression)
    //Expression to be evaluated. If this expression evaluates to 0 (True), this causes an assertion failure that terminates the program.
    assert( s1.Compare( "ABE" ) < 0 ); // Compare with LPTSTR string.
    int error = s1.Compare( "ABE" );    //return 1
    cout<<"error is "<<error<<endl;

    system("pause");
	return 0;
}


#include <iostream>
#include <cstring>      // for c-style string functions
#include <cctype>       // for character-based functions
//#include "stdafx.h"

using namespace std;    

#define ABCD 1
#define DRYRUN 3    //you can have diff value, see below how it works
#include <iostream>
 
// Conditional inclusion
// https://en.cppreference.com/w/cpp/preprocessor/conditional
/* Combined directives
Checks if the identifier was defined as a macro name.

#ifdef identifier is essentially equivalent to #if defined identifier.

#ifndef identifier is essentially equivalent to #if !defined identifier. 
*/

/* Syntax
#if (expression)		
#ifdef identifier		
#ifndef identifier		
#elif (expression)		
#elifdef identifier		(since C++23)
#elifndef identifier		(since C++23)
#else		
#endif		 
*/

int main()
{
 
#ifdef ABCD
    std::cout << "1: yes\n";
#else
    std::cout << "1: no\n";
#endif
  //-------------------------------------------
#ifndef ABCD
    std::cout << "2: no1\n";
#elif ABCD == 2                 //this is good it can further evaluate the expression.
    std::cout << "2: yes\n";
#else
    std::cout << "2: no2\n";
#endif
 //----------------------------------------------
#if !defined(DCBA) && (ABCD < 2*4-3)
    std::cout << "3: yes\n";
#endif

// Note that if a compiler does not support C++23's #elifdef/#elifndef
// directives then the "unexpected" block (see below) will be selected.
#ifdef CPU
    std::cout << "4: no1\n";
#elifdef GPU
    std::cout << "4: no2\n";
#elifndef RAM
    std::cout << "4: yes\n"; // expected block
#else
    std::cout << "4: no!\n"; // unexpectedly selects this block by skipping 
                             // unknown directives and "jumping" directly
                             // from "#ifdef CPU" to this "#else" block
#endif
//-----------------------------------------------------------------------------------
// One simple it is used in production code.
#ifdef ULT
        cout<<"Executing some blocks of code here!"<<endl;
        cout<<"pUltManager->PickUnit(IsGangA() ? ULT_PNP_GANGA_TRAY : ULT_PNP_GANGB_TRAY, arg_2, arg_3, arg_4, arg_5);"<<endl;
#endif

#ifndef DRYRUN
        cout<<"if not in dry run mode - Therefore, it is in Active Run mode."<<endl;
        cout<<"Function call RunModeStart() for example"<<endl;
#elif DRYRUN ==1
        cout<<"DRYRUN mode 1"<<endl;
#elif DRYRUN ==2
        cout<<"DRYRUN mode 2"<<endl;        
#else
        cout<<"Actual run mode with material"<<endl;

#endif



}
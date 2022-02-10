// MyProjtemp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CpersonType.h"

using namespace std;

enum TASK_STATUS
{
    TASK_IN_PROGRESS,
    TASK_COMPLETE,
    TASK_ERROR,
    //
    TASK_HALT,  // to halt task for recovry purpose
    //
    TASK_EOL,   // to perform intape eol when machine eol
    //
    TASK_STOP,  // mcstop 
    //
    TASK_SKIP,
    //
    TASK_STANDBY,

    TASK_CONSECUTIVE_EMPTY,

};

int IndexerModAxisHoming()
{
    cout << "Inside a function" << endl;
    return TASK_COMPLETE;
}




int main()
{
    std::cout << "Hello World!\n";

    TASK_STATUS st;
    st = TASK_STOP;

    cout << "What is the st now: " << st << endl;
    cout << "Size of enum variable " << sizeof(st) << " bytes." << endl;
    //--------------------------------------------------------------------
    TASK_STATUS current = TASK_STATUS(IndexerModAxisHoming());
    cout << "What is the current status now: " << current << endl;
    //--------------------------------------------------------------------
    personType p1{ "Amy","Lim" };
    p1.print();




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

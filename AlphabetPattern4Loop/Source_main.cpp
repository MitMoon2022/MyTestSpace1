//C++ Exercises: Display the pattern like pyramid using the alphabet
//Last update on August 19 2022 21 : 50 : 27 (UTC / GMT + 8 hours)
//
//C++ For Loop : Exercise - 48 with Solution
//Write a program in C++ to display the pattern like pyramid using the alphabet.
//
//https ://www.w3resource.com/cpp-exercises/for-loop/cpp-for-loop-exercise-48.php

#include <iostream>

using namespace std;

void func1()    //key the number of alphabet.
{
    int i, j;
    char alph = 'A';
    int n, blk;
    int ctr = 1;
    cout << "\n\n Display the pattern like pyramid using the alphabet:\n";
    cout << "---------------------------------------------------------\n";
    cout << " Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (blk = 1; blk <= n - i; blk++)
            cout << "  ";
        for (j = 0; j <= (ctr / 2); j++)
        {
            cout << alph++ << " ";
        }
        alph = alph - 2;
        for (j = 0; j < (ctr / 2); j++)
        {
            cout << alph-- << " ";
        }
        ctr = ctr + 2;
        alph = 'A';
        cout << endl;
    }


}//end of func1

void func2()    //key in the numeric
{
    int i, j;
    //char alph = 'A';
    int num;
    int n, blk;
    int ctr = 1;
    cout << "\n\n Display the pattern like pyramid using the numeric:\n";
    cout << "---------------------------------------------------------\n";
    cout << " Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;
    num = 1;        //inititial the num.
    for (i = 1; i <= n; i++) {
        for (blk = 1; blk <= n - i; blk++)
            cout << "  ";
        for (j = 0; j <= (ctr / 2); j++)
        {
            cout << num++ << " ";
        }
        //alph = alph - 2;
        num = num - 2;
        for (j = 0; j < (ctr / 2); j++)
        {
            cout << num-- << " ";
        }
        ctr = ctr + 2;
        //alph = 'A';
        num = 1;
        cout << endl;
    }
}

void func3()    //key in the string of aphabet
{
    int i, j;
    //char alph = 'A';
    //int num;
    string input;
    int n, blk;
    int ctr = 1;
    cout << "\n\n Display the pattern like pyramid using the numeric:\n";
    cout << "---------------------------------------------------------\n";
    cout << " Input the number of Letters (less than 26) in the Pyramid: ";
    cin >> n;
    //num = 1;        //inititial the num.
    input = "C++isFun!";

    //for (i = 1; i <= n; i++) {
    //    for (blk = 1; blk <= n - i; blk++)
    //        cout << "  ";
    //    for (j = 0; j <= (ctr / 2); j++)
    //    {
    //        cout << input++ << " ";
    //    }
    //    //alph = alph - 2;
    //    num = num - 2;
    //    for (j = 0; j < (ctr / 2); j++)
    //    {
    //        cout << num-- << " ";
    //    }
    //    ctr = ctr + 2;
    //    //alph = 'A';
    //    num = 1;
    //    cout << endl;
    //}
}





int main_try()  //my testing program first.
{
   
    cout << "Start program!" << endl;
    //func1();
    func2();


    cout << "=========== End ======================" << endl;
    return 0;
}

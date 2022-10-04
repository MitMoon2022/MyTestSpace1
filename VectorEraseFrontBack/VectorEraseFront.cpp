// VectorEraseFront.cpp : Defines the entry point for the console application.
// https://linuxhint.com/remove-specific-element-vector-cpp/
// https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/?ref=lbp
// https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/?ref=lbp
// Removing from the Front
// The erase member function can remove an element from the front of the vector.  
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
        //vector<char> vtr = {'A', 'B', 'C', 'D', 'E'};

        vector<char> vtr;
        vtr.push_back('A');
        vtr.push_back('B');
        vtr.push_back('C');
        vtr.push_back('D');
        vtr.push_back('E');


        // Printing the Vector
        for (auto it = vtr.begin(); it != vtr.end(); ++it)
            cout << *it<<' ';
        cout<<endl;



        //1 method: make use of iterator to erase which ?th Element.
        /*
        vector<char>::iterator q = vtr.begin();
        vector<char>::iterator p = vtr.erase(q);
        cout << *p << endl;
        */


        //2 method:erase the first one! 
        vector<char>::iterator q = vtr.begin();
        cout << *q <<" Remove the first element."<<endl; //print out to check only.
        cout << vtr.front() << " - vector.front() return the first element"<<endl;
        vtr.erase(vtr.begin());  //its like pop_front().

        for (int i=0; i < vtr.size(); i++)
            cout << vtr[i] << ' ';
        cout << endl;
        //- CANNOT USE THIS METHOD LIKE THE ERASE FIRST GOT ERROR -----
        //vector<char>::iterator n = vtr.end(); this is ok but the next step-error
        //cout<< *n <<" Remove the last element."<<endl; XXXXXX

        //-------------------------------------------------------------
        cout<<vtr.back()<<endl; //a dedicated back() which return the element.
        vtr.pop_back();  //remove the last element.

        //-------------------------------------------------------------
        for(vector<char>::iterator it = vtr.begin(); it != vtr.end(); it++)
            cout << *it << ' ';
        cout << endl;
        //-------------------------------------------------------------
        //Date: 04/10/2022
        //https://www.delftstack.com/howto/cpp/cpp-vector-of-pointers/
        //
  /*    std::vector offers rich functionality to allocate a vector of pointers and 
        manipulate the vector with multiple built-in functions. 
        This method provides a more flexible interface for new element creation during
        the run-time. Notice that we initialized the vector elements with the nullptr value
        as shown:
  */
        //Start
        cout<<"==========================================================================="<<endl;
        vector<int*> vector_p;

        vector_p.push_back(new int(1)); //new operator returns a pointer to the heap.
        vector_p.push_back(new int(2));
        vector_p.push_back(new int(3));
        vector_p.push_back(new int(4));
        vector_p.push_back(new int(5));

        //auto count = vector_p.size();

        cout << "vector_p addresses:" << endl;
        for(int i = 0; i < vector_p.size(); ++i) {
            cout << &vector_p[i] << endl;
        }
        cout<<endl;

        //How to access the content of the vector's element of pointers *variable.
         cout << "vector_p content:" << endl;
        for(int i = 0; i < vector_p.size(); ++i) {
            cout << *vector_p[i] << endl;
        }
        cout<<endl;

         cout << "vector_p XXXX:" << endl;
        for(int i = 0; i < vector_p.size(); ++i) {
            cout << vector_p[i] << endl;
        }
        cout<<endl;




        /*for(int*& s : vector_p)
            cout<< s <<endl

        cout<<endl;*/




    system("pause");
	return 0;
}


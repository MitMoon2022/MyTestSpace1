// ReadfromFileTest2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.delftstack.com/howto/cpp/how-to-read-a-file-line-by-line-cpp/#use-std-getline-function-to-read-a-file-line-by-line
//Use std::getline() Function to Read a File Line by Line

//The getline() function is the preferred way of reading a file line by line in C++.
//The function reads characters from the input stream until the delimiter char is encounteredand then stores them in a string.
//The delimiter is passed as the third optional parameter, and by default, it’s assumed to be a new line character \n.
//Since the getline method returns a nonzero value if the data can be read from the stream, 
//we can put it as a while loop condition to continue retrieving lines from a file until the end of it is reached.
//Note that it’s good practice to verify if the input stream has an associated file with the is_open method.


#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <string>

//#include  <bits/stdc++.h>

using namespace std;

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

int main()
{
    std::cout << "Start Program!\n";

    string filename("input.txt");
    vector<string> lines;
    string line;

  /*  std::fstream input_file;
    input_file.open(filename);*/

    ifstream input_file(filename);
   if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

   //However, it does not work using the VSC++ to debug, when u go to the debug folder run the cmd_prompt
   //it works.

    //string str;

   /* cout << "Please enter your name: \n";
    getline(cin, str);
    cout << "Hello, " << str
        << " welcome to GfG !\n";*/


    while (getline(input_file, line,';')) {
        lines.push_back(line);
    }

    for (const auto& i : lines)
        cout << i << endl;

    input_file.close();
    return EXIT_SUCCESS;
}


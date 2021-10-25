
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//This inital code is to demonstrate complier for modern C++.


int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
	
	cout<<"The End"<<endl;

}
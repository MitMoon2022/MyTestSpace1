// SysCallMoveCopy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Using command system call to execute file move or copy example



*/
#include <windows.h>
#include <iostream>
/* strerror example : error list */
#include <stdio.h>
#include <string.h>
#include <errno.h>


using namespace std;


int main()

{
	//FILE* pFile;
	//int ret1;
	//ret1 = system("start note5pad.exe");// As an example. Change [notepad] to any executable file //
	//std::cout<<"The return value of system() is : "<<ret1<<std::endl;
	//system ("start ipconfig") ; //with the "start" in font an other application.
	//system ("ipconfig") ; //without the start, it will run the command in its window.
	//system("pause");

	//system ("start C:\\Users\\Folder\\chrome.exe https://www.stackoverflow.com"); //for opening stackoverflow through google chrome , if chorme.exe is in that folder..
	//---------------------------------------------------------------------------------------
	/*pFile = fopen("unexist.ent", "r");
	if (pFile == NULL)
		printf("Error return code ->: %s\n", strerror(errno));
		
	*/
	// Start here!
	if (system(NULL))	//C++ program to check if we can run commands using system()
		cout << "Command processor exists";
	else
		cout << "Command processor doesn't exists";

	int ret;

	//ret = system("start notepad.exe");	//return zero if success
	//cout << "ret is " << ret << endl;
	//if (ret)
	//	cout << "Fails\n";
	//else
	//	cout << "Success\n";

	//it needs a \\ for directory access.
	ret = system("copy test.txt d:\\testC.txt");	//return zero if success
	if (ret)
		cout << "Fails\n";
	else
		cout << "Success\n";

	//ret = system("move test.txt f:\mvtest.txt");	//return zero if success
	//if (ret)
	//	cout << "Fails\n";
	//else
	//	cout << "Success\n";





	cout << "Done_Complete!" << endl;
	return 0;
}
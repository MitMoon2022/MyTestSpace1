// MoveFile01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/******************************************************************************
Description
The C library function int rename(const char *old_filename, const char *new_filename) causes the filename
referred to by old_filename to be changed to new_filename.

We can use a rename() function in our C++ program to move files from one directory to another directory.
It is present in <cstdio> header of C++.

Return Value
On success, zero is returned. On error, -1 is returned, and errno is set appropriately.

Move - meaning the source file will be gone when successfull.

Few points that must be noted before you run the given example program:

The old directory path must be relative to the same directory where the program is saved otherwise you will have to specify the absolute path of the file.
The new directory will be created relative to the current directory (the directory where you have saved your program) unless you specify an absolute path/name for the destination. If the new directory name already exists, the compiler will throw an error.
After the files have been moved, the old directory/file is removed or deleted.

************************************************************************/

#define STN_ARC_LOGFILE         "D:\\MitData\\DebugLog\\Log_ARC"

#define oldname1    "d:/jftMit1/movecpp.txt"
#define newname1    "d:/jftMit/MyTestSpace1/MoveFile01/x64"

#define oldname2    "d:\\jftMit1\\movecpp.txt"
#define newname2    "d:\\jftMit\\MyTestSpace1\\MoveFile01\\x64"

#define oldnameGood    "file.txt"
#define newnameGood    "d:/Movefile.txt"


#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    cout << "Start Program!\n";
    int ret;
    //char oldname[] = "file.txt";		        //tested ok
    //char newname[] = "d:/Movefile.txt";	   //tested ok

    //const char *oldname = "file.txt";           //tested - must use command pmpt to run + const keyword
    //const char *newname = "d:/Movefile.txt";
    //ret = rename(oldname, newname);

    //Working de!
    const char* oldname = oldnameGood;           //tested - must use command pmpt to run + const keyword
    const char* newname = newnameGood;





 /*
    if(ret == 0) {
       printf("File renamed successfully");
    } else {
       printf("Error: unable to rename the file");
    }
 */
    ret = rename(oldname, newname);
    if (ret)
        cout << "Failure";
    else
        cout << "Success";


    return(0);






}


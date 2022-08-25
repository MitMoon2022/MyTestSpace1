// CopyFile01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************************************************
Part 2: Learn how to see the filesystem path :
https://en.cppreference.com/w/cpp/filesystem/absolute XXX Don't work

Try copy file using <fstream> too.
https ://stackoverflow.com/questions/10195343/copy-a-file-in-a-sane-safe-and-efficient-way

***********************************************************************************/
//#define STN_ARC_LOGFILE         "D:\\MitData\\DebugLog\\Log_ARC"

#define oldname1    "d:/jftMit1/movecpp.txt"
#define newname1    "d:/jftMit/MyTestSpace1/MoveFile01/x64"

#define oldname2    "d:\\jftMit1\\movecpp.txt"
#define newname2    "d:\\jftMit\\MyTestSpace1\\MoveFile01\\x64"

#define oldnameGood    "file.txt"
#define newnameGood    "d:/Movefile.txt"


#include <iostream>
#include <cstdio>
#include <filesystem>   //for part2 filesystem
#include <fstream>
#include <Windows.h>
#include <atlstr.h>

using namespace std;

//namespace fs = std::filesystem;

int main()
{
    cout << "Start Program!\n";
    int ret;
   
    //Working de!
    const char* oldname = oldnameGood;           //tested - must use command pmpt to run + const keyword
    const char* newname = newnameGood;

//=========================================================================================
//Part2:

/*cout << "current path is " << std::filesystem::<< endl;*/

//   ifstream src("/file.txt", ios::binary);
//ofstream dst("./fileCopy.txt", ios::out);     //with "/" or "//" same result.
//   ofstream dst("D://jftMit1//fileCopy.txt", ios::binary); 

//    dst << src.rdbuf();
//    cout << "Done\n";   //copy over but no content!

//==using <windows.h> method =======================================================================================
    CString  sourcePath("/file.txt");
    CString  DetFilePath("D:\\jftMit1\\fileCopy1.txt");


    //CopyFile("d:/folder1/file.exe", "d:/folder2/file.exe", true)
    //ret = CopyFile(L"/file.txt", L"/fileCopy1.txt", true);
    //TRUE means don't overwrite the existing file; just abort. FALSE means overwrite it.

    ret = CopyFile(sourcePath, DetFilePath, true);


    cout << "ret is " << ret << endl;
    if (ret)
        cout << "Success\n";
    else
        cout << "Failure\n";


    cout << "Done1\n";
    return(0);






}
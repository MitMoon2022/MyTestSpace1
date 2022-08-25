/*
Program: Copy and Move a file from one location to other
Description: This program can copy and move a file from one location to another location. To copy a function there is a different function, to move the file there is a different function.
Author: Lord Hypersonic
Email: lordhypersonic.522@gmail.com
Website: www.lordhypersonic.blogspot.com
*/
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

//function  to copy a file from one location to other
void fileCopy (string file, string source, string destination)
{
    for (int i = 0; i < source.size(); i++)
    {
        if (source[i] == '\\')
            source[i] = '/';
    }
    for (int i = 0; i < destination.size(); i++)
    {
        if (destination[i] == '\\')
            destination[i] == '/';
    }
    if (source[source.size()-1] != '/')
        source.push_back('/');
    source = source + file;
    if (destination[destination.size() - 1] != '/')
        destination.push_back('/');
    destination = destination + file;
    ifstream sourceFile (source.c_str(), ios::binary);
    if (sourceFile)
    {
        ifstream idestination (destination.c_str());
        if (idestination)
        {
            cout<<file<<" already exist, Do you want to replace? [Yes/No] : ";
            string choice;
            getline(cin, choice);
            if (choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES" || choice == "y")
            {
                idestination.close();
                ofstream destinationFile (destination.c_str(), ios::binary);
                string line;
                while (getline(sourceFile,line))
                {
                    destinationFile<<line<<endl;
                }
                destinationFile.flush();
                destinationFile.close();
                cout<<endl<<"File copied successfully"<<endl;
            }
            else
            {
                cout<<"Exiting...........";
                idestination.close();
            }
        }
        else
        {
            idestination.close();
            ofstream destinationFile (destination.c_str(), ios::binary);
            string line;
            while (getline(sourceFile,line))
            {
                destinationFile<<line<<endl;
            }
            destinationFile.flush();
            destinationFile.close();
            cout<<endl<<"File copied successfully"<<endl;
        }
        sourceFile.close();
    }
    else
    {
        cout<<endl<<"[ERROR]:-"<<endl;
        cout<<"Not able to locate "<<source<<endl;
    }
}

//function to move a file from one location to other
void fileMove (string file, string source, string destination)
{
    for (int i = 0; i < source.size(); i++)
    {
        if (source[i] == '\\')
            source[i] = '/';
    }
    for (int i = 0; i < destination.size(); i++)
    {
        if (destination[i] == '\\')
            destination[i] = '/';
    }
    if (source[source.size() -1 ] != '/')
        source.push_back('/');
    source = source + file;
    if (destination[destination.size() - 1] != '/')
        destination.push_back('/');
    destination = destination + file;
    ifstream sourceFile (source.c_str(), ios::binary);
    if (sourceFile)
    {
        ifstream idestination (destination.c_str());
        if (idestination)
        {
            cout<<file<<" already exist, Do you want to replace? [Yes/No] : ";
            string choice;
            getline(cin, choice);
            if (choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES" || choice == "y")
            {
                idestination.close();
                ofstream destinationFile (destination.c_str(), ios::binary);
                string line;
                while (getline(sourceFile,line))
                {
                    destinationFile<<line<<endl;
                }
                destinationFile.flush();
                destinationFile.close();
                sourceFile.close();
                int status = remove(source.c_str());
                if (status == 0)
                    cout<<endl<<"File moved successfully"<<endl;
                else
                {
                    perror("[ERROR]:-\nNot able to move file due to following error");
                }
            }
            else
            {
                cout<<"Exiting...........";
                idestination.close();
            }
        }
        else
        {
            idestination.close();
            ofstream destinationFile (destination.c_str(), ios::binary);
            string line;
            while (getline(sourceFile,line))
            {
                destinationFile<<line<<endl;;
            }
            destinationFile.flush();
            destinationFile.close();
            sourceFile.close();
            int status = remove(source.c_str());
            if (status == 0)
                cout<<endl<<"File moved successfully"<<endl;
            else
            {
                perror("[ERROR]:-\nNot able to move file due to following error");
            }
        }
        sourceFile.close();
    }
    else
    {
        cout<<endl<<"[ERROR]:-"<<endl;
        cout<<"Not able to locate "<<source<<endl;
    }
}

int main()
{
    string choice;
    string fileName, source, destination;
    cout<<"Select option:- \n1. Copy file \n2. Move file \n>>"; getline(cin,choice);
    for (int i = 0; i < choice.size(); i++)
    {
        if (isupper(choice[i]))
        {
            tolower(choice[i]);
        }
    }
    if (choice == "1" || choice == "copy" || choice == "copy file" || choice == "copy file from one location to another")
    {
        cout<<"Enter file name: "; getline(cin,fileName);
        cout<<"Enter location of file: "; getline(cin,source);
        cout<<"Enter destination: "; getline(cin,destination);
        fileCopy(fileName,source,destination);
    }
    else if (choice == "2" || choice == "move" || choice == "move file" || choice == "move file from one location to another")
    {
        cout<<"Enter file name: "; getline(cin,fileName);
        cout<<"Enter location of file: "; getline(cin,source);
        cout<<"Enter destination: "; getline(cin,destination);
        fileMove(fileName, source, destination);
    }
    else
    {
        cout<<endl<<"There is no such option \""<<choice<<"\""<<endl;
    }
    _getch();
}
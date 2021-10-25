/*
This program is show you how to call an .exe just like in the command prompt.
*/

#include <windows.h>

int main ()

{
   //system ("start notepad.exe") ;// As an example. Change [notepad] to any executable file //
	//system ("start ipconfig") ; //with the "start" in font an other application.
	system ("ipconfig") ; //without the start, it will run the command in its window.
	//system("pause");

	//system ("start C:\\Users\\Folder\\chrome.exe https://www.stackoverflow.com"); //for opening stackoverflow through google chrome , if chorme.exe is in that folder..
    
	return 0 ;
}
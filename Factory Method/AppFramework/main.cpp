#include "Application.h"
#include "TextApplication.h"
#include "SpreadSheetApplication.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;	//to check for memory leaks!
	SpreadSheetApplication app ;
	app.New() ;
	app.Open() ;
	app.Save() ;
}

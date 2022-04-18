
// MFCDialogThread.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCDialogThreadApp:
// See MFCDialogThread.cpp for the implementation of this class
//

class CMFCDialogThreadApp : public CWinApp
{
public:
	CMFCDialogThreadApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCDialogThreadApp theApp;
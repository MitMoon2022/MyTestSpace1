
// MFCDialogThreadL51.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCDialogThreadL51App:
// See MFCDialogThreadL51.cpp for the implementation of this class
//

class CMFCDialogThreadL51App : public CWinApp
{
public:
	CMFCDialogThreadL51App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCDialogThreadL51App theApp;
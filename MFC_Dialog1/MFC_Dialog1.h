
// MFC_Dialog1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_Dialog1App:
// See MFC_Dialog1.cpp for the implementation of this class
//

class CMFC_Dialog1App : public CWinApp
{
public:
	CMFC_Dialog1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_Dialog1App theApp;
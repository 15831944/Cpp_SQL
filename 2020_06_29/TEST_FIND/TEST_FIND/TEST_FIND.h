
// TEST_FIND.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTEST_FINDApp:
// See TEST_FIND.cpp for the implementation of this class
//

class CTEST_FINDApp : public CWinApp
{
public:
	CTEST_FINDApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTEST_FINDApp theApp;
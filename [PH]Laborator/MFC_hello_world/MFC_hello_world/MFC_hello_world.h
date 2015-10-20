
// MFC_hello_world.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_hello_worldApp:
// See MFC_hello_world.cpp for the implementation of this class
//

class CMFC_hello_worldApp : public CWinApp
{
public:
	CMFC_hello_worldApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_hello_worldApp theApp;
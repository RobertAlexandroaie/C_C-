
// MFC_Interschimba_Butoane.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_Interschimba_ButoaneApp:
// See MFC_Interschimba_Butoane.cpp for the implementation of this class
//

class CMFC_Interschimba_ButoaneApp : public CWinApp
{
public:
	CMFC_Interschimba_ButoaneApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_Interschimba_ButoaneApp theApp;
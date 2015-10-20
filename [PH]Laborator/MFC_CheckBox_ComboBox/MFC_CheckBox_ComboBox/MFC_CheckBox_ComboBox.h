
// MFC_CheckBox_ComboBox.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_CheckBox_ComboBoxApp:
// See MFC_CheckBox_ComboBox.cpp for the implementation of this class
//

class CMFC_CheckBox_ComboBoxApp : public CWinApp
{
public:
	CMFC_CheckBox_ComboBoxApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_CheckBox_ComboBoxApp theApp;
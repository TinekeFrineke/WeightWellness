
// WeightWatchers.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CWeightWatchersApp:
// See WeightWatchers.cpp for the implementation of this class
//

class CWeightWatchersApp : public CWinApp
{
public:
	CWeightWatchersApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CWeightWatchersApp theApp;
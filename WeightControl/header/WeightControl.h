// WeightWatchers.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "model/Model.h"


// CWWApplication:
// See WeightWatchers.cpp for the implementation of this class
//

class CWWApplication : public CWinApp
{
public:
	CWWApplication();
  ~CWWApplication();

  std::tstring      GetDataDirectory() const { return mDataDirectory; }
  std::tstring      GetUserDirectory() const;

// Overrides
public:
	virtual BOOL      InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()

private:
  weight::Model         mModel;
  std::tstring      mDataDirectory;
};

extern CWWApplication theApp;
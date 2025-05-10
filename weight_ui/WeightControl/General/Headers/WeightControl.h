// WeightWatchers.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include <memory>
#include <string>

#include "resource.h"		// main symbols

namespace weight {
class IMessageHandler;
class IModel;
}

// CWWApplication:
// See WeightWatchers.cpp for the implementation of this class
//

class CWWApplication: public CWinApp
{
public:
    CWWApplication();
    ~CWWApplication();

    std::string      GetDataDirectory() const { return mDataDirectory; }

    // Overrides
public:
    virtual BOOL      InitInstance();

    // Implementation

    DECLARE_MESSAGE_MAP()

private:
    std::shared_ptr<weight::IMessageHandler> m_messageHandler;
    std::unique_ptr<weight::IModel> mModel;
    std::string   mDataDirectory;
};

extern CWWApplication theApp;
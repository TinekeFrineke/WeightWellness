// WeightWatchers.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "WeightControl.h"

#include <assert.h>
#include <iostream>
#include <xercesc/util/IOException.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include "Utilities/Inifile.h"
//#include "Utilities/PathUtils.h"

#include "model/ModelFactory.h"
#include "model/Personalia.h"
#include "xmlreader/XmlReader.h"
#include "xmlwriter/XmlWriter.h"

#include "NewNameDialog.h"
#include "PageFactory.h"
#include "WWDialog.h"

// CWWApplication

BEGIN_MESSAGE_MAP(CWWApplication, CWinApp)
    ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CWWApplication construction
CWWApplication::CWWApplication()
    : mModel(weight::ModelFactory().CreateModel())
{
    //_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    try
    {
        XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();
    }
    catch (const XERCES_CPP_NAMESPACE::XMLException& toCatch)
    {
        std::wcout << L"Error during initialization of xerces-c: " << toCatch.getMessage();
        throw;
    }

    // Place all significant initialization in InitInstance
}


// The one and only CWWApplication object

CWWApplication theApp;


// CWWApplication initialization

BOOL CWWApplication::InitInstance()
{
    // InitCommonControls() is required on Windows XP if an application
    // manifest specifies use of ComCtl32.dll version 6 or later to enable
    // visual styles.  Otherwise, any window creation will fail.
    InitCommonControls();

    CWinApp::InitInstance();

    AfxEnableControlContainer();

    TCHAR dir[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, dir);
    std::wifstream input(std::wstring(dir) + L"\\weightcontrol.ini");
    Inifile inifile(input);

    if (inifile.empty()) {
        MessageBox(0, _T("Unable to open inifile"), inifile.GetName().c_str(), MB_OK);
        return FALSE;
    }

    mDataDirectory = inifile[_T("General")][_T("DataPath")];

    ww2024::XmlReader reader(*mModel);
    reader.Read(mDataDirectory);
    if (mModel->GetPersonalia() == nullptr) {
        NewNameDialog dialog(NULL);
        INT_PTR nResponse = dialog.DoModal();
        if (nResponse == IDOK)
        {
            std::tstring name(dialog.GetName());
            if (name.empty()) {
                MessageBox(0, _T("Empty personalia not allowed"), _T("ERROR"), MB_OK);
                return FALSE;
            }

            try {
                mModel->SetPersonalia(std::make_unique<weight::Personalia>(name));
            }
            catch (const std::runtime_error& error) {
                std::tstring terror(Str::ToTString(error.what()));
                MessageBox(0, _T("Invalid personalia"), terror.c_str(), MB_OK);
                return FALSE;
            }
            // TODO ww2024: Place code here to handle when the dialog is
            //  dismissed with OK
        }
        else if (nResponse == IDCANCEL)
        {
            MessageBox(0, _T("Unable to create personalia"), _T("ERROR"), MB_OK);
            return FALSE;
        }
    }

    mModel->SetStrategy(mModel->GetPersonalia()->GetStrategy());

    auto pagefactory(std::make_unique<PageFactory>(mModel->GetRecipeDefinitionRepository(),
                                                   mModel->GetFoodDefinitionRepository(),
                                                   mModel->GetCalculator()));

    CWWDialog dlg(*mModel, std::move(pagefactory));
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO ww2024: Place code here to handle when the dialog is
        //  dismissed with OK
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO ww2024: Place code here to handle when the dialog is
        //  dismissed with Cancel
    }

    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE;
}


CWWApplication::~CWWApplication()
{
    try {
        ww2024::XmlWriter writer(*mModel);
        writer.Write(mDataDirectory);
    }
    catch (const XERCES_CPP_NAMESPACE::IOException& error) {
        std::tstring terror(Str::ToTString(error.getMessage()));
        ::MessageBox(0, terror.c_str(), _T("Xerces Exception"), MB_OK);
    }
    catch (const std::exception& anException)
    {
        std::tstring terror(Str::ToTString(anException.what()));
        ::MessageBox(0, terror.c_str(), _T("Exception"), MB_OK);
    }

    XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();
    _CrtDumpMemoryLeaks();
}
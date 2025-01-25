

// WeightWatchers.cpp : Defines the class behaviors for the application.
//
#include "WeightControl.h"


#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QDebug>

#include <assert.h>
#include <iostream>
#include <xercesc/util/IOException.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include "Utilities/Inifile.h"
#include "Utilities/PathUtils.h"

#include "model/Personalia.h"
#include "viewmodel/IFoodDefinitionListModel.h"
#include "viewmodel/IFoodListModel.h"
#include "viewmodel/IDay.h"
#include "viewmodel/IPersonalData.h"
#include "viewmodel/IRecipeListModel.h"
#include "viewmodel/IViewModel.h"
#include "viewmodel/IWeek.h"
#include "viewmodel/ViewModelFactory.h"
#include "xmlreader/XmlReader.h"
#include "xmlwriter/XmlWriter.h"

namespace {
void attachConsole() {
    // Allocate a new console for the application
    AllocConsole();

    // Redirect standard output and error to the console
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);  // Redirect stdout to console
    freopen_s(&fp, "CONOUT$", "w", stderr);  // Redirect stderr to console

    // Optional: Print a message to the console
    qDebug() << "Console attached for logging.";
}
}

XercesInitializer::XercesInitializer()
{
    try
    {
        XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();
    }
    catch (const XERCES_CPP_NAMESPACE::XMLException& toCatch)
    {
        std::cout << "Error during initialization of xerces-c: "
            << toCatch.getMessage();
        throw;
    }
}

XercesInitializer::~XercesInitializer()
{
    XERCES_CPP_NAMESPACE::XMLPlatformUtils::Terminate();
}


int main(int argc, char* argv[])
{
    wchar_t dir[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, dir);
    std::wcout << "Current path: " << dir << std::endl;

    XercesInitializer initializer;

    WeightControl control;
    if (!control.Initialize()) {
        ::MessageBox(0, L"Could not initialize WeightControl", L"ERROR", MB_OK);
    }

    QGuiApplication app(argc, argv);

#ifdef _DEBUG
    attachConsole();
#endif

    auto viewModel(viewmodel::CreateViewModel(control.GetModel()));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("ViewModel", viewModel.get());
    engine.rootContext()->setContextProperty("PersonalData", viewModel->GetPersonalData());
    engine.rootContext()->setContextProperty("Day", viewModel->GetDay());
    engine.rootContext()->setContextProperty("Week", viewModel->GetWeek());
    engine.rootContext()->setContextProperty("FoodListModel", viewModel->GetDay()->getFoodListModel());
    engine.rootContext()->setContextProperty("FoodDefinitionListModel", viewModel->getFoodDefinitionListModel());
    engine.rootContext()->setContextProperty("RecipeListModel", viewModel->getRecipeListModel());
    engine.addImportPath(":/");
    engine.loadFromModule("QmlResource", "Main");

    if (engine.rootObjects().isEmpty()) {
        qFatal("Failed to load QML Dialog.");
    }

    return app.exec(); // Start the Qt event loop
}

// CWWApplication initialization

WeightControl::WeightControl()
{
}

WeightControl::~WeightControl()
{
    try {
        ww2024::XmlWriter writer(*mModel);
        writer.Write(m_dataDirectory);
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

}

bool WeightControl::Initialize()
{
    TCHAR dir[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, dir);

    Inifile inifile(std::wstring(dir) + L"\\weightcontrol.ini");

    if (inifile.Empty()) {
        MessageBox(0, _T("Unable to open inifile"), inifile.GetName().c_str(), MB_OK);
        return false;
    }

    m_dataDirectory = inifile[_T("General")][_T("DataPath")];

    mModel = std::make_shared<weight::Model>();
    ww2024::XmlReader reader(*mModel);
    reader.Read(m_dataDirectory);
    //if (mModel.GetActivePersonalia() == NULL) {
    //    NewNameDialog dialog(NULL);
    //    INT_PTR nResponse = dialog.DoModal();
    //    if (nResponse == IDOK)
    //    {
    //        std::tstring name(dialog.GetName());
    //        if (name.empty()) {
    //            MessageBox(0, _T("Empty personalia not allowed"), _T("ERROR"), MB_OK);
    //            return FALSE;
    //        }

    //        try {
    //            mModel.AddPersonalia(name);
    //        }
    //        catch (const std::runtime_error& error) {
    //            std::tstring terror(Str::ToTString(error.what()));
    //            MessageBox(0, _T("Invalid personalia"), terror.c_str(), MB_OK);
    //            return false;
    //        }
    //        // TODO ww2024: Place code here to handle when the dialog is
    //        //  dismissed with OK
    //    }
    //    else if (nResponse == IDCANCEL)
    //    {
    //        MessageBox(0, _T("Unable to create personalia"), _T("ERROR"), MB_OK);
    //        return false;
    //    }
    //}

    mModel->SetStrategy(mModel->GetActivePersonalia()->GetStrategy());

    return true;
}

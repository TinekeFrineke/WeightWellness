

//// WeightWatchers.h : main header file for the PROJECT_NAME application
////
//
#pragma once

#include <memory>
#include <string>

#include "model/Model.h"


class XercesInitializer
{
public:
    XercesInitializer();
    ~XercesInitializer();
};

class WeightControl
{
public:
    WeightControl();
    ~WeightControl();

    bool Initialize();

    std::shared_ptr<weight::Model> GetModel() { return mModel; }


private:
    std::shared_ptr<weight::Model> mModel;
    std::wstring m_dataDirectory;
};

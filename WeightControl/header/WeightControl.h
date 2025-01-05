

//// WeightWatchers.h : main header file for the PROJECT_NAME application
////
//
#pragma once

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

private:
    weight::Model mModel;
    std::wstring mDataDirectory;
};

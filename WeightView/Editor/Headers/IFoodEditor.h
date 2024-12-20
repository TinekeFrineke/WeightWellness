#pragma once

#include <memory>

class CWnd;

namespace weight {
class Model;
class Voedingsmiddel;
}

class IFoodEditor
{
public:
    virtual ~IFoodEditor() = default;

    virtual bool Edit(weight::Voedingsmiddel& food) = 0;

private:
    CWnd* m_parent;
};


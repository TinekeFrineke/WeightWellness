#pragma once

#include <memory>

class CWnd;

namespace weight {
class Model;
class VMDefinitie;
}

class FoodDefinitionEditor
{
public:
    FoodDefinitionEditor(weight::Model& model, CWnd* parent);

    bool Edit(weight::VMDefinitie& definition) const;
    std::unique_ptr<weight::VMDefinitie> Create() const;

private:
    mutable bool m_newDefinition{ false };
    weight::Model& m_model;
    CWnd* m_parent;
};


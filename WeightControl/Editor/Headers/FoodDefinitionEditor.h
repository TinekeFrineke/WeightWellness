#pragma once

#include <memory>

class CWnd;

namespace weight {
class IModel;
class VMDefinitie;
}

class FoodDefinitionEditor
{
public:
    FoodDefinitionEditor(weight::IModel& model, CWnd* parent);

    bool Edit(weight::VMDefinitie& definition) const;
    std::unique_ptr<weight::VMDefinitie> Create() const;

private:
    mutable bool m_isNewDefinition{ false };
    weight::IModel& m_model;
    CWnd* m_parent;
};


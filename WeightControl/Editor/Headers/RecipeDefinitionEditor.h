#pragma once

#include "IRecipeDefinitionEditor.h"

class CWnd;

namespace weight {
class IModel;
}

class RecipeDefinitionEditor
    : public IRecipeDefinitionEditor
{
public:
    explicit RecipeDefinitionEditor(weight::IModel& model, CWnd* parent) : m_model(model), m_parent(parent) {}

    bool Edit(weight::ReceptDefinitie& portie) const override;
    std::unique_ptr<weight::ReceptDefinitie> Create() const override;

private:
    weight::IModel& m_model;
    CWnd* m_parent;
};

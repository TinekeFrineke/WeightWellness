#pragma once

#include "IRecipeDefinitionEditor.h"

class CWnd;

namespace weight {
class Model;
}

class RecipeDefinitionEditor
    : public IRecipeDefinitionEditor
{
public:
    RecipeDefinitionEditor(weight::Model& model, CWnd* parent) : m_model(model), m_parent(parent) {}

    bool Edit(weight::ReceptDefinitie& portie) const override;
    std::unique_ptr<weight::ReceptDefinitie> Create() const override;

private:
    weight::Model& m_model;
    CWnd* m_parent;
};

#pragma once

#include "IRecipeDefinitionEditor.h"

class CWnd;

namespace weight {
class IModel;

template <typename TYPE> class IRepository;
}

class RecipeDefinitionEditor
    : public IRecipeDefinitionEditor
{
public:
    explicit RecipeDefinitionEditor(weight::IModel& model, std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes, CWnd* parent) : m_model(model), m_parent(parent) {}

    bool Edit(weight::ReceptDefinitie& portie) const override;
    std::unique_ptr<weight::ReceptDefinitie> Create() const override;

private:
    weight::IModel& m_model;
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    CWnd* m_parent;
};

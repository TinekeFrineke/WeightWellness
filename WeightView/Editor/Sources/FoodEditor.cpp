#include "FoodEditor.h"

#include "stdafx.h"

#include "model/IFoodDefinitionRepository.h"
#include "model/Model.h"
#include "model/NutritionalValue.h"
#include "model/Voedingsmiddel.h"
#include "model/VoedingsmiddelDefinitie.h"

#include "EditFoodDialog.h"


FoodEditor::FoodEditor(std::shared_ptr<weight::IFoodDefinitionRepository> definitions,
                       std::shared_ptr<weight::PointsCalculator> calculator,
                       CWnd* parent)
    : m_definitions(definitions)
    , m_calculator(calculator)
    , m_parent(parent)
{
}

bool FoodEditor::Edit(weight::Voedingsmiddel& food)
{
    auto definition(m_definitions->Find(food.GetName()));
    if (definition != nullptr) {
        return Edit(food, definition->GetNutritionalValue().GetParameters(), definition->GetPointsPer100Units(),
                    definition->GetPortieList());
    }

    std::vector<std::unique_ptr<weight::Portie>> porties;
    porties.push_back(std::make_unique<weight::Portie>(food.GetConstLot().GetPortie()));

    return Edit(food, food.GetConstLot().GetParameters(), food.GetLot().GetPointsPer100Units(), porties);
}

bool FoodEditor::Edit(weight::Voedingsmiddel& food, const weight::FoodParameters& parameters, double pointsPer100Units,
                      const std::vector<std::unique_ptr<weight::Portie>>& porties)
{
    EditFoodDialog dialog(food, food.GetConstLot().GetParameters(), m_calculator, pointsPer100Units, porties, m_parent);
    INT_PTR nResponse = dialog.DoModal();
    return nResponse == IDOK;
}

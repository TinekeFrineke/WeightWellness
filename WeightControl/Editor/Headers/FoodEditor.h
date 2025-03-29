#pragma once

#include <memory>
#include <vector>

#include "IFoodEditor.h"

class CWnd;

namespace weight {
class PointsCalculator;
class Portie;
class VMDefinitie;
struct FoodParameters;

template <typename TYPE> class IRepository;
}

class FoodEditor
    : public IFoodEditor
{
public:
    FoodEditor(std::shared_ptr<weight::IRepository<weight::VMDefinitie>> definitions,
               std::shared_ptr<weight::PointsCalculator> calculator,
               CWnd* parent);

    bool Edit(weight::Voedingsmiddel& food) override;

private:
    bool Edit(weight::Voedingsmiddel& food, const weight::FoodParameters& parameters, double pointsPer100Units,
              const std::vector<std::unique_ptr<weight::Portie>>& porties);

    //weight::Model& m_model;
    std::shared_ptr<weight::IRepository<weight::VMDefinitie>> m_definitions;
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    CWnd* m_parent;
};


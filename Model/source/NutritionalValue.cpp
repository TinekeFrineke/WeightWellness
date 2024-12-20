

#include "NutritionalValue.h"

namespace weight
{

int Entity<NutritionalValue>::mNumberOfInstances = 0;


NutritionalValue::NutritionalValue(std::shared_ptr<weight::PointsCalculator> calculator)
    : m_calculator(std::move(calculator))
{
#ifdef FIND_LEAKS
    Register();
#endif
}

NutritionalValue::~NutritionalValue()
{
#ifdef FIND_LEAKS
    Unregister();
#endif
}

double NutritionalValue::GetPointsPer100Units() const
{
    return m_calculator->GetPointsPer100Units(m_parameters);
}

std::wstring NutritionalValue::GetInstanceName() const noexcept
{
    return L"None";
}

std::wstring NutritionalValue::GetClassName()
{
    return L"NutritionalValue";
}

} // namespace weight

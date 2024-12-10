
#pragma once

#include "Entity.h"
#include "PointsCalculator.h"

namespace weight
{


class NutritionalValue : public Entity<NutritionalValue>
{
public:
    explicit NutritionalValue(std::shared_ptr<weight::PointsCalculator> calculator);
    ~NutritionalValue() override;

    FoodParameters GetParameters() const noexcept { return m_parameters; }
    void SetParameters(const FoodParameters& parameters) noexcept { m_parameters = parameters; }

    double GetKCalPer100Units() const { return m_parameters.GetKCalPer100Units(); }
    double GetFatPer100Units() const { return m_parameters.GetVetPer100Units(); }
    double GetProteinPer100Units() const { return m_parameters.GetEiwitPer100Units(); }
    double GetCarbohydratesPer100Units() const { return m_parameters.GetKoolhydratenPer100Units(); }
    double GetFibersPer100Units() const { return m_parameters.GetVezelsPer100Units(); }
    double GetPointsPer100Units() const;

    void SetKCalPer100Units(double aKCalPer100) { m_parameters.SetKCalPer100Units(aKCalPer100); }
    void SetFatPer100Units(double aVetPer100) { m_parameters.SetVetPer100Units(aVetPer100); }
    void SetProteiPer100Units(double anEiwit) { m_parameters.SetEiwitPer100Units(anEiwit); }
    void SetCarbohydratesPer100Units(double akh) { m_parameters.SetKoolhydratenPer100Units(akh); }
    void SetFibersPer100Units(double aVezels) { m_parameters.SetVezelsPer100Units(aVezels); }

protected:
    std::wstring GetInstanceName() const noexcept override;
    static std::tstring GetClassName();

private:
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    FoodParameters m_parameters{};
};


} // namespace weight

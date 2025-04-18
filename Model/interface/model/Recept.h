#pragma once

#include "Item.h"
#include "Portie.h"
#include "Voedingsmiddel.h"

namespace weight
{


class Recept: public Item
{
public:
    explicit Recept(const std::string& aName) : mName(aName) {}
    virtual                       ~Recept();

    std::string GetName() const override { return mName; }
    double GetPoints() const override;
    void Accept(ItemVisitor& aVisitor) override;

    int GetNumberOfPortions() const noexcept { return mNumberOfPortions; }
    double GetPointsPerPortion() const noexcept { return mPointsPerPortion; }

    void SetNumberOfPortions(int aNumber) noexcept { mNumberOfPortions = aNumber; }
    void SetPointsPerPortion(double aPunten) noexcept { mPointsPerPortion = aPunten; }


private:
    std::string mName;
    int mNumberOfPortions{};
    double mPointsPerPortion{};
};


} // namespace weight

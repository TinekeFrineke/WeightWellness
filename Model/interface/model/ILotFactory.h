#pragma once

#include <memory>

namespace weight {

class PortionedLot;
class Portie;
class VMDefinitie;

struct FoodParameters;

class ILotFactory
{
public:
    virtual ~ILotFactory() = default;

    virtual std::unique_ptr<PortionedLot> Create(const FoodParameters& parameters, Portie& aPortie) = 0;
};

} // namespace weight

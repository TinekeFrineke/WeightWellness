#pragma once

#include <memory>

namespace weight {

class PortionedLot;
class Portie;
class VMDefinitie;

class ILotFactory
{
public:
    virtual ~ILotFactory() = default;

    virtual std::unique_ptr<PortionedLot> Create(const VMDefinitie& aDefinitie, Portie& aPortie) = 0;
};

} // namespace weight

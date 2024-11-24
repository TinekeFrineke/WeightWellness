#pragma once

#include <memory>

namespace WW {

class PortionedLot;
class Portie;
class VMDefinitie;

class ILotFactory
{
public:
    virtual ~ILotFactory() = default;

    virtual std::unique_ptr<PortionedLot> Create(VMDefinitie& aDefinitie, Portie& aPortie) = 0;
};

} // namespace WW
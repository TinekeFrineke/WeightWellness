#pragma once

#include <memory>

namespace WW {

class Lot;
class Portie;
class VMDefinitie;

class ILotFactory
{
public:
    virtual ~ILotFactory() = default;

    virtual std::unique_ptr<Lot> Create(VMDefinitie& aDefinitie, Portie& aPortie) = 0;
};

} // namespace WW
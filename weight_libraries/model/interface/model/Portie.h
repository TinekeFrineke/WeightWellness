#pragma once

#include <string>

#include "Entity.h"

namespace weight
{


// Een portie bevat een vast aantal grammen of milliliters, en een vast
// aantal punten. Intern wordt een portie altijd uitgedrukt in een aantal
// van deze units.
class Portie: public Entity<Portie>
{
public:
    Portie(const std::string& aName);
    Portie(const Portie& portie);
    ~Portie();

    double GetUnits() const noexcept { return mUnits; }
    std::string GetName() const { return mName; }

    void                  SetUnits(double anAmount) noexcept { mUnits = anAmount; }
    void                  SetName(const std::string& aName) { mName = aName; }

    // Entity overrides
    std::string  GetInstanceName() const noexcept override { return mName; }
    static std::string   GetClassName() { return "Portie"; }

private:
    double mUnits;
    std::string mName;
};


} // namespace weight

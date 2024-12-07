#pragma once

#include <string>

#include "Entity.h"

namespace weight
{


// Een portie bevat een vast aantal grammen of mulliliters, en een vast
// aantal punten. Intern wordt een portie altijd uitgedrukt in een aantal
// van deze units.
class Portie: public Entity<Portie>
{
public:
    Portie(const std::wstring& aName);
    Portie(const Portie& portie);
    ~Portie();

    double GetUnits() const noexcept { return mUnits; }
    std::wstring GetName() const { return mName; }

    void                  SetUnits(double anAmount) noexcept { mUnits = anAmount; }
    void                  SetName(const std::wstring& aName) { mName = aName; }

    // Entity overrides
    virtual std::wstring  GetInstanceName() const noexcept override { return mName; }
    static std::wstring   GetClassName() { return _T("Portie"); }

private:
    double mUnits;
    std::wstring mName;
};


} // namespace weight

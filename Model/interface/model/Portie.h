#pragma once

#include "Entity.h"
#include "PortieNaam.h"
#include "Unit.h"

namespace weight
{


// Een portie bevat een vast aantal grammen of mulliliters, en een vast
// aantal punten. Intern wordt een portie altijd uitgedrukt in een aantal
// van deze units.
class Portie : public Entity<Portie>
{
public:
                        Portie(const PortieNaam & aName);
                        Portie(const Portie & aPortie);
                        ~Portie();

  double                GetUnits() const                  { return mUnits; }
  PortieNaam            GetName() const                   { return mName; }

  void                  SetUnits(double anAmount)         { mUnits = anAmount; }
  void                  SetName(const PortieNaam & aName) { mName = aName; }

  // Entity overrides
  virtual std::tstring  GetInstanceName() const           { return mName.Get(); }
  static std::tstring   GetClassName()                    { return _T("Portie"); }

private:
  double                mUnits;
  PortieNaam            mName;

  static int            mNumberOfPorties;
};


} // namespace weight

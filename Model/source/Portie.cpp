
#include "Portie.h"

#ifdef FIND_LEAKS
#include <windows.h>
#endif



namespace WW
{


int Entity<Portie>::mNumberOfInstances = 0;


Portie::Portie(const PortieNaam& aName)
    : mName(aName),
    mUnits(0)
{
#ifdef FIND_LEAKS
    Register();
#endif
}


Portie::Portie(const Portie& aPortie)
    : mName(aPortie.mName),
    mUnits(aPortie.mUnits)
{
#ifdef FIND_LEAKS
    Register();
#endif
}


Portie::~Portie()
{
#ifdef FIND_LEAKS
    Unregister();
#endif
}


} // namespace WW

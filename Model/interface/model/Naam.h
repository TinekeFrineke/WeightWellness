#pragma once

#include <tchar.h>

#include "Utilities/StrUtils.h"


namespace weight
{


class Naam
{
public:
    Naam(const std::tstring& aName)
        : mName(aName) {}
    std::tstring                  Get() const { return mName; }

private:
    std::tstring                  mName;
};


inline bool operator==(const Naam& aName1, const Naam& aName2)
{
    return aName1.Get() == aName2.Get();
}


} // namespace weight

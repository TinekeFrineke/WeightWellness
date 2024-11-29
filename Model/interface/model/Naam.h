#pragma once

#include <tchar.h>

#include "Utilities/StrUtils.h"


namespace weight
{


class Naam
{
public:
    explicit Naam(const std::wstring& aName) : mName(aName) {}
    std::wstring Get() const { return mName; }

private:
    std::wstring mName;
};


inline bool operator==(const Naam& aName1, const Naam& aName2)
{
    return aName1.Get() == aName2.Get();
}


} // namespace weight

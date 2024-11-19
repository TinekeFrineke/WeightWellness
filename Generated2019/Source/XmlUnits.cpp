//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlUnits.h"

#include <assert.h>
#include <tchar.h>

#include "XmlUnit.h"

namespace ww2019
{
XmlUnits::XmlUnits()
{
}

XmlUnits::~XmlUnits()
{
}



const std::vector<std::unique_ptr<XmlUnit>> & XmlUnits::GetUnitList() const
{
    return mUnitList;
}


void XmlUnits::Add(std::unique_ptr<XmlUnit> aUnit)
{
    mUnitList.push_back(std::move(aUnit));
}
}
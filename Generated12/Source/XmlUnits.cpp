#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlUnits.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface\Generated\XmlUnit.h"

namespace ww_1_2
{
XmlUnits::XmlUnits()
{
}

XmlUnits::~XmlUnits()
{
  for (size_t i = 0; i < mUnitList.size(); ++i)
    delete mUnitList[i];
}



const std::vector<XmlUnit *> & XmlUnits::GetUnitList() const
{
  return mUnitList;
}


void XmlUnits::Add(XmlUnit * aUnit)
{
  mUnitList.push_back(aUnit);
}
}
#include "../Interface/stdafx.h"
#include "../Interface/XmlUnits.h"

#include <assert.h>
#include <tchar.h>

#include "../Interface/XmlUnit.h"

namespace ww2019
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
#include "stdafx.h"
#include "XmlUnits.h"

#include <assert.h>
#include <tchar.h>

#include "XmlUnit.h"

namespace ww_1_1
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
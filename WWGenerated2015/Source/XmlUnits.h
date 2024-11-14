#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2015
{
// Forward declarations
class XmlUnit;
class XmlUnits : public XmlClass
{
public:
  XmlUnits();
  virtual ~XmlUnits();

  const std::vector<XmlUnit *> & GetUnitList() const;
  void Add(XmlUnit * aUnit);

private:
  // Prohibit copying and assignment
  XmlUnits(const XmlUnits & anOriginal);
  XmlUnits & operator=(const XmlUnits & anOriginal);
  std::vector<XmlUnit *> mUnitList;
};


}

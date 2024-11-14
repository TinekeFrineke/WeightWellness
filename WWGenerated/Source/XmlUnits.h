#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnits_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnits_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_1
{
// Forward declarations
class XmlUnit;
class XmlUnits : public Generator::XmlClass
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
#endif // Projects_VC10_WW_WWGenerated_XmlUnits_h__

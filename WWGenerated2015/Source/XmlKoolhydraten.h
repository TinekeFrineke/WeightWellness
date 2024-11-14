#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlStrategybase.h"

namespace ww2015
{
// Forward declarations
class XmlKoolhydraten : public XmlClass
{
public:
  XmlKoolhydraten();
  virtual ~XmlKoolhydraten();

  const XmlStrategybase & GetStrategybase() const;
  XmlStrategybase & GetStrategybase();

private:
  // Prohibit copying and assignment
  XmlKoolhydraten(const XmlKoolhydraten & anOriginal);
  XmlKoolhydraten & operator=(const XmlKoolhydraten & anOriginal);
  XmlStrategybase mStrategybase;
};


}

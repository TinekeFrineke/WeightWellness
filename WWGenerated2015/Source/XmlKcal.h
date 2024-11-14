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
class XmlKcal : public XmlClass
{
public:
  XmlKcal();
  virtual ~XmlKcal();

  const XmlStrategybase & GetStrategybase() const;
  XmlStrategybase & GetStrategybase();

private:
  // Prohibit copying and assignment
  XmlKcal(const XmlKcal & anOriginal);
  XmlKcal & operator=(const XmlKcal & anOriginal);
  XmlStrategybase mStrategybase;
};


}

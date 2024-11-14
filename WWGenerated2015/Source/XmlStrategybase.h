#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2015
{
class XmlStrategybase : public XmlClass
{
public:
  XmlStrategybase();
  virtual ~XmlStrategybase();


private:
  // Prohibit copying and assignment
  XmlStrategybase(const XmlStrategybase & anOriginal);
  XmlStrategybase & operator=(const XmlStrategybase & anOriginal);
};


}

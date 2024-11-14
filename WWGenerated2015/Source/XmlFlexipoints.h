#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlBonuslist.h"
#include "XmlVrijeporties.h"
#include "XmlStrategybase.h"

namespace ww2015
{
// Forward declarations
class XmlFlexipoints : public XmlClass
{
public:
  XmlFlexipoints();
  virtual ~XmlFlexipoints();

  const XmlBonuslist & GetBonuslist() const;
  XmlBonuslist & GetBonuslist();
  const XmlVrijeporties & GetVrijeporties() const;
  XmlVrijeporties & GetVrijeporties();
  const XmlStrategybase & GetStrategybase() const;
  XmlStrategybase & GetStrategybase();

private:
  // Prohibit copying and assignment
  XmlFlexipoints(const XmlFlexipoints & anOriginal);
  XmlFlexipoints & operator=(const XmlFlexipoints & anOriginal);
  XmlBonuslist mBonuslist;
  XmlVrijeporties mVrijeporties;
  XmlStrategybase mStrategybase;
};


}

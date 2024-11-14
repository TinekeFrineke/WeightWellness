#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlBonuslist.h"
#include "XmlSterrelots.h"
#include "XmlStrategybase.h"

namespace ww2015
{
// Forward declarations
class XmlPropoints : public XmlClass
{
public:
  XmlPropoints();
  virtual ~XmlPropoints();

  const XmlBonuslist & GetBonuslist() const;
  XmlBonuslist & GetBonuslist();
  const XmlSterrelots & GetSterrelots() const;
  XmlSterrelots & GetSterrelots();
  const XmlStrategybase & GetStrategybase() const;
  XmlStrategybase & GetStrategybase();

private:
  // Prohibit copying and assignment
  XmlPropoints(const XmlPropoints & anOriginal);
  XmlPropoints & operator=(const XmlPropoints & anOriginal);
  XmlBonuslist mBonuslist;
  XmlSterrelots mSterrelots;
  XmlStrategybase mStrategybase;
};


}

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_2
{
// Forward declarations
class XmlBonuscell;
class XmlBonuslist : public XmlClass
{
public:
  XmlBonuslist();
  virtual ~XmlBonuslist();

  const std::vector<XmlBonuscell *> & GetBonuscellList() const;
  void Add(XmlBonuscell * aBonuscell);

private:
  // Prohibit copying and assignment
  XmlBonuslist(const XmlBonuslist & anOriginal);
  XmlBonuslist & operator=(const XmlBonuslist & anOriginal);
  std::vector<XmlBonuscell *> mBonuscellList;
};


}

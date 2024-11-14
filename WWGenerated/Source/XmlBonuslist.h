#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuslist_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuslist_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_1
{
// Forward declarations
class XmlBonuscell;
class XmlBonuslist : public Generator::XmlClass
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
#endif // Projects_VC10_WW_WWGenerated_XmlBonuslist_h__

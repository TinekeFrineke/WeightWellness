#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefs_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefs_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_1
{
// Forward declarations
class XmlGerechtdef;
class XmlGerechtdefs : public Generator::XmlClass
{
public:
  XmlGerechtdefs();
  virtual ~XmlGerechtdefs();

  const std::vector<XmlGerechtdef *> & GetGerechtdefList() const;
  void Add(XmlGerechtdef * aGerechtdef);

private:
  // Prohibit copying and assignment
  XmlGerechtdefs(const XmlGerechtdefs & anOriginal);
  XmlGerechtdefs & operator=(const XmlGerechtdefs & anOriginal);
  std::vector<XmlGerechtdef *> mGerechtdefList;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlGerechtdefs_h__

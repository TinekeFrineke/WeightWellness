#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdefs_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdefs_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_1
{
// Forward declarations
class XmlReceptdef;
class XmlReceptdefs : public Generator::XmlClass
{
public:
  XmlReceptdefs();
  virtual ~XmlReceptdefs();

  const std::vector<XmlReceptdef *> & GetReceptdefList() const;
  void Add(XmlReceptdef * aReceptdef);

private:
  // Prohibit copying and assignment
  XmlReceptdefs(const XmlReceptdefs & anOriginal);
  XmlReceptdefs & operator=(const XmlReceptdefs & anOriginal);
  std::vector<XmlReceptdef *> mReceptdefList;
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlReceptdefs_h__

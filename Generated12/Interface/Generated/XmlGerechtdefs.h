#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww_1_2
{
// Forward declarations
class XmlGerechtdef;
class XmlGerechtdefs : public XmlClass
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

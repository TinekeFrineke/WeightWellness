#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2019
{
// Forward declarations
class XmlReceptdef;
class XmlReceptdefs : public XmlClass
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

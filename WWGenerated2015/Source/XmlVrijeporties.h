#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2015
{
// Forward declarations
class XmlVrijeportie;
class XmlVrijeporties : public XmlClass
{
public:
  XmlVrijeporties();
  virtual ~XmlVrijeporties();

  const XmlVrijeportie * GetVrijeportie() const;
  void Add(XmlVrijeportie * aVrijeportie);

private:
  // Prohibit copying and assignment
  XmlVrijeporties(const XmlVrijeporties & anOriginal);
  XmlVrijeporties & operator=(const XmlVrijeporties & anOriginal);
  XmlVrijeportie * mVrijeportie;
};


}

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2015
{
// Forward declarations
class XmlSterrelot;
class XmlSterrelots : public XmlClass
{
public:
  XmlSterrelots();
  virtual ~XmlSterrelots();

  const XmlSterrelot * GetSterrelot() const;
  void Add(XmlSterrelot * aSterrelot);

private:
  // Prohibit copying and assignment
  XmlSterrelots(const XmlSterrelots & anOriginal);
  XmlSterrelots & operator=(const XmlSterrelots & anOriginal);
  XmlSterrelot * mSterrelot;
};


}

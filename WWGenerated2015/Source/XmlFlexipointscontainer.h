#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2015
{
// Forward declarations
class XmlFlexipoints;
class XmlFlexipointscontainer : public XmlClass
{
public:
  XmlFlexipointscontainer();
  virtual ~XmlFlexipointscontainer();

  const std::vector<XmlFlexipoints *> & GetFlexipointsList() const;
  void Add(XmlFlexipoints * aFlexipoints);

private:
  // Prohibit copying and assignment
  XmlFlexipointscontainer(const XmlFlexipointscontainer & anOriginal);
  XmlFlexipointscontainer & operator=(const XmlFlexipointscontainer & anOriginal);
  std::vector<XmlFlexipoints *> mFlexipointsList;
};


}

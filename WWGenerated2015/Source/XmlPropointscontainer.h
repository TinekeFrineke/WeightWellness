#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2015
{
// Forward declarations
class XmlPropoints;
class XmlPropointscontainer : public XmlClass
{
public:
  XmlPropointscontainer();
  virtual ~XmlPropointscontainer();

  const std::vector<XmlPropoints *> & GetPropointsList() const;
  void Add(XmlPropoints * aPropoints);

private:
  // Prohibit copying and assignment
  XmlPropointscontainer(const XmlPropointscontainer & anOriginal);
  XmlPropointscontainer & operator=(const XmlPropointscontainer & anOriginal);
  std::vector<XmlPropoints *> mPropointsList;
};


}

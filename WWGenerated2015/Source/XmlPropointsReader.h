#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015{ class XmlPropoints; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlPropointsReader : public XmlClass
{
public:
  XmlPropointsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPropoints *& aPropoints);
  XmlPropoints * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPropoints & aPropoints);

private:
  // Prohibit copying and assignment
  XmlPropointsReader(const XmlPropointsReader & anOriginal);
  XmlPropointsReader & operator=(const XmlPropointsReader & anOriginal);
};


}

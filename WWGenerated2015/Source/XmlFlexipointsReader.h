#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015{ class XmlFlexipoints; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlFlexipointsReader : public XmlClass
{
public:
  XmlFlexipointsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlFlexipoints *& aFlexipoints);
  XmlFlexipoints * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlFlexipoints & aFlexipoints);

private:
  // Prohibit copying and assignment
  XmlFlexipointsReader(const XmlFlexipointsReader & anOriginal);
  XmlFlexipointsReader & operator=(const XmlFlexipointsReader & anOriginal);
};


}

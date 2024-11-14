#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015{ class XmlFlexipointscontainer; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlFlexipointscontainerReader : public XmlClass
{
public:
  XmlFlexipointscontainerReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlFlexipointscontainer *& aFlexipointscontainer);
  XmlFlexipointscontainer * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlFlexipointscontainer & aFlexipointscontainer);

private:
  // Prohibit copying and assignment
  XmlFlexipointscontainerReader(const XmlFlexipointscontainerReader & anOriginal);
  XmlFlexipointscontainerReader & operator=(const XmlFlexipointscontainerReader & anOriginal);
};


}

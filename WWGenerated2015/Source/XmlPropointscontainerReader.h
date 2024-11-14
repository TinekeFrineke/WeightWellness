#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015{ class XmlPropointscontainer; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlPropointscontainerReader : public XmlClass
{
public:
  XmlPropointscontainerReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPropointscontainer *& aPropointscontainer);
  XmlPropointscontainer * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPropointscontainer & aPropointscontainer);

private:
  // Prohibit copying and assignment
  XmlPropointscontainerReader(const XmlPropointscontainerReader & anOriginal);
  XmlPropointscontainerReader & operator=(const XmlPropointscontainerReader & anOriginal);
};


}

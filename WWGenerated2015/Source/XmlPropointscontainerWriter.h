#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlPropointscontainer; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlPropointscontainerWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlPropointscontainer & aPropointscontainer);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPropointscontainer & aPropointscontainer, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlFlexipointscontainer; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlFlexipointscontainerWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlFlexipointscontainer & aFlexipointscontainer);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlFlexipointscontainer & aFlexipointscontainer, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

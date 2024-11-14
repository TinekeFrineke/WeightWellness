#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlGerechtdefs; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlGerechtdefsWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlGerechtdefs & aGerechtdefs);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerechtdefs & aGerechtdefs, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

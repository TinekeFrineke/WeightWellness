#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlPersonalia; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlPersonaliaWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlPersonalia & aPersonalia);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPersonalia & aPersonalia, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

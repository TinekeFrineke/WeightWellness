//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2024
{

class XmlReceptdefs;

class XmlReceptdefsWriter : public XmlClass
{
public:
    XmlClass::Result Write(const std::wstring & aFilename, const XmlReceptdefs& aReceptdefs);
    void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlReceptdefs & aReceptdefs, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

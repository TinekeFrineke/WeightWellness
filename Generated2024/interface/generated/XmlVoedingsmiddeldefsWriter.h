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

class XmlVoedingsmiddeldefs;

class XmlVoedingsmiddeldefsWriter : public XmlClass
{
public:
    XmlClass::Result Write(const std::wstring & aFilename, const XmlVoedingsmiddeldefs& aVoedingsmiddeldefs);
    void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldefs & aVoedingsmiddeldefs, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

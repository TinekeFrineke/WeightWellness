//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <memory>

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2024
{

class XmlVoedingsmiddeldefs;

class XmlVoedingsmiddeldefsReader : public XmlClass
{
public:
    XmlVoedingsmiddeldefsReader();

    std::unique_ptr<XmlVoedingsmiddeldefs> Read(const std::wstring & aFilename); 
    std::unique_ptr<XmlVoedingsmiddeldefs> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldefs & aVoedingsmiddeldefs);

private:
    XmlVoedingsmiddeldefsReader(const XmlVoedingsmiddeldefsReader& anOriginal) = delete;
    XmlVoedingsmiddeldefsReader& operator=(const XmlVoedingsmiddeldefsReader& anOriginal) = delete;

};


}

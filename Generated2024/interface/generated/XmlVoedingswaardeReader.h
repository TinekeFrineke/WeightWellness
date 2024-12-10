//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>

#include <memory>
#include <string>

#include "XmlClass.h"


XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2024
{

class XmlVoedingswaarde;

class XmlVoedingswaardeReader : public XmlClass
{
public:
    XmlVoedingswaardeReader();

    std::unique_ptr<XmlVoedingswaarde> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingswaarde & Voedingswaarde);

private:
    XmlVoedingswaardeReader(const XmlVoedingswaardeReader& anOriginal) = delete;
    XmlVoedingswaardeReader& operator=(const XmlVoedingswaardeReader& anOriginal) = delete;

};


}

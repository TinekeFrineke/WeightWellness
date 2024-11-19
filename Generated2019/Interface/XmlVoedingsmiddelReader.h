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

namespace ww2019
{

class XmlVoedingsmiddel;

class XmlVoedingsmiddelReader : public XmlClass
{
public:
    XmlVoedingsmiddelReader();

    std::unique_ptr<XmlVoedingsmiddel> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddel & Voedingsmiddel);

private:
    XmlVoedingsmiddelReader(const XmlVoedingsmiddelReader& anOriginal) = delete;
    XmlVoedingsmiddelReader& operator=(const XmlVoedingsmiddelReader& anOriginal) = delete;

};


}

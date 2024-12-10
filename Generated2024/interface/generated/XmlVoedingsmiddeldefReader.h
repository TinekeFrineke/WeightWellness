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

class XmlVoedingsmiddeldef;

class XmlVoedingsmiddeldefReader : public XmlClass
{
public:
    XmlVoedingsmiddeldefReader();

    std::unique_ptr<XmlVoedingsmiddeldef> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldef & Voedingsmiddeldef);

private:
    XmlVoedingsmiddeldefReader(const XmlVoedingsmiddeldefReader& anOriginal) = delete;
    XmlVoedingsmiddeldefReader& operator=(const XmlVoedingsmiddeldefReader& anOriginal) = delete;

};


}

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

class XmlVoedingsmiddelheader;

class XmlVoedingsmiddelheaderReader : public XmlClass
{
public:
    XmlVoedingsmiddelheaderReader();

    std::unique_ptr<XmlVoedingsmiddelheader> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelheader & Voedingsmiddelheader);

private:
    XmlVoedingsmiddelheaderReader(const XmlVoedingsmiddelheaderReader& anOriginal) = delete;
    XmlVoedingsmiddelheaderReader& operator=(const XmlVoedingsmiddelheaderReader& anOriginal) = delete;

};


}

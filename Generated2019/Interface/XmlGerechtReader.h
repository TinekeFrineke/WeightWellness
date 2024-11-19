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

class XmlGerecht;

class XmlGerechtReader : public XmlClass
{
public:
    XmlGerechtReader();

    std::unique_ptr<XmlGerecht> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerecht & Gerecht);

private:
    XmlGerechtReader(const XmlGerechtReader& anOriginal) = delete;
    XmlGerechtReader& operator=(const XmlGerechtReader& anOriginal) = delete;

};


}

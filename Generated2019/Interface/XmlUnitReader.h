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

class XmlUnit;

class XmlUnitReader : public XmlClass
{
public:
    XmlUnitReader();

    std::unique_ptr<XmlUnit> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnit & Unit);

private:
    XmlUnitReader(const XmlUnitReader& anOriginal) = delete;
    XmlUnitReader& operator=(const XmlUnitReader& anOriginal) = delete;

};


}

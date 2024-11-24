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

class XmlStandardlot;

class XmlStandardlotReader : public XmlClass
{
public:
    XmlStandardlotReader();

    std::unique_ptr<XmlStandardlot> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlStandardlot & Standardlot);

private:
    XmlStandardlotReader(const XmlStandardlotReader& anOriginal) = delete;
    XmlStandardlotReader& operator=(const XmlStandardlotReader& anOriginal) = delete;

};


}

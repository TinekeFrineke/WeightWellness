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

class XmlBonuscell;

class XmlBonuscellReader : public XmlClass
{
public:
    XmlBonuscellReader();

    std::unique_ptr<XmlBonuscell> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuscell & Bonuscell);

private:
    XmlBonuscellReader(const XmlBonuscellReader& anOriginal) = delete;
    XmlBonuscellReader& operator=(const XmlBonuscellReader& anOriginal) = delete;

};


}

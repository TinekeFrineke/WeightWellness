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

class XmlBonuslist;

class XmlBonuslistReader : public XmlClass
{
public:
    XmlBonuslistReader();

    std::unique_ptr<XmlBonuslist> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuslist & Bonuslist);

private:
    XmlBonuslistReader(const XmlBonuslistReader& anOriginal) = delete;
    XmlBonuslistReader& operator=(const XmlBonuslistReader& anOriginal) = delete;

};


}

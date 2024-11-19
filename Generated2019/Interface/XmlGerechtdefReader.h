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

class XmlGerechtdef;

class XmlGerechtdefReader : public XmlClass
{
public:
    XmlGerechtdefReader();

    std::unique_ptr<XmlGerechtdef> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdef & Gerechtdef);

private:
    XmlGerechtdefReader(const XmlGerechtdefReader& anOriginal) = delete;
    XmlGerechtdefReader& operator=(const XmlGerechtdefReader& anOriginal) = delete;

};


}

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

class XmlReceptdef;

class XmlReceptdefReader : public XmlClass
{
public:
    XmlReceptdefReader();

    std::unique_ptr<XmlReceptdef> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdef & Receptdef);

private:
    XmlReceptdefReader(const XmlReceptdefReader& anOriginal) = delete;
    XmlReceptdefReader& operator=(const XmlReceptdefReader& anOriginal) = delete;

};


}

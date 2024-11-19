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

class XmlRecept;

class XmlReceptReader : public XmlClass
{
public:
    XmlReceptReader();

    std::unique_ptr<XmlRecept> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlRecept & Recept);

private:
    XmlReceptReader(const XmlReceptReader& anOriginal) = delete;
    XmlReceptReader& operator=(const XmlReceptReader& anOriginal) = delete;

};


}

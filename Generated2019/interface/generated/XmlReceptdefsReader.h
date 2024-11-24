//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <memory>

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{

class XmlReceptdefs;

class XmlReceptdefsReader : public XmlClass
{
public:
    XmlReceptdefsReader();

    std::unique_ptr<XmlReceptdefs> Read(const std::wstring & aFilename); 
    std::unique_ptr<XmlReceptdefs> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdefs & aReceptdefs);

private:
    XmlReceptdefsReader(const XmlReceptdefsReader& anOriginal) = delete;
    XmlReceptdefsReader& operator=(const XmlReceptdefsReader& anOriginal) = delete;

};


}

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

namespace ww2024
{

class XmlPersonalia;

class XmlPersonaliaReader : public XmlClass
{
public:
    XmlPersonaliaReader();

    std::unique_ptr<XmlPersonalia> Read(const std::wstring & aFilename); 
    std::unique_ptr<XmlPersonalia> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPersonalia & aPersonalia);

private:
    XmlPersonaliaReader(const XmlPersonaliaReader& anOriginal) = delete;
    XmlPersonaliaReader& operator=(const XmlPersonaliaReader& anOriginal) = delete;

};


}

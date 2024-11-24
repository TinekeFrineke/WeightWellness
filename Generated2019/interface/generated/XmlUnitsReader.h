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

class XmlUnits;

class XmlUnitsReader : public XmlClass
{
public:
    XmlUnitsReader();

    std::unique_ptr<XmlUnits> Read(const std::wstring & aFilename); 
    std::unique_ptr<XmlUnits> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnits & aUnits);

private:
    XmlUnitsReader(const XmlUnitsReader& anOriginal) = delete;
    XmlUnitsReader& operator=(const XmlUnitsReader& anOriginal) = delete;

};


}

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

class XmlWeek;

class XmlWeekReader : public XmlClass
{
public:
    XmlWeekReader();

    std::unique_ptr<XmlWeek> Read(const std::wstring & aFilename); 
    std::unique_ptr<XmlWeek> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlWeek & aWeek);

private:
    XmlWeekReader(const XmlWeekReader& anOriginal) = delete;
    XmlWeekReader& operator=(const XmlWeekReader& anOriginal) = delete;

};


}

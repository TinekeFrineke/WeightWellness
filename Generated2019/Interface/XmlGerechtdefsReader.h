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

class XmlGerechtdefs;

class XmlGerechtdefsReader : public XmlClass
{
public:
    XmlGerechtdefsReader();

    std::unique_ptr<XmlGerechtdefs> Read(const std::wstring & aFilename); 
    std::unique_ptr<XmlGerechtdefs> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdefs & aGerechtdefs);

private:
    XmlGerechtdefsReader(const XmlGerechtdefsReader& anOriginal) = delete;
    XmlGerechtdefsReader& operator=(const XmlGerechtdefsReader& anOriginal) = delete;

};


}

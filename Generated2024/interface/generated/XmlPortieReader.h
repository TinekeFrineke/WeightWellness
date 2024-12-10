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

namespace ww2024
{

class XmlPortie;

class XmlPortieReader : public XmlClass
{
public:
    XmlPortieReader();

    std::unique_ptr<XmlPortie> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortie & Portie);

private:
    XmlPortieReader(const XmlPortieReader& anOriginal) = delete;
    XmlPortieReader& operator=(const XmlPortieReader& anOriginal) = delete;

};


}

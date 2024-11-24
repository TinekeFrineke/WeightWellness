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

class XmlPortieomschrijving;

class XmlPortieomschrijvingReader : public XmlClass
{
public:
    XmlPortieomschrijvingReader();

    std::unique_ptr<XmlPortieomschrijving> Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

    XmlClass::Result Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortieomschrijving & Portieomschrijving);

private:
    XmlPortieomschrijvingReader(const XmlPortieomschrijvingReader& anOriginal) = delete;
    XmlPortieomschrijvingReader& operator=(const XmlPortieomschrijvingReader& anOriginal) = delete;

};


}

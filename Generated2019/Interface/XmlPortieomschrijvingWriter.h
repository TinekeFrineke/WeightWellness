//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{

class XmlPortieomschrijving;

class XmlPortieomschrijvingWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortieomschrijving & aPortieomschrijving);
    void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortieomschrijving & aPortieomschrijving, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

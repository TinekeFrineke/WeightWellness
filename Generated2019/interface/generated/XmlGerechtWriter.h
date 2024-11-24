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

class XmlGerecht;

class XmlGerechtWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerecht & aGerecht);
    void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerecht & aGerecht, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

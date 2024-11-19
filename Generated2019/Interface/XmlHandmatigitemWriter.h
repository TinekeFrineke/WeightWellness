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

class XmlHandmatigitem;

class XmlHandmatigitemWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlHandmatigitem & aHandmatigitem);
    void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlHandmatigitem & aHandmatigitem, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

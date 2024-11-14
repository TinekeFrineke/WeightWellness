#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlVrijeportie; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlVrijeportieWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVrijeportie & aVrijeportie);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVrijeportie & aVrijeportie, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

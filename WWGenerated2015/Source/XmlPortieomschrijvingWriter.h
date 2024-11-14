#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlPortieomschrijving; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlPortieomschrijvingWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortieomschrijving & aPortieomschrijving);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortieomschrijving & aPortieomschrijving, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

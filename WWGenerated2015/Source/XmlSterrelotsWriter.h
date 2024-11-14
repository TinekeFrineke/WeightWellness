#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlSterrelots; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlSterrelotsWriter : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlSterrelots & aSterrelots);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlSterrelots & aSterrelots, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

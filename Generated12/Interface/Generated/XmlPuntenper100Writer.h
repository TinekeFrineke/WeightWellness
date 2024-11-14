#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlPuntenper100; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlPuntenper100Writer : public XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPuntenper100 & aPuntenper100);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPuntenper100 & aPuntenper100, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

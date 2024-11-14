#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlBonuslist; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlBonuslistWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlBonuslist & aBonuslist);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuslist & aBonuslist, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

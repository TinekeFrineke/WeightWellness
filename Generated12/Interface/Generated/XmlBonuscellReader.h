#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlBonuscell; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlBonuscellReader : public XmlClass
{
public:
  XmlBonuscellReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlBonuscell *& aXmlBonuscell);
  XmlBonuscell * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuscell & Bonuscell);

private:
  // Prohibit copying and assignment
  XmlBonuscellReader(const XmlBonuscellReader & anOriginal);
  XmlBonuscellReader & operator=(const XmlBonuscellReader & anOriginal);
};


}

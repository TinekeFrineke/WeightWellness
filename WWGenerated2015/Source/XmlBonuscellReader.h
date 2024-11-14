#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlBonuscell; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
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

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlBonuslist; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlBonuslistReader : public XmlClass
{
public:
  XmlBonuslistReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlBonuslist *& aXmlBonuslist);
  XmlBonuslist * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuslist & Bonuslist);

private:
  // Prohibit copying and assignment
  XmlBonuslistReader(const XmlBonuslistReader & anOriginal);
  XmlBonuslistReader & operator=(const XmlBonuslistReader & anOriginal);
};


}

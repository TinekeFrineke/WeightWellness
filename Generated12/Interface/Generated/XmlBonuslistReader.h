#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2{ class XmlBonuslist; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlBonuslistReader : public XmlClass
{
public:
  XmlBonuslistReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlBonuslist *& aBonuslist);
  XmlBonuslist * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuslist & aBonuslist);

private:
  // Prohibit copying and assignment
  XmlBonuslistReader(const XmlBonuslistReader & anOriginal);
  XmlBonuslistReader & operator=(const XmlBonuslistReader & anOriginal);
};


}

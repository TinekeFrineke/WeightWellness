#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlStandardlot; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlStandardlotReader : public XmlClass
{
public:
  XmlStandardlotReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlStandardlot *& aXmlStandardlot);
  XmlStandardlot * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlStandardlot & Standardlot);

private:
  // Prohibit copying and assignment
  XmlStandardlotReader(const XmlStandardlotReader & anOriginal);
  XmlStandardlotReader & operator=(const XmlStandardlotReader & anOriginal);
};


}

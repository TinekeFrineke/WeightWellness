#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlGerecht; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlGerechtReader : public XmlClass
{
public:
  XmlGerechtReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlGerecht *& aXmlGerecht);
  XmlGerecht * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerecht & Gerecht);

private:
  // Prohibit copying and assignment
  XmlGerechtReader(const XmlGerechtReader & anOriginal);
  XmlGerechtReader & operator=(const XmlGerechtReader & anOriginal);
};


}

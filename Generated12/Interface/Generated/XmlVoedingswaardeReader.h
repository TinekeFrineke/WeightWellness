#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlVoedingswaarde; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlVoedingswaardeReader : public XmlClass
{
public:
  XmlVoedingswaardeReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingswaarde *& aXmlVoedingswaarde);
  XmlVoedingswaarde * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingswaarde & Voedingswaarde);

private:
  // Prohibit copying and assignment
  XmlVoedingswaardeReader(const XmlVoedingswaardeReader & anOriginal);
  XmlVoedingswaardeReader & operator=(const XmlVoedingswaardeReader & anOriginal);
};


}

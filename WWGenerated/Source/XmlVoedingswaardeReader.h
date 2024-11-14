#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingswaardeReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingswaardeReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlVoedingswaarde; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlVoedingswaardeReader : public Generator::XmlClass
{
public:
  XmlVoedingswaardeReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingswaarde *& aXmlVoedingswaarde);
  XmlVoedingswaarde * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingswaarde & Voedingswaarde);

private:
  // Prohibit copying and assignment
  XmlVoedingswaardeReader(const XmlVoedingswaardeReader & anOriginal);
  XmlVoedingswaardeReader & operator=(const XmlVoedingswaardeReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingswaardeReader_h__

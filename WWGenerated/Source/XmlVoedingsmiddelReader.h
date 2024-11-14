#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlVoedingsmiddel; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlVoedingsmiddelReader : public Generator::XmlClass
{
public:
  XmlVoedingsmiddelReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddel *& aXmlVoedingsmiddel);
  XmlVoedingsmiddel * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddel & Voedingsmiddel);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelReader(const XmlVoedingsmiddelReader & anOriginal);
  XmlVoedingsmiddelReader & operator=(const XmlVoedingsmiddelReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelReader_h__

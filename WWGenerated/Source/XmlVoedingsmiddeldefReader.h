#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlVoedingsmiddeldef; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlVoedingsmiddeldefReader : public Generator::XmlClass
{
public:
  XmlVoedingsmiddeldefReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddeldef *& aXmlVoedingsmiddeldef);
  XmlVoedingsmiddeldef * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldef & Voedingsmiddeldef);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldefReader(const XmlVoedingsmiddeldefReader & anOriginal);
  XmlVoedingsmiddeldefReader & operator=(const XmlVoedingsmiddeldefReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefReader_h__

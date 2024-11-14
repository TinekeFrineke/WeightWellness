#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelheaderReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelheaderReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlVoedingsmiddelheader; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlVoedingsmiddelheaderReader : public Generator::XmlClass
{
public:
  XmlVoedingsmiddelheaderReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddelheader *& aXmlVoedingsmiddelheader);
  XmlVoedingsmiddelheader * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelheader & Voedingsmiddelheader);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelheaderReader(const XmlVoedingsmiddelheaderReader & anOriginal);
  XmlVoedingsmiddelheaderReader & operator=(const XmlVoedingsmiddelheaderReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelheaderReader_h__

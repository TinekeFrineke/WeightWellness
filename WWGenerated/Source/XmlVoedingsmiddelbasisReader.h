#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelbasisReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelbasisReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlVoedingsmiddelbasis; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlVoedingsmiddelbasisReader : public Generator::XmlClass
{
public:
  XmlVoedingsmiddelbasisReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddelbasis *& aXmlVoedingsmiddelbasis);
  XmlVoedingsmiddelbasis * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelbasis & Voedingsmiddelbasis);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelbasisReader(const XmlVoedingsmiddelbasisReader & anOriginal);
  XmlVoedingsmiddelbasisReader & operator=(const XmlVoedingsmiddelbasisReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddelbasisReader_h__

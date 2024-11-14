#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefsReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefsReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1{ class XmlVoedingsmiddeldefs; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlVoedingsmiddeldefsReader : public Generator::XmlClass
{
public:
  XmlVoedingsmiddeldefsReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddeldefs *& aVoedingsmiddeldefs);
  XmlVoedingsmiddeldefs * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldefs & aVoedingsmiddeldefs);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldefsReader(const XmlVoedingsmiddeldefsReader & anOriginal);
  XmlVoedingsmiddeldefsReader & operator=(const XmlVoedingsmiddeldefsReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlVoedingsmiddeldefsReader_h__

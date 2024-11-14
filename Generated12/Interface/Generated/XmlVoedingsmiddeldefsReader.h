#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2{ class XmlVoedingsmiddeldefs; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlVoedingsmiddeldefsReader : public XmlClass
{
public:
  XmlVoedingsmiddeldefsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddeldefs *& aVoedingsmiddeldefs);
  XmlVoedingsmiddeldefs * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldefs & aVoedingsmiddeldefs);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldefsReader(const XmlVoedingsmiddeldefsReader & anOriginal);
  XmlVoedingsmiddeldefsReader & operator=(const XmlVoedingsmiddeldefsReader & anOriginal);
};


}

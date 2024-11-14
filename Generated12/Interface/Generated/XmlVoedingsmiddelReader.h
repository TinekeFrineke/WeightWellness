#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlVoedingsmiddel; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlVoedingsmiddelReader : public XmlClass
{
public:
  XmlVoedingsmiddelReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddel *& aXmlVoedingsmiddel);
  XmlVoedingsmiddel * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddel & Voedingsmiddel);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelReader(const XmlVoedingsmiddelReader & anOriginal);
  XmlVoedingsmiddelReader & operator=(const XmlVoedingsmiddelReader & anOriginal);
};


}

#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlVoedingsmiddelbasis; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlVoedingsmiddelbasisReader : public XmlClass
{
public:
  XmlVoedingsmiddelbasisReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddelbasis *& aXmlVoedingsmiddelbasis);
  XmlVoedingsmiddelbasis * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelbasis & Voedingsmiddelbasis);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddelbasisReader(const XmlVoedingsmiddelbasisReader & anOriginal);
  XmlVoedingsmiddelbasisReader & operator=(const XmlVoedingsmiddelbasisReader & anOriginal);
};


}

#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlVoedingsmiddeldef; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlVoedingsmiddeldefReader : public XmlClass
{
public:
  XmlVoedingsmiddeldefReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVoedingsmiddeldef *& aXmlVoedingsmiddeldef);
  XmlVoedingsmiddeldef * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldef & Voedingsmiddeldef);

private:
  // Prohibit copying and assignment
  XmlVoedingsmiddeldefReader(const XmlVoedingsmiddeldefReader & anOriginal);
  XmlVoedingsmiddeldefReader & operator=(const XmlVoedingsmiddeldefReader & anOriginal);
};


}

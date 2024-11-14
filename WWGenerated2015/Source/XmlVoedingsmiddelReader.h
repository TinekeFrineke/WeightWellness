#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlVoedingsmiddel; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
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

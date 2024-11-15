#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlVoedingsmiddeldefs; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlVoedingsmiddeldefsWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlVoedingsmiddeldefs & aVoedingsmiddeldefs);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldefs & aVoedingsmiddeldefs, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

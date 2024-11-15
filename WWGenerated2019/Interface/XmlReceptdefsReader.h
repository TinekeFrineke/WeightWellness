#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019{ class XmlReceptdefs; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlReceptdefsReader : public XmlClass
{
public:
  XmlReceptdefsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlReceptdefs *& aReceptdefs);
  XmlReceptdefs * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdefs & aReceptdefs);

private:
  // Prohibit copying and assignment
  XmlReceptdefsReader(const XmlReceptdefsReader & anOriginal);
  XmlReceptdefsReader & operator=(const XmlReceptdefsReader & anOriginal);
};


}

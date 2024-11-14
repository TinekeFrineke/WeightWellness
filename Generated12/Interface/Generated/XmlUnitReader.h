#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlUnit; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlUnitReader : public XmlClass
{
public:
  XmlUnitReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlUnit *& aXmlUnit);
  XmlUnit * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnit & Unit);

private:
  // Prohibit copying and assignment
  XmlUnitReader(const XmlUnitReader & anOriginal);
  XmlUnitReader & operator=(const XmlUnitReader & anOriginal);
};


}

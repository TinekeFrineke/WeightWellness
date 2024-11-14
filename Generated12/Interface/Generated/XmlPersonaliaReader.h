#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2{ class XmlPersonalia; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlPersonaliaReader : public XmlClass
{
public:
  XmlPersonaliaReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPersonalia *& aPersonalia);
  XmlPersonalia * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPersonalia & aPersonalia);

private:
  // Prohibit copying and assignment
  XmlPersonaliaReader(const XmlPersonaliaReader & anOriginal);
  XmlPersonaliaReader & operator=(const XmlPersonaliaReader & anOriginal);
};


}

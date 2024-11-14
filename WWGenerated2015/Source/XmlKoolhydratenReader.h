#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015{ class XmlKoolhydraten; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlKoolhydratenReader : public XmlClass
{
public:
  XmlKoolhydratenReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlKoolhydraten *& aKoolhydraten);
  XmlKoolhydraten * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlKoolhydraten & aKoolhydraten);

private:
  // Prohibit copying and assignment
  XmlKoolhydratenReader(const XmlKoolhydratenReader & anOriginal);
  XmlKoolhydratenReader & operator=(const XmlKoolhydratenReader & anOriginal);
};


}

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww2015{ class XmlUnits; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlUnitsReader : public XmlClass
{
public:
  XmlUnitsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlUnits *& aUnits);
  XmlUnits * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnits & aUnits);

private:
  // Prohibit copying and assignment
  XmlUnitsReader(const XmlUnitsReader & anOriginal);
  XmlUnitsReader & operator=(const XmlUnitsReader & anOriginal);
};


}

#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnitsReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnitsReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1{ class XmlUnits; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlUnitsReader : public Generator::XmlClass
{
public:
  XmlUnitsReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlUnits *& aUnits);
  XmlUnits * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnits & aUnits);

private:
  // Prohibit copying and assignment
  XmlUnitsReader(const XmlUnitsReader & anOriginal);
  XmlUnitsReader & operator=(const XmlUnitsReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlUnitsReader_h__

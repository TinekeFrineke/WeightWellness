#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnitReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlUnitReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlUnit; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlUnitReader : public Generator::XmlClass
{
public:
  XmlUnitReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlUnit *& aXmlUnit);
  XmlUnit * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnit & Unit);

private:
  // Prohibit copying and assignment
  XmlUnitReader(const XmlUnitReader & anOriginal);
  XmlUnitReader & operator=(const XmlUnitReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlUnitReader_h__

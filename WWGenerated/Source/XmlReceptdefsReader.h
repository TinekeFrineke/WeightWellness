#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdefsReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdefsReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1{ class XmlReceptdefs; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlReceptdefsReader : public Generator::XmlClass
{
public:
  XmlReceptdefsReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlReceptdefs *& aReceptdefs);
  XmlReceptdefs * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdefs & aReceptdefs);

private:
  // Prohibit copying and assignment
  XmlReceptdefsReader(const XmlReceptdefsReader & anOriginal);
  XmlReceptdefsReader & operator=(const XmlReceptdefsReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlReceptdefsReader_h__

#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefsReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefsReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1{ class XmlGerechtdefs; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlGerechtdefsReader : public Generator::XmlClass
{
public:
  XmlGerechtdefsReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlGerechtdefs *& aGerechtdefs);
  XmlGerechtdefs * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdefs & aGerechtdefs);

private:
  // Prohibit copying and assignment
  XmlGerechtdefsReader(const XmlGerechtdefsReader & anOriginal);
  XmlGerechtdefsReader & operator=(const XmlGerechtdefsReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlGerechtdefsReader_h__

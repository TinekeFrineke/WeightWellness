#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuscellReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuscellReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlBonuscell; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlBonuscellReader : public Generator::XmlClass
{
public:
  XmlBonuscellReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlBonuscell *& aXmlBonuscell);
  XmlBonuscell * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuscell & Bonuscell);

private:
  // Prohibit copying and assignment
  XmlBonuscellReader(const XmlBonuscellReader & anOriginal);
  XmlBonuscellReader & operator=(const XmlBonuscellReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlBonuscellReader_h__

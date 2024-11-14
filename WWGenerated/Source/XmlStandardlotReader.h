#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlStandardlotReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlStandardlotReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlStandardlot; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlStandardlotReader : public Generator::XmlClass
{
public:
  XmlStandardlotReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlStandardlot *& aXmlStandardlot);
  XmlStandardlot * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlStandardlot & Standardlot);

private:
  // Prohibit copying and assignment
  XmlStandardlotReader(const XmlStandardlotReader & anOriginal);
  XmlStandardlotReader & operator=(const XmlStandardlotReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlStandardlotReader_h__

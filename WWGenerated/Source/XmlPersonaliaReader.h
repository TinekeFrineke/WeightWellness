#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPersonaliaReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPersonaliaReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1{ class XmlPersonalia; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlPersonaliaReader : public Generator::XmlClass
{
public:
  XmlPersonaliaReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPersonalia *& aPersonalia);
  XmlPersonalia * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPersonalia & aPersonalia);

private:
  // Prohibit copying and assignment
  XmlPersonaliaReader(const XmlPersonaliaReader & anOriginal);
  XmlPersonaliaReader & operator=(const XmlPersonaliaReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlPersonaliaReader_h__

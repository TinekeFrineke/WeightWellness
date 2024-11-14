#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlWeekReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlWeekReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1{ class XmlWeek; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlWeekReader : public Generator::XmlClass
{
public:
  XmlWeekReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlWeek *& aWeek);
  XmlWeek * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlWeek & aWeek);

private:
  // Prohibit copying and assignment
  XmlWeekReader(const XmlWeekReader & anOriginal);
  XmlWeekReader & operator=(const XmlWeekReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlWeekReader_h__

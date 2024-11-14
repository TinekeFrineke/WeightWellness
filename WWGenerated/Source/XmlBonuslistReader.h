#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuslistReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuslistReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1{ class XmlBonuslist; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlBonuslistReader : public Generator::XmlClass
{
public:
  XmlBonuslistReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlBonuslist *& aBonuslist);
  XmlBonuslist * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuslist & aBonuslist);

private:
  // Prohibit copying and assignment
  XmlBonuslistReader(const XmlBonuslistReader & anOriginal);
  XmlBonuslistReader & operator=(const XmlBonuslistReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlBonuslistReader_h__

#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlGerecht; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlGerechtReader : public Generator::XmlClass
{
public:
  XmlGerechtReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlGerecht *& aXmlGerecht);
  XmlGerecht * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerecht & Gerecht);

private:
  // Prohibit copying and assignment
  XmlGerechtReader(const XmlGerechtReader & anOriginal);
  XmlGerechtReader & operator=(const XmlGerechtReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlGerechtReader_h__

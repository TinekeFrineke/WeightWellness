#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefsWriter_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefsWriter_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlGerechtdefs; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlGerechtdefsWriter : public Generator::XmlClass
{
public:
  Generator::XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlGerechtdefs & aGerechtdefs);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerechtdefs & aGerechtdefs, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlGerechtdefsWriter_h__

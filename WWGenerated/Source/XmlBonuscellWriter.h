#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuscellWriter_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlBonuscellWriter_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlBonuscell; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlBonuscellWriter : public Generator::XmlClass
{
public:
  XERCES_CPP_NAMESPACE::DOMNode * Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuscell & aBonuscell);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuscell & aBonuscell, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlBonuscellWriter_h__

#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlRecept; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlReceptReader : public Generator::XmlClass
{
public:
  XmlReceptReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlRecept *& aXmlRecept);
  XmlRecept * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlRecept & Recept);

private:
  // Prohibit copying and assignment
  XmlReceptReader(const XmlReceptReader & anOriginal);
  XmlReceptReader & operator=(const XmlReceptReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlReceptReader_h__

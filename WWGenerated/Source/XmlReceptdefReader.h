#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdefReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlReceptdefReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlReceptdef; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlReceptdefReader : public Generator::XmlClass
{
public:
  XmlReceptdefReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlReceptdef *& aXmlReceptdef);
  XmlReceptdef * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdef & Receptdef);

private:
  // Prohibit copying and assignment
  XmlReceptdefReader(const XmlReceptdefReader & anOriginal);
  XmlReceptdefReader & operator=(const XmlReceptdefReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlReceptdefReader_h__

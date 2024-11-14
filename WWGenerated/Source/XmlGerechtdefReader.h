#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlGerechtdefReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlGerechtdef; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlGerechtdefReader : public Generator::XmlClass
{
public:
  XmlGerechtdefReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlGerechtdef *& aXmlGerechtdef);
  XmlGerechtdef * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerechtdef & Gerechtdef);

private:
  // Prohibit copying and assignment
  XmlGerechtdefReader(const XmlGerechtdefReader & anOriginal);
  XmlGerechtdefReader & operator=(const XmlGerechtdefReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlGerechtdefReader_h__

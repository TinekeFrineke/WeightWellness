#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlHandmatigitemReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlHandmatigitemReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlHandmatigitem; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlHandmatigitemReader : public Generator::XmlClass
{
public:
  XmlHandmatigitemReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlHandmatigitem *& aXmlHandmatigitem);
  XmlHandmatigitem * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlHandmatigitem & Handmatigitem);

private:
  // Prohibit copying and assignment
  XmlHandmatigitemReader(const XmlHandmatigitemReader & anOriginal);
  XmlHandmatigitemReader & operator=(const XmlHandmatigitemReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlHandmatigitemReader_h__

#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortieReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortieReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlPortie; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlPortieReader : public Generator::XmlClass
{
public:
  XmlPortieReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPortie *& aXmlPortie);
  XmlPortie * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortie & Portie);

private:
  // Prohibit copying and assignment
  XmlPortieReader(const XmlPortieReader & anOriginal);
  XmlPortieReader & operator=(const XmlPortieReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlPortieReader_h__

#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlDagReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlDagReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlDag; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlDagReader : public Generator::XmlClass
{
public:
  XmlDagReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlDag *& aXmlDag);
  XmlDag * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlDag & Dag);

private:
  // Prohibit copying and assignment
  XmlDagReader(const XmlDagReader & anOriginal);
  XmlDagReader & operator=(const XmlDagReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlDagReader_h__

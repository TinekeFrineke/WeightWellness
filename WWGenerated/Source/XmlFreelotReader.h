#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlFreelotReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlFreelotReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlFreelot; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlFreelotReader : public Generator::XmlClass
{
public:
  XmlFreelotReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlFreelot *& aXmlFreelot);
  XmlFreelot * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlFreelot & Freelot);

private:
  // Prohibit copying and assignment
  XmlFreelotReader(const XmlFreelotReader & anOriginal);
  XmlFreelotReader & operator=(const XmlFreelotReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlFreelotReader_h__

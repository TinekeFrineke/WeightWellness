#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortieomschrijvingReader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPortieomschrijvingReader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlPortieomschrijving; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlPortieomschrijvingReader : public Generator::XmlClass
{
public:
  XmlPortieomschrijvingReader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPortieomschrijving *& aXmlPortieomschrijving);
  XmlPortieomschrijving * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortieomschrijving & Portieomschrijving);

private:
  // Prohibit copying and assignment
  XmlPortieomschrijvingReader(const XmlPortieomschrijvingReader & anOriginal);
  XmlPortieomschrijvingReader & operator=(const XmlPortieomschrijvingReader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlPortieomschrijvingReader_h__

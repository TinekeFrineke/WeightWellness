#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlVrijeporties; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlVrijeportiesReader : public XmlClass
{
public:
  XmlVrijeportiesReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVrijeporties *& aXmlVrijeporties);
  XmlVrijeporties * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVrijeporties & Vrijeporties);

private:
  // Prohibit copying and assignment
  XmlVrijeportiesReader(const XmlVrijeportiesReader & anOriginal);
  XmlVrijeportiesReader & operator=(const XmlVrijeportiesReader & anOriginal);
};


}

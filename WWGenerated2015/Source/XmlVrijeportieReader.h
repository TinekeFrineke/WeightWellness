#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlVrijeportie; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlVrijeportieReader : public XmlClass
{
public:
  XmlVrijeportieReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlVrijeportie *& aXmlVrijeportie);
  XmlVrijeportie * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVrijeportie & Vrijeportie);

private:
  // Prohibit copying and assignment
  XmlVrijeportieReader(const XmlVrijeportieReader & anOriginal);
  XmlVrijeportieReader & operator=(const XmlVrijeportieReader & anOriginal);
};


}

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlSterrelots; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlSterrelotsReader : public XmlClass
{
public:
  XmlSterrelotsReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlSterrelots *& aXmlSterrelots);
  XmlSterrelots * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlSterrelots & Sterrelots);

private:
  // Prohibit copying and assignment
  XmlSterrelotsReader(const XmlSterrelotsReader & anOriginal);
  XmlSterrelotsReader & operator=(const XmlSterrelotsReader & anOriginal);
};


}

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlSterrelot; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlSterrelotReader : public XmlClass
{
public:
  XmlSterrelotReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlSterrelot *& aXmlSterrelot);
  XmlSterrelot * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlSterrelot & Sterrelot);

private:
  // Prohibit copying and assignment
  XmlSterrelotReader(const XmlSterrelotReader & anOriginal);
  XmlSterrelotReader & operator=(const XmlSterrelotReader & anOriginal);
};


}

#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlReceptdef; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlReceptdefReader : public XmlClass
{
public:
  XmlReceptdefReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlReceptdef *& aXmlReceptdef);
  XmlReceptdef * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdef & Receptdef);

private:
  // Prohibit copying and assignment
  XmlReceptdefReader(const XmlReceptdefReader & anOriginal);
  XmlReceptdefReader & operator=(const XmlReceptdefReader & anOriginal);
};


}

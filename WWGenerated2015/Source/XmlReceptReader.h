#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlRecept; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlReceptReader : public XmlClass
{
public:
  XmlReceptReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlRecept *& aXmlRecept);
  XmlRecept * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlRecept & Recept);

private:
  // Prohibit copying and assignment
  XmlReceptReader(const XmlReceptReader & anOriginal);
  XmlReceptReader & operator=(const XmlReceptReader & anOriginal);
};


}

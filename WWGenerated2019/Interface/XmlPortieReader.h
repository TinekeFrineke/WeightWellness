#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlPortie; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlPortieReader : public XmlClass
{
public:
  XmlPortieReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPortie *& aXmlPortie);
  XmlPortie * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortie & Portie);

private:
  // Prohibit copying and assignment
  XmlPortieReader(const XmlPortieReader & anOriginal);
  XmlPortieReader & operator=(const XmlPortieReader & anOriginal);
};


}

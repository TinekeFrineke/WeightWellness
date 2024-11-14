#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlPortie; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
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

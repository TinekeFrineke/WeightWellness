#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlDag; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlDagReader : public XmlClass
{
public:
  XmlDagReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlDag *& aXmlDag);
  XmlDag * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlDag & Dag);

private:
  // Prohibit copying and assignment
  XmlDagReader(const XmlDagReader & anOriginal);
  XmlDagReader & operator=(const XmlDagReader & anOriginal);
};


}

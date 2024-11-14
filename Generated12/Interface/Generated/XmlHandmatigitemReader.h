#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlHandmatigitem; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlHandmatigitemReader : public XmlClass
{
public:
  XmlHandmatigitemReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlHandmatigitem *& aXmlHandmatigitem);
  XmlHandmatigitem * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlHandmatigitem & Handmatigitem);

private:
  // Prohibit copying and assignment
  XmlHandmatigitemReader(const XmlHandmatigitemReader & anOriginal);
  XmlHandmatigitemReader & operator=(const XmlHandmatigitemReader & anOriginal);
};


}

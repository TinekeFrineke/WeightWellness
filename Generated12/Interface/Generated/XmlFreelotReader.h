#pragma once
#include "../Interface\Generated\stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface\Generated\XmlClass.h"

// forward declarations
namespace ww_1_2 { class XmlFreelot; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_2
{
class XmlFreelotReader : public XmlClass
{
public:
  XmlFreelotReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlFreelot *& aXmlFreelot);
  XmlFreelot * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlFreelot & Freelot);

private:
  // Prohibit copying and assignment
  XmlFreelotReader(const XmlFreelotReader & anOriginal);
  XmlFreelotReader & operator=(const XmlFreelotReader & anOriginal);
};


}

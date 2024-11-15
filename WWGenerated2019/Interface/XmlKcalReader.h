#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019{ class XmlKcal; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlKcalReader : public XmlClass
{
public:
  XmlKcalReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlKcal *& aKcal);
  XmlKcal * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlKcal & aKcal);

private:
  // Prohibit copying and assignment
  XmlKcalReader(const XmlKcalReader & anOriginal);
  XmlKcalReader & operator=(const XmlKcalReader & anOriginal);
};


}

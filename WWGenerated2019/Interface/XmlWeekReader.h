#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019{ class XmlWeek; }
XERCES_CPP_NAMESPACE_BEGIN
class DOMDocument;
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlWeekReader : public XmlClass
{
public:
  XmlWeekReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlWeek *& aWeek);
  XmlWeek * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);
  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlWeek & aWeek);

private:
  // Prohibit copying and assignment
  XmlWeekReader(const XmlWeekReader & anOriginal);
  XmlWeekReader & operator=(const XmlWeekReader & anOriginal);
};


}

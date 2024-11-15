#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>

#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlKcal; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMDocument;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlKcalWriter : public XmlClass
{
public:
  XmlClass::eRESULT Write(const std::wstring & aFilename, const XmlKcal & aKcal);
  void Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlKcal & aKcal, XERCES_CPP_NAMESPACE::DOMElement & anElement);
};


}

#pragma once
#include "../Interface/stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "../Interface/XmlClass.h"

// forward declarations
namespace ww2019 { class XmlPuntenper100; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2019
{
class XmlPuntenper100Reader : public XmlClass
{
public:
  XmlPuntenper100Reader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPuntenper100 *& aXmlPuntenper100);
  XmlPuntenper100 * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPuntenper100 & Puntenper100);

private:
  // Prohibit copying and assignment
  XmlPuntenper100Reader(const XmlPuntenper100Reader & anOriginal);
  XmlPuntenper100Reader & operator=(const XmlPuntenper100Reader & anOriginal);
};


}

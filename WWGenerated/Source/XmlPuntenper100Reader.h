#ifndef ww_1_1_Projects_VC10_WW_WWGenerated_XmlPuntenper100Reader_h__
#define ww_1_1_Projects_VC10_WW_WWGenerated_XmlPuntenper100Reader_h__


#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww_1_1 { class XmlPuntenper100; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww_1_1
{
class XmlPuntenper100Reader : public Generator::XmlClass
{
public:
  XmlPuntenper100Reader();

  Generator::XmlClass::eRESULT Read(const std::wstring & aFilename, XmlPuntenper100 *& aXmlPuntenper100);
  XmlPuntenper100 * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  Generator::XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPuntenper100 & Puntenper100);

private:
  // Prohibit copying and assignment
  XmlPuntenper100Reader(const XmlPuntenper100Reader & anOriginal);
  XmlPuntenper100Reader & operator=(const XmlPuntenper100Reader & anOriginal);
};


}
#endif // Projects_VC10_WW_WWGenerated_XmlPuntenper100Reader_h__

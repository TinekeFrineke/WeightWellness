#pragma once
#include "stdafx.h"

#include <xercesc/util/xercesdefs.hpp>
#include <string>
#include "XmlClass.h"

// forward declarations
namespace ww2015 { class XmlStrategybase; }

XERCES_CPP_NAMESPACE_BEGIN
class DOMNode;
XERCES_CPP_NAMESPACE_END

namespace ww2015
{
class XmlStrategybaseReader : public XmlClass
{
public:
  XmlStrategybaseReader();

  XmlClass::eRESULT Read(const std::wstring & aFilename, XmlStrategybase *& aXmlStrategybase);
  XmlStrategybase * Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement);

  XmlClass::eRESULT Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlStrategybase & Strategybase);

private:
  // Prohibit copying and assignment
  XmlStrategybaseReader(const XmlStrategybaseReader & anOriginal);
  XmlStrategybaseReader & operator=(const XmlStrategybaseReader & anOriginal);
};


}

#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlUnit.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlUnitWriter.h"

namespace ww_1_2
{
XERCES_CPP_NAMESPACE::DOMNode * XmlUnitWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlUnit & aUnit)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("unit"));
  Fill(aDocument, aUnit, *element);
  return element;
}

void XmlUnitWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlUnit & aUnit, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aUnit;
  (void)anElement;
  anElement.setAttribute(_T("naam"), aUnit.Getnaam().c_str());
}


}

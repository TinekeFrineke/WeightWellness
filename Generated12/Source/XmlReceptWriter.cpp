#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlRecept.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlReceptWriter.h"

namespace ww_1_2
{
XERCES_CPP_NAMESPACE::DOMNode * XmlReceptWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlRecept & aRecept)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("recept"));
  Fill(aDocument, aRecept, *element);
  return element;
}

void XmlReceptWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlRecept & aRecept, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aRecept;
  (void)anElement;
  anElement.setAttribute(_T("naam"), aRecept.Getnaam().c_str());
  anElement.setAttribute(_T("punten"), aRecept.Getpunten().c_str());
  anElement.setAttribute(_T("hoeveelheid"), aRecept.Gethoeveelheid().c_str());
}


}

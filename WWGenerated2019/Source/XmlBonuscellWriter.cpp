#include "../Interface/stdafx.h"

#include "../Interface/XmlBonuscell.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlBonuscellWriter.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlBonuscellWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuscell & aBonuscell)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("bonuscell"));
  Fill(aDocument, aBonuscell, *element);
  return element;
}

void XmlBonuscellWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuscell & aBonuscell, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aBonuscell;
  (void)anElement;
  {
    TCHAR buffer[1024];
    _itot_s(aBonuscell.Getgewicht(), buffer, 1024, 10);
    anElement.setAttribute(_T("gewicht"), buffer);
  }
  switch (aBonuscell.Getintensiteit())
  {
    case XmlBonuscell::intensiteit_laag:
      anElement.setAttribute(_T("intensiteit"), _T("laag"));
    break;
    case XmlBonuscell::intensiteit_middel:
      anElement.setAttribute(_T("intensiteit"), _T("middel"));
    break;
    case XmlBonuscell::intensiteit_hoog:
      anElement.setAttribute(_T("intensiteit"), _T("hoog"));
    break;
    default:
      throw 1;
  }
  {
    TCHAR buffer[1024];
    _itot_s(aBonuscell.Getminuten(), buffer, 1024, 10);
    anElement.setAttribute(_T("minuten"), buffer);
  }
  {
    TCHAR buffer[1024];
    _itot_s(aBonuscell.Getpunten(), buffer, 1024, 10);
    anElement.setAttribute(_T("punten"), buffer);
  }
}


}

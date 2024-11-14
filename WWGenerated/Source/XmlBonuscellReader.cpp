#include "stdafx.h"
#include "XmlBonuscellReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlBonuscell.h"


namespace ww_1_1
{
XmlBonuscellReader::XmlBonuscellReader()
{
}


XmlBonuscell * XmlBonuscellReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlBonuscell * Bonuscell = new XmlBonuscell;
  Fill(anElement, *Bonuscell);
  return Bonuscell;
}

Generator::XmlClass::eRESULT XmlBonuscellReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuscell & aBonuscell)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return Generator::XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * gewichtnode = attributes->getNamedItem(_T("gewicht"));
    if (gewichtnode != NULL)
    {
      aBonuscell.Setgewicht(_ttoi(gewichtnode->getNodeValue()));
    }
    XERCES_CPP_NAMESPACE::DOMNode * intensiteitnode = attributes->getNamedItem(_T("intensiteit"));
    if (intensiteitnode != NULL)
    {
      if (_tcscmp(intensiteitnode->getNodeValue(), _T("laag")) == 0)
        aBonuscell.Setintensiteit(XmlBonuscell::intensiteit_laag);
      else if (_tcscmp(intensiteitnode->getNodeValue(), _T("middel")) == 0)
        aBonuscell.Setintensiteit(XmlBonuscell::intensiteit_middel);
      else if (_tcscmp(intensiteitnode->getNodeValue(), _T("hoog")) == 0)
        aBonuscell.Setintensiteit(XmlBonuscell::intensiteit_hoog);
    }
    XERCES_CPP_NAMESPACE::DOMNode * minutennode = attributes->getNamedItem(_T("minuten"));
    if (minutennode != NULL)
    {
      aBonuscell.Setminuten(_ttoi(minutennode->getNodeValue()));
    }
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
    {
      aBonuscell.Setpunten(_ttoi(puntennode->getNodeValue()));
    }
  }

  return Generator::XmlClass::RESULT_Ok;
}


}

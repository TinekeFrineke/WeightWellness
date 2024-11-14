#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlGerechtReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlGerecht.h"


namespace ww_1_2
{
XmlGerechtReader::XmlGerechtReader()
{
}


XmlGerecht * XmlGerechtReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlGerecht * Gerecht = new XmlGerecht;
  Fill(anElement, *Gerecht);
  return Gerecht;
}

XmlClass::eRESULT XmlGerechtReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlGerecht & aGerecht)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != NULL)
      aGerecht.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aGerecht.Setpunten(puntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * hoeveelheidnode = attributes->getNamedItem(_T("hoeveelheid"));
    if (hoeveelheidnode != NULL)
      aGerecht.Sethoeveelheid(hoeveelheidnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

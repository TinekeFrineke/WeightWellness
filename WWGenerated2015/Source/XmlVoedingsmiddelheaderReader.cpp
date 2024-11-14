#include "stdafx.h"
#include "XmlVoedingsmiddelheaderReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddelheader.h"


namespace ww2015
{
XmlVoedingsmiddelheaderReader::XmlVoedingsmiddelheaderReader()
{
}


XmlVoedingsmiddelheader * XmlVoedingsmiddelheaderReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlVoedingsmiddelheader * Voedingsmiddelheader = new XmlVoedingsmiddelheader;
  Fill(anElement, *Voedingsmiddelheader);
  return Voedingsmiddelheader;
}

XmlClass::eRESULT XmlVoedingsmiddelheaderReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelheader & aVoedingsmiddelheader)
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
      aVoedingsmiddelheader.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * categorienode = attributes->getNamedItem(_T("categorie"));
    if (categorienode != NULL)
      aVoedingsmiddelheader.Setcategorie(categorienode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * merknode = attributes->getNamedItem(_T("merk"));
    if (merknode != NULL)
      aVoedingsmiddelheader.Setmerk(merknode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * unitnode = attributes->getNamedItem(_T("unit"));
    if (unitnode != NULL)
      aVoedingsmiddelheader.Setunit(unitnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

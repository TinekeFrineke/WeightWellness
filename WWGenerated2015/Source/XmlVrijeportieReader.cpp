#include "stdafx.h"
#include "XmlVrijeportieReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVrijeportie.h"


namespace ww2015
{
XmlVrijeportieReader::XmlVrijeportieReader()
{
}


XmlVrijeportie * XmlVrijeportieReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlVrijeportie * Vrijeportie = new XmlVrijeportie;
  Fill(anElement, *Vrijeportie);
  return Vrijeportie;
}

XmlClass::eRESULT XmlVrijeportieReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVrijeportie & aVrijeportie)
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
    XERCES_CPP_NAMESPACE::DOMNode * voedingsmiddelnode = attributes->getNamedItem(_T("voedingsmiddel"));
    if (voedingsmiddelnode != NULL)
      aVrijeportie.Setvoedingsmiddel(voedingsmiddelnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aVrijeportie.Setpunten(puntennode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

#include "stdafx.h"
#include "XmlSterrelotReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlSterrelot.h"


namespace ww2015
{
XmlSterrelotReader::XmlSterrelotReader()
{
}


XmlSterrelot * XmlSterrelotReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlSterrelot * Sterrelot = new XmlSterrelot;
  Fill(anElement, *Sterrelot);
  return Sterrelot;
}

XmlClass::eRESULT XmlSterrelotReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlSterrelot & aSterrelot)
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
      aSterrelot.Setvoedingsmiddel(voedingsmiddelnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * portienode = attributes->getNamedItem(_T("portie"));
    if (portienode != NULL)
      aSterrelot.Setportie(portienode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * hoeveelheidnode = attributes->getNamedItem(_T("hoeveelheid"));
    if (hoeveelheidnode != NULL)
      aSterrelot.Sethoeveelheid(hoeveelheidnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

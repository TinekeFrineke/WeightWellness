#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlPortieomschrijvingReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlPortieomschrijving.h"


namespace ww_1_2
{
XmlPortieomschrijvingReader::XmlPortieomschrijvingReader()
{
}


XmlPortieomschrijving * XmlPortieomschrijvingReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlPortieomschrijving * Portieomschrijving = new XmlPortieomschrijving;
  Fill(anElement, *Portieomschrijving);
  return Portieomschrijving;
}

XmlClass::eRESULT XmlPortieomschrijvingReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPortieomschrijving & aPortieomschrijving)
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
    XERCES_CPP_NAMESPACE::DOMNode * omschrijvingnode = attributes->getNamedItem(_T("omschrijving"));
    if (omschrijvingnode != NULL)
      aPortieomschrijving.Setomschrijving(omschrijvingnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

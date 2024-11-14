#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlReceptReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlRecept.h"


namespace ww_1_2
{
XmlReceptReader::XmlReceptReader()
{
}


XmlRecept * XmlReceptReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlRecept * Recept = new XmlRecept;
  Fill(anElement, *Recept);
  return Recept;
}

XmlClass::eRESULT XmlReceptReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlRecept & aRecept)
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
      aRecept.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aRecept.Setpunten(puntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * hoeveelheidnode = attributes->getNamedItem(_T("hoeveelheid"));
    if (hoeveelheidnode != NULL)
      aRecept.Sethoeveelheid(hoeveelheidnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

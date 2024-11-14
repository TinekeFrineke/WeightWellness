#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlFreelotReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlFreelot.h"


namespace ww_1_2
{
XmlFreelotReader::XmlFreelotReader()
{
}


XmlFreelot * XmlFreelotReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlFreelot * Freelot = new XmlFreelot;
  Fill(anElement, *Freelot);
  return Freelot;
}

XmlClass::eRESULT XmlFreelotReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlFreelot & aFreelot)
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
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aFreelot.Setpunten(puntennode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

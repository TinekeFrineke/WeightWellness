#include "stdafx.h"
#include "XmlVrijeportiesReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVrijeporties.h"
#include "XmlVrijeportieReader.h"
#include "XmlVrijeportie.h"


namespace ww2015
{
XmlVrijeportiesReader::XmlVrijeportiesReader()
{
}


XmlVrijeporties * XmlVrijeportiesReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlVrijeporties * Vrijeporties = new XmlVrijeporties;
  Fill(anElement, *Vrijeporties);
  return Vrijeporties;
}

XmlClass::eRESULT XmlVrijeportiesReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVrijeporties & aVrijeporties)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

    short type = list->item(i)->getNodeType();
    XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

    if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
    {
     if (_tcscmp(node->getNodeName(), _T("vrijeportie")) == 0)
     {
       XmlVrijeportieReader VrijeportieReader;
       XmlVrijeportie * Vrijeportie = VrijeportieReader.Generate(*node);
       if (Vrijeportie != NULL)
         aVrijeporties.Add(Vrijeportie);
     }
   }
  }
  return XmlClass::RESULT_Ok;
}


}

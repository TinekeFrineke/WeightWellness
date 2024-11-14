#include "stdafx.h"
#include "XmlVoedingsmiddelReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddel.h"
#include "XmlStandardlotReader.h"
#include "XmlStandardlot.h"
#include "XmlFreelotReader.h"
#include "XmlFreelot.h"


namespace ww_1_1
{
XmlVoedingsmiddelReader::XmlVoedingsmiddelReader()
{
}


XmlVoedingsmiddel * XmlVoedingsmiddelReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlVoedingsmiddel * Voedingsmiddel = new XmlVoedingsmiddel;
  Fill(anElement, *Voedingsmiddel);
  return Voedingsmiddel;
}

Generator::XmlClass::eRESULT XmlVoedingsmiddelReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddel & aVoedingsmiddel)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return Generator::XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

    short type = list->item(i)->getNodeType();
    XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

    if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
    {
     if (_tcscmp(node->getNodeName(), _T("standardlot")) == 0)
     {
       XmlStandardlotReader StandardlotReader;
       XmlStandardlot * Standardlot = StandardlotReader.Generate(*node);
       if (Standardlot != NULL)
         aVoedingsmiddel.Add(Standardlot);
     }
     else if (_tcscmp(node->getNodeName(), _T("freelot")) == 0)
     {
       XmlFreelotReader FreelotReader;
       XmlFreelot * Freelot = FreelotReader.Generate(*node);
       if (Freelot != NULL)
         aVoedingsmiddel.Add(Freelot);
     }
   }
  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != NULL)
      aVoedingsmiddel.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * categorienode = attributes->getNamedItem(_T("categorie"));
    if (categorienode != NULL)
      aVoedingsmiddel.Setcategorie(categorienode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * merknode = attributes->getNamedItem(_T("merk"));
    if (merknode != NULL)
      aVoedingsmiddel.Setmerk(merknode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * unitnode = attributes->getNamedItem(_T("unit"));
    if (unitnode != NULL)
      aVoedingsmiddel.Setunit(unitnode->getNodeValue());
  }

  return Generator::XmlClass::RESULT_Ok;
}


}

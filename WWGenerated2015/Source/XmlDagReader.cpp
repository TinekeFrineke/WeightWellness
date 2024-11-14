#include "stdafx.h"
#include "XmlDagReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlDag.h"
#include "XmlVoedingsmiddelReader.h"
#include "XmlVoedingsmiddel.h"
#include "XmlReceptReader.h"
#include "XmlRecept.h"
#include "XmlGerechtReader.h"
#include "XmlGerecht.h"
#include "XmlHandmatigitemReader.h"
#include "XmlHandmatigitem.h"
#include "XmlBonuscellReader.h"
#include "XmlBonuscell.h"


namespace ww2015
{
XmlDagReader::XmlDagReader()
{
}


XmlDag * XmlDagReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlDag * Dag = new XmlDag;
  Fill(anElement, *Dag);
  return Dag;
}

XmlClass::eRESULT XmlDagReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlDag & aDag)
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
     if (_tcscmp(node->getNodeName(), _T("voedingsmiddel")) == 0)
     {
       XmlVoedingsmiddelReader VoedingsmiddelReader;
       XmlVoedingsmiddel * Voedingsmiddel = VoedingsmiddelReader.Generate(*node);
       if (Voedingsmiddel != NULL)
         aDag.Add(Voedingsmiddel);
     }
     else if (_tcscmp(node->getNodeName(), _T("recept")) == 0)
     {
       XmlReceptReader ReceptReader;
       XmlRecept * Recept = ReceptReader.Generate(*node);
       if (Recept != NULL)
         aDag.Add(Recept);
     }
     else if (_tcscmp(node->getNodeName(), _T("gerecht")) == 0)
     {
       XmlGerechtReader GerechtReader;
       XmlGerecht * Gerecht = GerechtReader.Generate(*node);
       if (Gerecht != NULL)
         aDag.Add(Gerecht);
     }
     else if (_tcscmp(node->getNodeName(), _T("handmatigitem")) == 0)
     {
       XmlHandmatigitemReader HandmatigitemReader;
       XmlHandmatigitem * Handmatigitem = HandmatigitemReader.Generate(*node);
       if (Handmatigitem != NULL)
         aDag.Add(Handmatigitem);
     }
     else if (_tcscmp(node->getNodeName(), _T("bonuscell")) == 0)
     {
       XmlBonuscellReader BonuscellReader;
       XmlBonuscell * Bonuscell = BonuscellReader.Generate(*node);
       if (Bonuscell != NULL)
         aDag.Add(Bonuscell);
     }
   }
  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * bonuspuntennode = attributes->getNamedItem(_T("bonuspunten"));
    if (bonuspuntennode != NULL)
      aDag.Setbonuspunten(bonuspuntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * datumnode = attributes->getNamedItem(_T("datum"));
    if (datumnode != NULL)
      aDag.Setdatum(datumnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * gewichtnode = attributes->getNamedItem(_T("gewicht"));
    if (gewichtnode != NULL)
      aDag.Setgewicht(gewichtnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

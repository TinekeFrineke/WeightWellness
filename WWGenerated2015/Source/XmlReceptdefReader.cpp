#include "stdafx.h"
#include "XmlReceptdefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlReceptdef.h"
#include "XmlVoedingsmiddelReader.h"
#include "XmlVoedingsmiddel.h"
#include "XmlReceptReader.h"
#include "XmlRecept.h"
#include "XmlGerechtReader.h"
#include "XmlGerecht.h"
#include "XmlHandmatigitemReader.h"
#include "XmlHandmatigitem.h"


namespace ww2015
{
XmlReceptdefReader::XmlReceptdefReader()
{
}


XmlReceptdef * XmlReceptdefReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlReceptdef * Receptdef = new XmlReceptdef;
  Fill(anElement, *Receptdef);
  return Receptdef;
}

XmlClass::eRESULT XmlReceptdefReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdef & aReceptdef)
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
         aReceptdef.Add(Voedingsmiddel);
     }
     else if (_tcscmp(node->getNodeName(), _T("recept")) == 0)
     {
       XmlReceptReader ReceptReader;
       XmlRecept * Recept = ReceptReader.Generate(*node);
       if (Recept != NULL)
         aReceptdef.Add(Recept);
     }
     else if (_tcscmp(node->getNodeName(), _T("gerecht")) == 0)
     {
       XmlGerechtReader GerechtReader;
       XmlGerecht * Gerecht = GerechtReader.Generate(*node);
       if (Gerecht != NULL)
         aReceptdef.Add(Gerecht);
     }
     else if (_tcscmp(node->getNodeName(), _T("handmatigitem")) == 0)
     {
       XmlHandmatigitemReader HandmatigitemReader;
       XmlHandmatigitem * Handmatigitem = HandmatigitemReader.Generate(*node);
       if (Handmatigitem != NULL)
         aReceptdef.Add(Handmatigitem);
     }
   }
  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != NULL)
      aReceptdef.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * portiesnode = attributes->getNamedItem(_T("porties"));
    if (portiesnode != NULL)
      aReceptdef.Setporties(portiesnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

#include "stdafx.h"
#include "XmlVoedingsmiddeldefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddeldef.h"
#include "XmlVoedingswaardeReader.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100Reader.h"
#include "XmlPuntenper100.h"
#include "XmlVoedingsmiddelheaderReader.h"
#include "XmlVoedingsmiddelheader.h"
#include "XmlPortieReader.h"
#include "XmlPortie.h"


namespace ww2015
{
XmlVoedingsmiddeldefReader::XmlVoedingsmiddeldefReader()
{
}


XmlVoedingsmiddeldef * XmlVoedingsmiddeldefReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlVoedingsmiddeldef * Voedingsmiddeldef = new XmlVoedingsmiddeldef;
  Fill(anElement, *Voedingsmiddeldef);
  return Voedingsmiddeldef;
}

XmlClass::eRESULT XmlVoedingsmiddeldefReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldef & aVoedingsmiddeldef)
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
     if (_tcscmp(node->getNodeName(), _T("voedingswaarde")) == 0)
     {
       XmlVoedingswaardeReader VoedingswaardeReader;
       XmlVoedingswaarde * Voedingswaarde = VoedingswaardeReader.Generate(*node);
       if (Voedingswaarde != NULL)
         aVoedingsmiddeldef.Add(Voedingswaarde);
     }
     else if (_tcscmp(node->getNodeName(), _T("puntenper100")) == 0)
     {
       XmlPuntenper100Reader Puntenper100Reader;
       XmlPuntenper100 * Puntenper100 = Puntenper100Reader.Generate(*node);
       if (Puntenper100 != NULL)
         aVoedingsmiddeldef.Add(Puntenper100);
     }
     else if (_tcscmp(node->getNodeName(), _T("voedingsmiddelheader")) == 0)
     {
       XmlVoedingsmiddelheaderReader VoedingsmiddelheaderReader;
       XmlVoedingsmiddelheader & Voedingsmiddelheader = aVoedingsmiddeldef.GetVoedingsmiddelheader();
       VoedingsmiddelheaderReader.Fill(*node, Voedingsmiddelheader);
     }
     else if (_tcscmp(node->getNodeName(), _T("portie")) == 0)
     {
       XmlPortieReader PortieReader;
       XmlPortie * Portie = PortieReader.Generate(*node);
       if (Portie != NULL)
         aVoedingsmiddeldef.Add(Portie);
     }
   }
  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * favorietnode = attributes->getNamedItem(_T("favoriet"));
    if (favorietnode != NULL)
    {
      if (_tcscmp(favorietnode->getNodeValue(), _T("true")) == 0)
        aVoedingsmiddeldef.Setfavoriet(XmlVoedingsmiddeldef::favoriet_true);
      else if (_tcscmp(favorietnode->getNodeValue(), _T("false")) == 0)
        aVoedingsmiddeldef.Setfavoriet(XmlVoedingsmiddeldef::favoriet_false);
    }
  }

  return XmlClass::RESULT_Ok;
}


}

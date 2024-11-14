#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlVoedingsmiddeldefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlVoedingsmiddeldef.h"
#include "../Interface\Generated\XmlVoedingswaardeReader.h"
#include "../Interface\Generated\XmlVoedingswaarde.h"
#include "../Interface\Generated\XmlPortieReader.h"
#include "../Interface\Generated\XmlPortie.h"
#include "../Interface\Generated\XmlPuntenper100Reader.h"
#include "../Interface\Generated\XmlPuntenper100.h"
#include "../Interface\Generated\XmlVoedingsmiddelbasisReader.h"
#include "../Interface\Generated\XmlVoedingsmiddelbasis.h"


namespace ww_1_2
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
     else if (_tcscmp(node->getNodeName(), _T("portie")) == 0)
     {
       XmlPortieReader PortieReader;
       XmlPortie * Portie = PortieReader.Generate(*node);
       if (Portie != NULL)
         aVoedingsmiddeldef.Add(Portie);
     }
     else if (_tcscmp(node->getNodeName(), _T("puntenper100")) == 0)
     {
       XmlPuntenper100Reader Puntenper100Reader;
       XmlPuntenper100 * Puntenper100 = Puntenper100Reader.Generate(*node);
       if (Puntenper100 != NULL)
         aVoedingsmiddeldef.Add(Puntenper100);
     }
     else if (_tcscmp(node->getNodeName(), _T("voedingsmiddelbasis")) == 0)
     {
       XmlVoedingsmiddelbasisReader VoedingsmiddelbasisReader;
       XmlVoedingsmiddelbasis & Voedingsmiddelbasis = aVoedingsmiddeldef.GetVoedingsmiddelbasis();
       VoedingsmiddelbasisReader.Fill(*node, Voedingsmiddelbasis);
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

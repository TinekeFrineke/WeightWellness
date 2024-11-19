//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddeldefReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlVoedingsmiddeldef.h"
#include "XmlVoedingsmiddelheaderReader.h"
#include "XmlVoedingsmiddelheader.h"
#include "XmlPortieReader.h"
#include "XmlPortie.h"
#include "XmlVoedingswaardeReader.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100Reader.h"
#include "XmlPuntenper100.h"


namespace ww2019
{
XmlVoedingsmiddeldefReader::XmlVoedingsmiddeldefReader()
{
}


std::unique_ptr<XmlVoedingsmiddeldef> XmlVoedingsmiddeldefReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto voedingsmiddeldef = std::make_unique<XmlVoedingsmiddeldef>();
    Fill(anElement, *voedingsmiddeldef);
    return voedingsmiddeldef;
}

XmlClass::Result XmlVoedingsmiddeldefReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldef & aVoedingsmiddeldef)
{
    const XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

    if (list == nullptr)
        return XmlClass::Result::Ok;

    for (XMLSize_t i = 0; i < list->getLength(); i++) {
        if (list->item(i) == nullptr)
            continue;

        short type = list->item(i)->getNodeType();
        XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

        if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE) {
     if (_tcscmp(node->getNodeName(), _T("voedingsmiddelheader")) == 0)
     {
         XmlVoedingsmiddelheaderReader VoedingsmiddelheaderReader;
         XmlVoedingsmiddelheader & Voedingsmiddelheader = aVoedingsmiddeldef.GetVoedingsmiddelheader();
         VoedingsmiddelheaderReader.Fill(*node, Voedingsmiddelheader);
     }
     else if (_tcscmp(node->getNodeName(), _T("portie")) == 0)
     {
         XmlPortieReader portieReader;
         auto portie = portieReader.Generate(*node);
         if (portie != nullptr)
             aVoedingsmiddeldef.Add(std::move(portie));
     }
     else if (_tcscmp(node->getNodeName(), _T("voedingswaarde")) == 0)
     {
         XmlVoedingswaardeReader voedingswaardeReader;
         auto voedingswaarde = voedingswaardeReader.Generate(*node);
         if (voedingswaarde != nullptr)
             aVoedingsmiddeldef.Add(std::move(voedingswaarde));
     }
     else if (_tcscmp(node->getNodeName(), _T("puntenper100")) == 0)
     {
         XmlPuntenper100Reader puntenper100Reader;
         auto puntenper100 = puntenper100Reader.Generate(*node);
         if (puntenper100 != nullptr)
             aVoedingsmiddeldef.Add(std::move(puntenper100));
     }
   }
  }
    const XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* favorietnode = attributes->getNamedItem(_T("favoriet"));
    if (favorietnode != nullptr)
    {
      if (_tcscmp(favorietnode->getNodeValue(), _T("yes")) == 0)
        aVoedingsmiddeldef.Setfavoriet(XmlVoedingsmiddeldef::favoriet::yes);
      else if (_tcscmp(favorietnode->getNodeValue(), _T("no")) == 0)
        aVoedingsmiddeldef.Setfavoriet(XmlVoedingsmiddeldef::favoriet::no);
    }
    }

    return XmlClass::Result::Ok;
}


}

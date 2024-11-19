//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlStandardlotReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlStandardlot.h"
#include "XmlPortieReader.h"
#include "XmlPortie.h"
#include "XmlVoedingswaardeReader.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100Reader.h"
#include "XmlPuntenper100.h"


namespace ww2019
{
XmlStandardlotReader::XmlStandardlotReader()
{
}


std::unique_ptr<XmlStandardlot> XmlStandardlotReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto standardlot = std::make_unique<XmlStandardlot>();
    Fill(anElement, *standardlot);
    return standardlot;
}

XmlClass::Result XmlStandardlotReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlStandardlot & aStandardlot)
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
     if (_tcscmp(node->getNodeName(), _T("portie")) == 0)
     {
         XmlPortieReader PortieReader;
         XmlPortie & Portie = aStandardlot.GetPortie();
         PortieReader.Fill(*node, Portie);
     }
     else if (_tcscmp(node->getNodeName(), _T("voedingswaarde")) == 0)
     {
         XmlVoedingswaardeReader voedingswaardeReader;
         auto voedingswaarde = voedingswaardeReader.Generate(*node);
         if (voedingswaarde != nullptr)
             aStandardlot.Add(std::move(voedingswaarde));
     }
     else if (_tcscmp(node->getNodeName(), _T("puntenper100")) == 0)
     {
         XmlPuntenper100Reader puntenper100Reader;
         auto puntenper100 = puntenper100Reader.Generate(*node);
         if (puntenper100 != nullptr)
             aStandardlot.Add(std::move(puntenper100));
     }
   }
  }
    const XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* hoeveelheidnode = attributes->getNamedItem(_T("hoeveelheid"));
    if (hoeveelheidnode != nullptr)
      aStandardlot.Sethoeveelheid(hoeveelheidnode->getNodeValue());
    }

    return XmlClass::Result::Ok;
}


}

//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlBonuslistReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlBonuslist.h"
#include "XmlBonuscellReader.h"
#include "XmlBonuscell.h"


namespace ww2019
{
XmlBonuslistReader::XmlBonuslistReader()
{
}


std::unique_ptr<XmlBonuslist> XmlBonuslistReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto bonuslist = std::make_unique<XmlBonuslist>();
    Fill(anElement, *bonuslist);
    return bonuslist;
}

XmlClass::Result XmlBonuslistReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuslist & aBonuslist)
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
     if (_tcscmp(node->getNodeName(), _T("bonuscell")) == 0)
     {
         XmlBonuscellReader bonuscellReader;
         auto bonuscell = bonuscellReader.Generate(*node);
         if (bonuscell != nullptr)
             aBonuslist.Add(std::move(bonuscell));
     }
   }
  }
    return XmlClass::Result::Ok;
}


}

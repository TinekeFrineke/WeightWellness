#include "stdafx.h"
#include "XmlBonuslistReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlBonuslist.h"
#include "XmlBonuscellReader.h"
#include "XmlBonuscell.h"


namespace ww2015
{
XmlBonuslistReader::XmlBonuslistReader()
{
}


XmlBonuslist * XmlBonuslistReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlBonuslist * Bonuslist = new XmlBonuslist;
  Fill(anElement, *Bonuslist);
  return Bonuslist;
}

XmlClass::eRESULT XmlBonuslistReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlBonuslist & aBonuslist)
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
     if (_tcscmp(node->getNodeName(), _T("bonuscell")) == 0)
     {
       XmlBonuscellReader BonuscellReader;
       XmlBonuscell * Bonuscell = BonuscellReader.Generate(*node);
       if (Bonuscell != NULL)
         aBonuslist.Add(Bonuscell);
     }
   }
  }
  return XmlClass::RESULT_Ok;
}


}

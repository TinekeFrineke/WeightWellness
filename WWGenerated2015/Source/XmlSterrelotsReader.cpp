#include "stdafx.h"
#include "XmlSterrelotsReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlSterrelots.h"
#include "XmlSterrelotReader.h"
#include "XmlSterrelot.h"


namespace ww2015
{
XmlSterrelotsReader::XmlSterrelotsReader()
{
}


XmlSterrelots * XmlSterrelotsReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlSterrelots * Sterrelots = new XmlSterrelots;
  Fill(anElement, *Sterrelots);
  return Sterrelots;
}

XmlClass::eRESULT XmlSterrelotsReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlSterrelots & aSterrelots)
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
     if (_tcscmp(node->getNodeName(), _T("sterrelot")) == 0)
     {
       XmlSterrelotReader SterrelotReader;
       XmlSterrelot * Sterrelot = SterrelotReader.Generate(*node);
       if (Sterrelot != NULL)
         aSterrelots.Add(Sterrelot);
     }
   }
  }
  return XmlClass::RESULT_Ok;
}


}

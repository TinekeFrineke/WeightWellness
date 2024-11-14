#include "stdafx.h"
#include "XmlStandardlotReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "XmlStandardlot.h"
#include "XmlVoedingswaardeReader.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100Reader.h"
#include "XmlPuntenper100.h"
#include "XmlPortieReader.h"
#include "XmlPortie.h"


namespace ww2015
{
XmlStandardlotReader::XmlStandardlotReader()
{
}


XmlStandardlot * XmlStandardlotReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlStandardlot * Standardlot = new XmlStandardlot;
  Fill(anElement, *Standardlot);
  return Standardlot;
}

XmlClass::eRESULT XmlStandardlotReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlStandardlot & aStandardlot)
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
         aStandardlot.Add(Voedingswaarde);
     }
     else if (_tcscmp(node->getNodeName(), _T("puntenper100")) == 0)
     {
       XmlPuntenper100Reader Puntenper100Reader;
       XmlPuntenper100 * Puntenper100 = Puntenper100Reader.Generate(*node);
       if (Puntenper100 != NULL)
         aStandardlot.Add(Puntenper100);
     }
     else if (_tcscmp(node->getNodeName(), _T("portie")) == 0)
     {
       XmlPortieReader PortieReader;
       XmlPortie & Portie = aStandardlot.GetPortie();
       PortieReader.Fill(*node, Portie);
     }
   }
  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * hoeveelheidnode = attributes->getNamedItem(_T("hoeveelheid"));
    if (hoeveelheidnode != NULL)
      aStandardlot.Sethoeveelheid(hoeveelheidnode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

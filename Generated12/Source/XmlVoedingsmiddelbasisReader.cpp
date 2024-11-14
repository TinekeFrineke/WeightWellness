#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlVoedingsmiddelbasisReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "../Interface\Generated\XmlVoedingsmiddelbasis.h"
#include "../Interface\Generated\XmlVoedingsmiddelheaderReader.h"
#include "../Interface\Generated\XmlVoedingsmiddelheader.h"


namespace ww_1_2
{
XmlVoedingsmiddelbasisReader::XmlVoedingsmiddelbasisReader()
{
}


XmlVoedingsmiddelbasis * XmlVoedingsmiddelbasisReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlVoedingsmiddelbasis * Voedingsmiddelbasis = new XmlVoedingsmiddelbasis;
  Fill(anElement, *Voedingsmiddelbasis);
  return Voedingsmiddelbasis;
}

XmlClass::eRESULT XmlVoedingsmiddelbasisReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddelbasis & aVoedingsmiddelbasis)
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
     if (_tcscmp(node->getNodeName(), _T("voedingsmiddelheader")) == 0)
     {
       XmlVoedingsmiddelheaderReader VoedingsmiddelheaderReader;
       XmlVoedingsmiddelheader & Voedingsmiddelheader = aVoedingsmiddelbasis.GetVoedingsmiddelheader();
       VoedingsmiddelheaderReader.Fill(*node, Voedingsmiddelheader);
     }
   }
  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * sterreportienode = attributes->getNamedItem(_T("sterreportie"));
    if (sterreportienode != NULL)
      aVoedingsmiddelbasis.Setsterreportie(sterreportienode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * vrijeportienode = attributes->getNamedItem(_T("vrijeportie"));
    if (vrijeportienode != NULL)
    {
      if (_tcscmp(vrijeportienode->getNodeValue(), _T("true")) == 0)
        aVoedingsmiddelbasis.Setvrijeportie(XmlVoedingsmiddelbasis::vrijeportie_true);
      else if (_tcscmp(vrijeportienode->getNodeValue(), _T("false")) == 0)
        aVoedingsmiddelbasis.Setvrijeportie(XmlVoedingsmiddelbasis::vrijeportie_false);
    }
    XERCES_CPP_NAMESPACE::DOMNode * vrijepuntennode = attributes->getNamedItem(_T("vrijepunten"));
    if (vrijepuntennode != NULL)
      aVoedingsmiddelbasis.Setvrijepunten(vrijepuntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * vrijeppportienode = attributes->getNamedItem(_T("vrijeppportie"));
    if (vrijeppportienode != NULL)
    {
      if (_tcscmp(vrijeppportienode->getNodeValue(), _T("true")) == 0)
        aVoedingsmiddelbasis.Setvrijeppportie(XmlVoedingsmiddelbasis::vrijeppportie_true);
      else if (_tcscmp(vrijeppportienode->getNodeValue(), _T("false")) == 0)
        aVoedingsmiddelbasis.Setvrijeppportie(XmlVoedingsmiddelbasis::vrijeppportie_false);
    }
    XERCES_CPP_NAMESPACE::DOMNode * vrijepppuntennode = attributes->getNamedItem(_T("vrijepppunten"));
    if (vrijepppuntennode != NULL)
      aVoedingsmiddelbasis.Setvrijepppunten(vrijepppuntennode->getNodeValue());
  }

  return XmlClass::RESULT_Ok;
}


}

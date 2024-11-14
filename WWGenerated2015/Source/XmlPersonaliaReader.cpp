#include "stdafx.h"
#include "XmlPersonaliaReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlPersonalia.h"
namespace ww2015
{


XmlPersonaliaReader::XmlPersonaliaReader()
{
}


XmlClass::eRESULT XmlPersonaliaReader::Read(const std::wstring & aFilename, XmlPersonalia *& aPersonalia)
{
  aPersonalia = NULL;
  if (_taccess(aFilename.c_str(), 0) == -1)
  {
    switch (errno)
    {
      case ENOENT:
        return RESULT_FileNotFound;
      default:
        return RESULT_FileOpenError;
    }
  }

  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  eRESULT result = ParseDocument(aFilename, parser);
  if (result != RESULT_Ok)
    if (result == RESULT_FileNotFound)
      return RESULT_Ok;
    else
      return result;

  if (parser.getDocument() == NULL)
    return RESULT_ErrorInFile;

  try
  {
    XERCES_CPP_NAMESPACE::DOMNodeList * list = parser.getDocument()->getChildNodes();

    if (list == NULL)
      return RESULT_ErrorInFile;

    for (XMLSize_t i = 0; i < list->getLength(); i++)
    {
      if (list->item(i) == NULL)
        continue;

      short type = list->item(i)->getNodeType();
      XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

      if (type == XERCES_CPP_NAMESPACE::DOMNode::TEXT_NODE)
      {
        continue;
      }
      else if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
      {
        const TCHAR * name = node->getNodeName();
        (void)name;
        if (_tcscmp(node->getNodeName(), _T("personalia")) == 0)
          aPersonalia = Generate(*node);
      }
    }

    if (aPersonalia == NULL)
      return RESULT_ParserError;
  }
  catch (const std::exception & anException)
  {
    (void)anException;
    return RESULT_ParserError;
  }
  catch (const XERCES_CPP_NAMESPACE::SAXException & anException)
  {
    (void)anException;
    return RESULT_ParserError;
  }
  catch (...)
  {
    return RESULT_ParserError;
  }

  return RESULT_Ok;
}

XmlPersonalia * XmlPersonaliaReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlPersonalia * Personalia = new XmlPersonalia;
  Fill(anElement, *Personalia);
  return Personalia;
}


XmlClass::eRESULT XmlPersonaliaReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPersonalia & aPersonalia)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != NULL)
      aPersonalia.Setnaam(naamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * gebruikersnaamnode = attributes->getNamedItem(_T("gebruikersnaam"));
    if (gebruikersnaamnode != NULL)
      aPersonalia.Setgebruikersnaam(gebruikersnaamnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aPersonalia.Setpunten(puntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * pppuntennode = attributes->getNamedItem(_T("pppunten"));
    if (pppuntennode != NULL)
      aPersonalia.Setpppunten(pppuntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * ppweekpuntennode = attributes->getNamedItem(_T("ppweekpunten"));
    if (ppweekpuntennode != NULL)
      aPersonalia.Setppweekpunten(ppweekpuntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * kcpuntennode = attributes->getNamedItem(_T("kcpunten"));
    if (kcpuntennode != NULL)
      aPersonalia.Setkcpunten(kcpuntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * kcweekpuntennode = attributes->getNamedItem(_T("kcweekpunten"));
    if (kcweekpuntennode != NULL)
      aPersonalia.Setkcweekpunten(kcweekpuntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * geborennode = attributes->getNamedItem(_T("geboren"));
    if (geborennode != NULL)
      aPersonalia.Setgeboren(geborennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * geslachtnode = attributes->getNamedItem(_T("geslacht"));
    if (geslachtnode != NULL)
    {
      if (_tcscmp(geslachtnode->getNodeValue(), _T("Mannelijk")) == 0)
        aPersonalia.Setgeslacht(XmlPersonalia::geslacht_Mannelijk);
      else if (_tcscmp(geslachtnode->getNodeValue(), _T("Vrouwelijk")) == 0)
        aPersonalia.Setgeslacht(XmlPersonalia::geslacht_Vrouwelijk);
    }
    XERCES_CPP_NAMESPACE::DOMNode * werknode = attributes->getNamedItem(_T("werk"));
    if (werknode != NULL)
    {
      if (_tcscmp(werknode->getNodeValue(), _T("Zittend")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk_Zittend);
      else if (_tcscmp(werknode->getNodeValue(), _T("Staand")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk_Staand);
      else if (_tcscmp(werknode->getNodeValue(), _T("Lopend")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk_Lopend);
      else if (_tcscmp(werknode->getNodeValue(), _T("Zwaar")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk_Zwaar);
    }
    XERCES_CPP_NAMESPACE::DOMNode * lengtenode = attributes->getNamedItem(_T("lengte"));
    if (lengtenode != NULL)
      aPersonalia.Setlengte(lengtenode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * gewichtnode = attributes->getNamedItem(_T("gewicht"));
    if (gewichtnode != NULL)
      aPersonalia.Setgewicht(gewichtnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * streefgewichtnode = attributes->getNamedItem(_T("streefgewicht"));
    if (streefgewichtnode != NULL)
      aPersonalia.Setstreefgewicht(streefgewichtnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * startgewichtnode = attributes->getNamedItem(_T("startgewicht"));
    if (startgewichtnode != NULL)
      aPersonalia.Setstartgewicht(startgewichtnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * huidiggewichtnode = attributes->getNamedItem(_T("huidiggewicht"));
    if (huidiggewichtnode != NULL)
      aPersonalia.Sethuidiggewicht(huidiggewichtnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * strategienode = attributes->getNamedItem(_T("strategie"));
    if (strategienode != NULL)
    {
      if (_tcscmp(strategienode->getNodeValue(), _T("FlexiPoints")) == 0)
        aPersonalia.Setstrategie(XmlPersonalia::strategie_FlexiPoints);
      else if (_tcscmp(strategienode->getNodeValue(), _T("ProPoints")) == 0)
        aPersonalia.Setstrategie(XmlPersonalia::strategie_ProPoints);
      else if (_tcscmp(strategienode->getNodeValue(), _T("KCal")) == 0)
        aPersonalia.Setstrategie(XmlPersonalia::strategie_KCal);
      else if (_tcscmp(strategienode->getNodeValue(), _T("CarboHydrates")) == 0)
        aPersonalia.Setstrategie(XmlPersonalia::strategie_CarboHydrates);
    }
  }

  return XmlClass::RESULT_Ok;
}


}



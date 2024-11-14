#include "stdafx.h"
#include "XmlWeekReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlWeek.h"
#include "XmlDagReader.h"
#include "XmlDag.h"
namespace ww_1_1
{


XmlWeekReader::XmlWeekReader()
{
}


Generator::XmlClass::eRESULT XmlWeekReader::Read(const std::wstring & aFilename, XmlWeek *& aWeek)
{
  aWeek = NULL;
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
        if (_tcscmp(node->getNodeName(), _T("week")) == 0)
          aWeek = Generate(*node);
      }
    }

    if (aWeek == NULL)
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

XmlWeek * XmlWeekReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlWeek * Week = new XmlWeek;
  Fill(anElement, *Week);
  return Week;
}


Generator::XmlClass::eRESULT XmlWeekReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlWeek & aWeek)
{
  XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

  if (list == NULL)
    return Generator::XmlClass::RESULT_Ok;

  for (XMLSize_t i = 0; i < list->getLength(); i++)
  {
    if (list->item(i) == NULL)
      continue;

    short type = list->item(i)->getNodeType();
    XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

    if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
    {
      if (_tcscmp(node->getNodeName(), _T("dag")) == 0)
     {
       XmlDagReader DagReader;
       XmlDag * Dag = DagReader.Generate(*node);
       if (Dag != NULL)
         aWeek.Add(Dag);
     }
   }
  }
  XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
  if (attributes != NULL)
  {
    XERCES_CPP_NAMESPACE::DOMNode * begindatumnode = attributes->getNamedItem(_T("begindatum"));
    if (begindatumnode != NULL)
      aWeek.Setbegindatum(begindatumnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * einddatumnode = attributes->getNamedItem(_T("einddatum"));
    if (einddatumnode != NULL)
      aWeek.Seteinddatum(einddatumnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != NULL)
      aWeek.Setpunten(puntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * weekpuntennode = attributes->getNamedItem(_T("weekpunten"));
    if (weekpuntennode != NULL)
      aWeek.Setweekpunten(weekpuntennode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * startweightnode = attributes->getNamedItem(_T("startweight"));
    if (startweightnode != NULL)
      aWeek.Setstartweight(startweightnode->getNodeValue());
    XERCES_CPP_NAMESPACE::DOMNode * strategienode = attributes->getNamedItem(_T("strategie"));
    if (strategienode != NULL)
    {
      if (_tcscmp(strategienode->getNodeValue(), _T("FlexiPoints")) == 0)
        aWeek.Setstrategie(XmlWeek::strategie_FlexiPoints);
      else if (_tcscmp(strategienode->getNodeValue(), _T("ProPoints")) == 0)
        aWeek.Setstrategie(XmlWeek::strategie_ProPoints);
      else if (_tcscmp(strategienode->getNodeValue(), _T("KCal")) == 0)
        aWeek.Setstrategie(XmlWeek::strategie_KCal);
      else if (_tcscmp(strategienode->getNodeValue(), _T("CarboHydrates")) == 0)
        aWeek.Setstrategie(XmlWeek::strategie_CarboHydrates);
    }
  }

  return Generator::XmlClass::RESULT_Ok;
}


}



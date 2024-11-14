#include "stdafx.h"
#include "XmlReceptdefsReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlReceptdefs.h"
#include "XmlReceptdefReader.h"
#include "XmlReceptdef.h"
namespace ww2015
{


XmlReceptdefsReader::XmlReceptdefsReader()
{
}


XmlClass::eRESULT XmlReceptdefsReader::Read(const std::wstring & aFilename, XmlReceptdefs *& aReceptdefs)
{
  aReceptdefs = NULL;
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
        if (_tcscmp(node->getNodeName(), _T("receptdefs")) == 0)
          aReceptdefs = Generate(*node);
      }
    }

    if (aReceptdefs == NULL)
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

XmlReceptdefs * XmlReceptdefsReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
  XmlReceptdefs * Receptdefs = new XmlReceptdefs;
  Fill(anElement, *Receptdefs);
  return Receptdefs;
}


XmlClass::eRESULT XmlReceptdefsReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdefs & aReceptdefs)
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
      if (_tcscmp(node->getNodeName(), _T("receptdef")) == 0)
     {
       XmlReceptdefReader ReceptdefReader;
       XmlReceptdef * Receptdef = ReceptdefReader.Generate(*node);
       if (Receptdef != NULL)
         aReceptdefs.Add(Receptdef);
     }
   }
  }
  return XmlClass::RESULT_Ok;
}


}



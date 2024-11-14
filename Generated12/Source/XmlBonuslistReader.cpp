#include "../Interface\Generated\stdafx.h"
#include "../Interface\Generated\XmlBonuslistReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "../Interface\Generated\XmlBonuslist.h"
#include "../Interface\Generated\XmlBonuscellReader.h"
#include "../Interface\Generated\XmlBonuscell.h"
namespace ww_1_2
{


XmlBonuslistReader::XmlBonuslistReader()
{
}


XmlClass::eRESULT XmlBonuslistReader::Read(const std::wstring & aFilename, XmlBonuslist *& aBonuslist)
{
  aBonuslist = NULL;
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
        if (_tcscmp(node->getNodeName(), _T("bonuslist")) == 0)
          aBonuslist = Generate(*node);
      }
    }

    if (aBonuslist == NULL)
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



//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlReceptdefsReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlReceptdefs.h"
#include "XmlReceptdefReader.h"
#include "XmlReceptdef.h"
namespace ww2019
{


XmlReceptdefsReader::XmlReceptdefsReader()
{
}


std::unique_ptr<XmlReceptdefs> XmlReceptdefsReader::Read(const std::wstring & aFilename)
{
    if (_taccess(aFilename.c_str(), 0) == -1)
      {
          switch (errno)
          {
              case ENOENT:
                  throw Result::FileNotFound;
              default:
                  throw Result::FileOpenError;
          }
      }

    ParseErrorHandler eh;
    XERCES_CPP_NAMESPACE::XercesDOMParser parser;
    parser.setDoValidation(false);
    parser.setErrorHandler(&eh);

    Result result = ParseDocument(aFilename, parser);
    if (result != Result::Ok)
        if (result == Result::FileNotFound)
            return {};
        else
            throw result;

    if (parser.getDocument() == nullptr)
        throw Result::ErrorInFile;

    try
    {
        XERCES_CPP_NAMESPACE::DOMNodeList * list = parser.getDocument()->getChildNodes();

        if (list == nullptr)
            throw Result::ErrorInFile;

        for (XMLSize_t i = 0; i < list->getLength(); i++)
        {
            if (list->item(i) == nullptr)
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
                    return Generate(*node);
            }
        }

        throw Result::ParserError;
    }
    catch (const std::exception & anException)
    {
        (void)anException;
        throw Result::ParserError;
    }
    catch (const XERCES_CPP_NAMESPACE::SAXException & anException)
    {
        (void)anException;
        throw Result::ParserError;
    }
    catch (...)
    {
        throw Result::ParserError;
    }

    return {};
}

std::unique_ptr<XmlReceptdefs> XmlReceptdefsReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto receptdefs = std::make_unique<XmlReceptdefs>();
    Fill(anElement, *receptdefs);
    return receptdefs;
}


XmlClass::Result XmlReceptdefsReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlReceptdefs & aReceptdefs)
{
    const XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

    if (list == nullptr)
        return XmlClass::Result::Ok;

    for (XMLSize_t i = 0; i < list->getLength(); i++)
    {
        if (list->item(i) == nullptr)
            continue;

        const short type = list->item(i)->getNodeType();
        const XERCES_CPP_NAMESPACE::DOMNode * node = list->item(i);

        if (type == XERCES_CPP_NAMESPACE::DOMNode::ELEMENT_NODE)
        {
            if (_tcscmp(node->getNodeName(), _T("receptdef")) == 0)
     {
         XmlReceptdefReader receptdefReader;
         std::unique_ptr<XmlReceptdef> receptdef = receptdefReader.Generate(*node);
         if (receptdef != nullptr)
             aReceptdefs.Add(std::move(receptdef));
     }
   }
  }
    return XmlClass::Result::Ok;
}


}



//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddeldefsReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlVoedingsmiddeldefs.h"
#include "XmlVoedingsmiddeldefReader.h"
#include "XmlVoedingsmiddeldef.h"
namespace ww2024
{


XmlVoedingsmiddeldefsReader::XmlVoedingsmiddeldefsReader()
{
}


std::unique_ptr<XmlVoedingsmiddeldefs> XmlVoedingsmiddeldefsReader::Read(const std::wstring & aFilename)
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
                if (_tcscmp(node->getNodeName(), _T("voedingsmiddeldefs")) == 0)
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

std::unique_ptr<XmlVoedingsmiddeldefs> XmlVoedingsmiddeldefsReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto voedingsmiddeldefs = std::make_unique<XmlVoedingsmiddeldefs>();
    Fill(anElement, *voedingsmiddeldefs);
    return voedingsmiddeldefs;
}


XmlClass::Result XmlVoedingsmiddeldefsReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlVoedingsmiddeldefs & aVoedingsmiddeldefs)
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
            if (_tcscmp(node->getNodeName(), _T("voedingsmiddeldef")) == 0)
     {
         XmlVoedingsmiddeldefReader voedingsmiddeldefReader;
         std::unique_ptr<XmlVoedingsmiddeldef> voedingsmiddeldef = voedingsmiddeldefReader.Generate(*node);
         if (voedingsmiddeldef != nullptr)
             aVoedingsmiddeldefs.Add(std::move(voedingsmiddeldef));
     }
   }
  }
    return XmlClass::Result::Ok;
}


}



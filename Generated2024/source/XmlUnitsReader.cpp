//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlUnitsReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlUnits.h"
#include "XmlUnitReader.h"
#include "XmlUnit.h"
namespace ww2024
{


XmlUnitsReader::XmlUnitsReader()
{
}


std::unique_ptr<XmlUnits> XmlUnitsReader::Read(const std::wstring & aFilename)
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
                if (_tcscmp(node->getNodeName(), _T("units")) == 0)
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

std::unique_ptr<XmlUnits> XmlUnitsReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto units = std::make_unique<XmlUnits>();
    Fill(anElement, *units);
    return units;
}


XmlClass::Result XmlUnitsReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlUnits & aUnits)
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
            if (_tcscmp(node->getNodeName(), _T("unit")) == 0)
     {
         XmlUnitReader unitReader;
         std::unique_ptr<XmlUnit> unit = unitReader.Generate(*node);
         if (unit != nullptr)
             aUnits.Add(std::move(unit));
     }
   }
  }
    return XmlClass::Result::Ok;
}


}



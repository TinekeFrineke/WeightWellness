//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlWeekReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlWeek.h"
#include "XmlDagReader.h"
#include "XmlDag.h"
namespace ww2019
{


XmlWeekReader::XmlWeekReader()
{
}


std::unique_ptr<XmlWeek> XmlWeekReader::Read(const std::wstring & aFilename)
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
                if (_tcscmp(node->getNodeName(), _T("week")) == 0)
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

std::unique_ptr<XmlWeek> XmlWeekReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto week = std::make_unique<XmlWeek>();
    Fill(anElement, *week);
    return week;
}


XmlClass::Result XmlWeekReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlWeek & aWeek)
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
            if (_tcscmp(node->getNodeName(), _T("dag")) == 0)
     {
         XmlDagReader dagReader;
         std::unique_ptr<XmlDag> dag = dagReader.Generate(*node);
         if (dag != nullptr)
             aWeek.Add(std::move(dag));
     }
   }
  }
    XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* begindatumnode = attributes->getNamedItem(_T("begindatum"));
    if (begindatumnode != nullptr)
      aWeek.Setbegindatum(begindatumnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* einddatumnode = attributes->getNamedItem(_T("einddatum"));
    if (einddatumnode != nullptr)
      aWeek.Seteinddatum(einddatumnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* puntennode = attributes->getNamedItem(_T("punten"));
    if (puntennode != nullptr) {
        aWeek.Setpunten(_ttoi(puntennode->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* weekpuntennode = attributes->getNamedItem(_T("weekpunten"));
    if (weekpuntennode != nullptr) {
        aWeek.Setweekpunten(_ttoi(weekpuntennode->getNodeValue()));
    }
    const XERCES_CPP_NAMESPACE::DOMNode* startweightnode = attributes->getNamedItem(_T("startweight"));
    if (startweightnode != nullptr)
      aWeek.Setstartweight(startweightnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* strategienode = attributes->getNamedItem(_T("strategie"));
    if (strategienode != nullptr)
    {
      if (_tcscmp(strategienode->getNodeValue(), _T("KCal")) == 0)
        aWeek.Setstrategie(XmlWeek::strategie::KCal);
      else if (_tcscmp(strategienode->getNodeValue(), _T("Koolhydraten")) == 0)
        aWeek.Setstrategie(XmlWeek::strategie::Koolhydraten);
    }
    }

    return XmlClass::Result::Ok;
}


}



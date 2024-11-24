//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlPersonaliaReader.h"

#include <tchar.h>
#include <xercesc/dom/dom.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/saxexception.hpp>
#include "XmlPersonalia.h"
namespace ww2019
{


XmlPersonaliaReader::XmlPersonaliaReader()
{
}


std::unique_ptr<XmlPersonalia> XmlPersonaliaReader::Read(const std::wstring & aFilename)
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
                if (_tcscmp(node->getNodeName(), _T("personalia")) == 0)
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

std::unique_ptr<XmlPersonalia> XmlPersonaliaReader::Generate(const XERCES_CPP_NAMESPACE::DOMNode & anElement)
{
    auto personalia = std::make_unique<XmlPersonalia>();
    Fill(anElement, *personalia);
    return personalia;
}


XmlClass::Result XmlPersonaliaReader::Fill(const XERCES_CPP_NAMESPACE::DOMNode & anElement, XmlPersonalia & aPersonalia)
{
    const XERCES_CPP_NAMESPACE::DOMNodeList * list = anElement.getChildNodes();

    if (list == nullptr)
        return XmlClass::Result::Ok;

    for (XMLSize_t i = 0; i < list->getLength(); i++)
    {
        if (list->item(i) == nullptr)
            continue;

  }
    XERCES_CPP_NAMESPACE::DOMNamedNodeMap * attributes = anElement.getAttributes();
    if (attributes != nullptr)
    {
    const XERCES_CPP_NAMESPACE::DOMNode* naamnode = attributes->getNamedItem(_T("naam"));
    if (naamnode != nullptr)
      aPersonalia.Setnaam(naamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* gebruikersnaamnode = attributes->getNamedItem(_T("gebruikersnaam"));
    if (gebruikersnaamnode != nullptr)
      aPersonalia.Setgebruikersnaam(gebruikersnaamnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* kcpuntennode = attributes->getNamedItem(_T("kcpunten"));
    if (kcpuntennode != nullptr)
      aPersonalia.Setkcpunten(kcpuntennode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* kcweekpuntennode = attributes->getNamedItem(_T("kcweekpunten"));
    if (kcweekpuntennode != nullptr)
      aPersonalia.Setkcweekpunten(kcweekpuntennode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* chpuntennode = attributes->getNamedItem(_T("chpunten"));
    if (chpuntennode != nullptr)
      aPersonalia.Setchpunten(chpuntennode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* chweekpuntennode = attributes->getNamedItem(_T("chweekpunten"));
    if (chweekpuntennode != nullptr)
      aPersonalia.Setchweekpunten(chweekpuntennode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* geborennode = attributes->getNamedItem(_T("geboren"));
    if (geborennode != nullptr)
      aPersonalia.Setgeboren(geborennode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* geslachtnode = attributes->getNamedItem(_T("geslacht"));
    if (geslachtnode != nullptr)
    {
      if (_tcscmp(geslachtnode->getNodeValue(), _T("Mannelijk")) == 0)
        aPersonalia.Setgeslacht(XmlPersonalia::geslacht::Mannelijk);
      else if (_tcscmp(geslachtnode->getNodeValue(), _T("Vrouwelijk")) == 0)
        aPersonalia.Setgeslacht(XmlPersonalia::geslacht::Vrouwelijk);
    }
    const XERCES_CPP_NAMESPACE::DOMNode* werknode = attributes->getNamedItem(_T("werk"));
    if (werknode != nullptr)
    {
      if (_tcscmp(werknode->getNodeValue(), _T("Zittend")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk::Zittend);
      else if (_tcscmp(werknode->getNodeValue(), _T("Staand")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk::Staand);
      else if (_tcscmp(werknode->getNodeValue(), _T("Lopend")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk::Lopend);
      else if (_tcscmp(werknode->getNodeValue(), _T("Zwaar")) == 0)
        aPersonalia.Setwerk(XmlPersonalia::werk::Zwaar);
    }
    const XERCES_CPP_NAMESPACE::DOMNode* lengtenode = attributes->getNamedItem(_T("lengte"));
    if (lengtenode != nullptr)
      aPersonalia.Setlengte(lengtenode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* gewichtnode = attributes->getNamedItem(_T("gewicht"));
    if (gewichtnode != nullptr)
      aPersonalia.Setgewicht(gewichtnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* streefgewichtnode = attributes->getNamedItem(_T("streefgewicht"));
    if (streefgewichtnode != nullptr)
      aPersonalia.Setstreefgewicht(streefgewichtnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* startgewichtnode = attributes->getNamedItem(_T("startgewicht"));
    if (startgewichtnode != nullptr)
      aPersonalia.Setstartgewicht(startgewichtnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* huidiggewichtnode = attributes->getNamedItem(_T("huidiggewicht"));
    if (huidiggewichtnode != nullptr)
      aPersonalia.Sethuidiggewicht(huidiggewichtnode->getNodeValue());
    const XERCES_CPP_NAMESPACE::DOMNode* strategienode = attributes->getNamedItem(_T("strategie"));
    if (strategienode != nullptr)
    {
      if (_tcscmp(strategienode->getNodeValue(), _T("KCal")) == 0)
        aPersonalia.Setstrategie(XmlPersonalia::strategie::KCal);
      else if (_tcscmp(strategienode->getNodeValue(), _T("CarboHydrates")) == 0)
        aPersonalia.Setstrategie(XmlPersonalia::strategie::CarboHydrates);
    }
    }

    return XmlClass::Result::Ok;
}


}



//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlPersonaliaWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlPersonalia.h"

namespace ww2019
{
XmlClass::Result XmlPersonaliaWriter::Write(const std::wstring & aFilename, const XmlPersonalia & aPersonalia)
{
    ParseErrorHandler eh;
    XERCES_CPP_NAMESPACE::XercesDOMParser parser;
    parser.setDoValidation(false);
    parser.setErrorHandler(&eh);

    XERCES_CPP_NAMESPACE::DOMImplementation* impl =
      XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

    XERCES_CPP_NAMESPACE::DOMDocument* doc =
      impl->createDocument(0,               // root element namespace URI.
                           L"personalia",  // root element name
                           0);              // document type object (Xml).
    XERCES_CPP_NAMESPACE::DOMElement* rootelement = doc->getDocumentElement();
    Fill(*doc, aPersonalia, *rootelement);

    XERCES_CPP_NAMESPACE::DOMWriter* writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
    XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
    writer->writeNode(&formatter, *doc);
    writer->release();

    doc->release();

    return Result::Ok;
}


void XmlPersonaliaWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPersonalia & aPersonalia, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aPersonalia;
    (void)anElement;
  anElement.setAttribute(_T("naam"), aPersonalia.Getnaam().c_str());
  anElement.setAttribute(_T("gebruikersnaam"), aPersonalia.Getgebruikersnaam().c_str());
  anElement.setAttribute(_T("punten"), aPersonalia.Getpunten().c_str());
  anElement.setAttribute(_T("kcpunten"), aPersonalia.Getkcpunten().c_str());
  anElement.setAttribute(_T("kcweekpunten"), aPersonalia.Getkcweekpunten().c_str());
  anElement.setAttribute(_T("geboren"), aPersonalia.Getgeboren().c_str());
    switch (aPersonalia.Getgeslacht())
    {
        case XmlPersonalia::geslacht::Mannelijk:
            anElement.setAttribute(_T("geslacht"), _T("Mannelijk"));
        break;
        case XmlPersonalia::geslacht::Vrouwelijk:
            anElement.setAttribute(_T("geslacht"), _T("Vrouwelijk"));
        break;
        default:
            throw 1;
    }
    switch (aPersonalia.Getwerk())
    {
        case XmlPersonalia::werk::Zittend:
            anElement.setAttribute(_T("werk"), _T("Zittend"));
        break;
        case XmlPersonalia::werk::Staand:
            anElement.setAttribute(_T("werk"), _T("Staand"));
        break;
        case XmlPersonalia::werk::Lopend:
            anElement.setAttribute(_T("werk"), _T("Lopend"));
        break;
        case XmlPersonalia::werk::Zwaar:
            anElement.setAttribute(_T("werk"), _T("Zwaar"));
        break;
        default:
            throw 1;
    }
  anElement.setAttribute(_T("lengte"), aPersonalia.Getlengte().c_str());
  anElement.setAttribute(_T("gewicht"), aPersonalia.Getgewicht().c_str());
  anElement.setAttribute(_T("streefgewicht"), aPersonalia.Getstreefgewicht().c_str());
  anElement.setAttribute(_T("startgewicht"), aPersonalia.Getstartgewicht().c_str());
  anElement.setAttribute(_T("huidiggewicht"), aPersonalia.Gethuidiggewicht().c_str());
    switch (aPersonalia.Getstrategie())
    {
        case XmlPersonalia::strategie::KCal:
            anElement.setAttribute(_T("strategie"), _T("KCal"));
        break;
        case XmlPersonalia::strategie::CarboHydrates:
            anElement.setAttribute(_T("strategie"), _T("CarboHydrates"));
        break;
        default:
            throw 1;
    }
}


}

#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlPersonalia.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlPersonaliaWriter.h"

namespace ww_1_2
{
XmlClass::eRESULT XmlPersonaliaWriter::Write(const std::wstring & aFilename, const XmlPersonalia & aPersonalia)
{
  ParseErrorHandler eh;
  XERCES_CPP_NAMESPACE::XercesDOMParser parser;
  parser.setDoValidation(false);
  parser.setErrorHandler(&eh);

  XERCES_CPP_NAMESPACE::DOMImplementation * impl =
    XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

  XERCES_CPP_NAMESPACE::DOMDocument * doc =
    impl->createDocument(0,               // root element namespace URI.
                         L"personalia",  // root element name
                         0);              // document type object (Xml).
  XERCES_CPP_NAMESPACE::DOMElement * rootelement = doc->getDocumentElement();
  Fill(*doc, aPersonalia, *rootelement);

  XERCES_CPP_NAMESPACE::DOMWriter * writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
  XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
  writer->writeNode(&formatter, *doc);
  writer->release();

  doc->release();

  return RESULT_Ok;
}


void XmlPersonaliaWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPersonalia & aPersonalia, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aPersonalia;
  (void)anElement;
  anElement.setAttribute(_T("naam"), aPersonalia.Getnaam().c_str());
  anElement.setAttribute(_T("gebruikersnaam"), aPersonalia.Getgebruikersnaam().c_str());
  anElement.setAttribute(_T("punten"), aPersonalia.Getpunten().c_str());
  anElement.setAttribute(_T("pppunten"), aPersonalia.Getpppunten().c_str());
  anElement.setAttribute(_T("ppweekpunten"), aPersonalia.Getppweekpunten().c_str());
  anElement.setAttribute(_T("kcpunten"), aPersonalia.Getkcpunten().c_str());
  anElement.setAttribute(_T("kcweekpunten"), aPersonalia.Getkcweekpunten().c_str());
  anElement.setAttribute(_T("chpunten"), aPersonalia.Getchpunten().c_str());
  anElement.setAttribute(_T("chweekpunten"), aPersonalia.Getchweekpunten().c_str());
  anElement.setAttribute(_T("geboren"), aPersonalia.Getgeboren().c_str());
  switch (aPersonalia.Getgeslacht())
  {
    case XmlPersonalia::geslacht_Mannelijk:
      anElement.setAttribute(_T("geslacht"), _T("Mannelijk"));
    break;
    case XmlPersonalia::geslacht_Vrouwelijk:
      anElement.setAttribute(_T("geslacht"), _T("Vrouwelijk"));
    break;
    default:
      throw 1;
  }
  switch (aPersonalia.Getwerk())
  {
    case XmlPersonalia::werk_Zittend:
      anElement.setAttribute(_T("werk"), _T("Zittend"));
    break;
    case XmlPersonalia::werk_Staand:
      anElement.setAttribute(_T("werk"), _T("Staand"));
    break;
    case XmlPersonalia::werk_Lopend:
      anElement.setAttribute(_T("werk"), _T("Lopend"));
    break;
    case XmlPersonalia::werk_Zwaar:
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
  switch (aPersonalia.Getstreven())
  {
    case XmlPersonalia::streven_Afvallen:
      anElement.setAttribute(_T("streven"), _T("Afvallen"));
    break;
    case XmlPersonalia::streven_OpGewichtBlijven:
      anElement.setAttribute(_T("streven"), _T("OpGewichtBlijven"));
    break;
    case XmlPersonalia::streven_Lopend:
      anElement.setAttribute(_T("streven"), _T("Lopend"));
    break;
    case XmlPersonalia::streven_Zwaar:
      anElement.setAttribute(_T("streven"), _T("Zwaar"));
    break;
    default:
      throw 1;
  }
  switch (aPersonalia.Getstrategie())
  {
    case XmlPersonalia::strategie_FlexiPoints:
      anElement.setAttribute(_T("strategie"), _T("FlexiPoints"));
    break;
    case XmlPersonalia::strategie_ProPoints:
      anElement.setAttribute(_T("strategie"), _T("ProPoints"));
    break;
    case XmlPersonalia::strategie_KCal:
      anElement.setAttribute(_T("strategie"), _T("KCal"));
    break;
    case XmlPersonalia::strategie_CarboHydrates:
      anElement.setAttribute(_T("strategie"), _T("CarboHydrates"));
    break;
    default:
      throw 1;
  }
}


}

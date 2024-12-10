//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlWeekWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlWeek.h"

#include "XmlDagWriter.h"
#include "XmlDag.h"
namespace ww2024
{
XmlClass::Result XmlWeekWriter::Write(const std::wstring & aFilename, const XmlWeek & aWeek)
{
    ParseErrorHandler eh;
    XERCES_CPP_NAMESPACE::XercesDOMParser parser;
    parser.setDoValidation(false);
    parser.setErrorHandler(&eh);

    XERCES_CPP_NAMESPACE::DOMImplementation* impl =
      XERCES_CPP_NAMESPACE::DOMImplementationRegistry::getDOMImplementation(L"Core");

    XERCES_CPP_NAMESPACE::DOMDocument* doc =
      impl->createDocument(0,               // root element namespace URI.
                           L"week",  // root element name
                           0);              // document type object (Xml).
    XERCES_CPP_NAMESPACE::DOMElement* rootelement = doc->getDocumentElement();
    Fill(*doc, aWeek, *rootelement);

    XERCES_CPP_NAMESPACE::DOMWriter* writer = ((XERCES_CPP_NAMESPACE::DOMImplementationLS*)impl)->createDOMWriter();
    XERCES_CPP_NAMESPACE::LocalFileFormatTarget formatter(aFilename.c_str());
    writer->writeNode(&formatter, *doc);
    writer->release();

    doc->release();

    return Result::Ok;
}


void XmlWeekWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlWeek & aWeek, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

    XmlDagWriter Dagwriter;
    for (size_t i = 0; i < aWeek.GetDagList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Dagnode = Dagwriter.Write(aDocument, *aWeek.GetDagList()[i]);
        anElement.appendChild(Dagnode);
    }
  anElement.setAttribute(_T("begindatum"), aWeek.Getbegindatum().c_str());
  anElement.setAttribute(_T("einddatum"), aWeek.Geteinddatum().c_str());
    {
        auto buffer{ std::to_wstring(aWeek.Getpunten()) };
        anElement.setAttribute(_T("punten"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aWeek.Getweekpunten()) };
        anElement.setAttribute(_T("weekpunten"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aWeek.Getstartweight()) };
        anElement.setAttribute(_T("startweight"), buffer.c_str());
    }
    switch (aWeek.Getstrategie())
    {
        case XmlWeek::strategie::KCal:
            anElement.setAttribute(_T("strategie"), _T("KCal"));
        break;
        case XmlWeek::strategie::Koolhydraten:
            anElement.setAttribute(_T("strategie"), _T("Koolhydraten"));
        break;
        default:
            throw 1;
    }
}


}

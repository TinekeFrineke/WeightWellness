//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlBonuscellWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlBonuscell.h"

namespace ww2024
{
XERCES_CPP_NAMESPACE::DOMNode * XmlBonuscellWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuscell & aBonuscell)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("bonuscell"));
    Fill(aDocument, aBonuscell, *element);
    return element;
}

void XmlBonuscellWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuscell & aBonuscell, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aBonuscell;
    (void)anElement;
    {
        auto buffer{ std::to_wstring(aBonuscell.Getgewicht()) };
        anElement.setAttribute(_T("gewicht"), buffer.c_str());
    }
    switch (aBonuscell.Getintensiteit())
    {
        case XmlBonuscell::intensiteit::laag:
            anElement.setAttribute(_T("intensiteit"), _T("laag"));
        break;
        case XmlBonuscell::intensiteit::middel:
            anElement.setAttribute(_T("intensiteit"), _T("middel"));
        break;
        case XmlBonuscell::intensiteit::hoog:
            anElement.setAttribute(_T("intensiteit"), _T("hoog"));
        break;
        default:
            throw 1;
    }
    {
        auto buffer{ std::to_wstring(aBonuscell.Getminuten()) };
        anElement.setAttribute(_T("minuten"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aBonuscell.Getpunten()) };
        anElement.setAttribute(_T("punten"), buffer.c_str());
    }
}


}

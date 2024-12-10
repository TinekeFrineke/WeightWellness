//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlReceptWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlRecept.h"

namespace ww2024
{
XERCES_CPP_NAMESPACE::DOMNode * XmlReceptWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlRecept & aRecept)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("recept"));
    Fill(aDocument, aRecept, *element);
    return element;
}

void XmlReceptWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlRecept & aRecept, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aRecept;
    (void)anElement;
  anElement.setAttribute(_T("naam"), aRecept.Getnaam().c_str());
    {
        auto buffer{ std::to_wstring(aRecept.Getpunten()) };
        anElement.setAttribute(_T("punten"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aRecept.Getaantalporties()) };
        anElement.setAttribute(_T("aantalporties"), buffer.c_str());
    }
}


}

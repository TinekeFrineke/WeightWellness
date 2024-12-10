//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlVoedingswaardeWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlVoedingswaarde.h"

namespace ww2024
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingswaardeWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingswaarde & aVoedingswaarde)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingswaarde"));
    Fill(aDocument, aVoedingswaarde, *element);
    return element;
}

void XmlVoedingswaardeWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingswaarde & aVoedingswaarde, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aVoedingswaarde;
    (void)anElement;
    {
        auto buffer{ std::to_wstring(aVoedingswaarde.Getkcalper100()) };
        anElement.setAttribute(_T("kcalper100"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aVoedingswaarde.Getvetper100()) };
        anElement.setAttribute(_T("vetper100"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aVoedingswaarde.Getkoolhydratenper100()) };
        anElement.setAttribute(_T("koolhydratenper100"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aVoedingswaarde.Geteiwitper100()) };
        anElement.setAttribute(_T("eiwitper100"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aVoedingswaarde.Getvezelsper100()) };
        anElement.setAttribute(_T("vezelsper100"), buffer.c_str());
    }
}


}

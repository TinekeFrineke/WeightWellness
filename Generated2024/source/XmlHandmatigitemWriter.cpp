//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlHandmatigitemWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlHandmatigitem.h"

namespace ww2024
{
XERCES_CPP_NAMESPACE::DOMNode * XmlHandmatigitemWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlHandmatigitem & aHandmatigitem)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("handmatigitem"));
    Fill(aDocument, aHandmatigitem, *element);
    return element;
}

void XmlHandmatigitemWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlHandmatigitem & aHandmatigitem, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aHandmatigitem;
    (void)anElement;
  anElement.setAttribute(_T("naam"), aHandmatigitem.Getnaam().c_str());
    {
        auto buffer{ std::to_wstring(aHandmatigitem.Getpunten()) };
        anElement.setAttribute(_T("punten"), buffer.c_str());
    }
    {
        auto buffer{ std::to_wstring(aHandmatigitem.Gethoeveelheid()) };
        anElement.setAttribute(_T("hoeveelheid"), buffer.c_str());
    }
}


}

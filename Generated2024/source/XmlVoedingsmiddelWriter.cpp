//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlVoedingsmiddelWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlVoedingsmiddel.h"

#include "XmlPortieWriter.h"
#include "XmlPortie.h"
#include "XmlVoedingswaardeWriter.h"
#include "XmlVoedingswaarde.h"
namespace ww2024
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddelWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddel & aVoedingsmiddel)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddel"));
    Fill(aDocument, aVoedingsmiddel, *element);
    return element;
}

void XmlVoedingsmiddelWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddel & aVoedingsmiddel, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

    XmlPortieWriter Portiewriter;
    anElement.appendChild(Portiewriter.Write(aDocument, aVoedingsmiddel.GetPortie()));

    XmlVoedingswaardeWriter Voedingswaardewriter;
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, aVoedingsmiddel.GetVoedingswaarde()));
  anElement.setAttribute(_T("naam"), aVoedingsmiddel.Getnaam().c_str());
  anElement.setAttribute(_T("categorie"), aVoedingsmiddel.Getcategorie().c_str());
  anElement.setAttribute(_T("unit"), aVoedingsmiddel.Getunit().c_str());
    {
        auto buffer{ std::to_wstring(aVoedingsmiddel.Getaantalporties()) };
        anElement.setAttribute(_T("aantalporties"), buffer.c_str());
    }
}


}

//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlVoedingsmiddeldefWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlVoedingsmiddeldef.h"

#include "XmlVoedingswaardeWriter.h"
#include "XmlVoedingswaarde.h"
#include "XmlPortieWriter.h"
#include "XmlPortie.h"
namespace ww2024
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddeldefWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddeldef"));
    Fill(aDocument, aVoedingsmiddeldef, *element);
    return element;
}

void XmlVoedingsmiddeldefWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

    XmlVoedingswaardeWriter Voedingswaardewriter;
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, aVoedingsmiddeldef.GetVoedingswaarde()));

    XmlPortieWriter Portiewriter;
    for (size_t i = 0; i < aVoedingsmiddeldef.GetPortieList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Portienode = Portiewriter.Write(aDocument, *aVoedingsmiddeldef.GetPortieList()[i]);
        anElement.appendChild(Portienode);
    }
  anElement.setAttribute(_T("naam"), aVoedingsmiddeldef.Getnaam().c_str());
  anElement.setAttribute(_T("categorie"), aVoedingsmiddeldef.Getcategorie().c_str());
  if (!aVoedingsmiddeldef.Getmerk().empty())
    anElement.setAttribute(_T("merk"), aVoedingsmiddeldef.Getmerk().c_str());
  anElement.setAttribute(_T("unit"), aVoedingsmiddeldef.Getunit().c_str());
    switch (aVoedingsmiddeldef.Getfavoriet())
    {
        case XmlVoedingsmiddeldef::favoriet::yes:
            anElement.setAttribute(_T("favoriet"), _T("yes"));
        break;
        case XmlVoedingsmiddeldef::favoriet::no:
            anElement.setAttribute(_T("favoriet"), _T("no"));
        break;
        default:
            throw 1;
    }
}


}

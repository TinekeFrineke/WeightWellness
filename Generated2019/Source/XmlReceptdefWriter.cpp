//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlReceptdefWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlReceptdef.h"

#include "XmlVoedingsmiddelWriter.h"
#include "XmlVoedingsmiddel.h"
#include "XmlReceptWriter.h"
#include "XmlRecept.h"
#include "XmlGerechtWriter.h"
#include "XmlGerecht.h"
#include "XmlHandmatigitemWriter.h"
#include "XmlHandmatigitem.h"
namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlReceptdefWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlReceptdef & aReceptdef)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("receptdef"));
    Fill(aDocument, aReceptdef, *element);
    return element;
}

void XmlReceptdefWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlReceptdef & aReceptdef, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

    XmlVoedingsmiddelWriter Voedingsmiddelwriter;
    for (size_t i = 0; i < aReceptdef.GetVoedingsmiddelList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Voedingsmiddelnode = Voedingsmiddelwriter.Write(aDocument, *aReceptdef.GetVoedingsmiddelList()[i]);
        anElement.appendChild(Voedingsmiddelnode);
    }

    XmlReceptWriter Receptwriter;
    for (size_t i = 0; i < aReceptdef.GetReceptList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Receptnode = Receptwriter.Write(aDocument, *aReceptdef.GetReceptList()[i]);
        anElement.appendChild(Receptnode);
    }

    XmlGerechtWriter Gerechtwriter;
    for (size_t i = 0; i < aReceptdef.GetGerechtList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Gerechtnode = Gerechtwriter.Write(aDocument, *aReceptdef.GetGerechtList()[i]);
        anElement.appendChild(Gerechtnode);
    }

    XmlHandmatigitemWriter Handmatigitemwriter;
    for (size_t i = 0; i < aReceptdef.GetHandmatigitemList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Handmatigitemnode = Handmatigitemwriter.Write(aDocument, *aReceptdef.GetHandmatigitemList()[i]);
        anElement.appendChild(Handmatigitemnode);
    }
  anElement.setAttribute(_T("naam"), aReceptdef.Getnaam().c_str());
  anElement.setAttribute(_T("porties"), aReceptdef.Getporties().c_str());
}


}

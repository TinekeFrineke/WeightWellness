//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlPortieomschrijvingWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlPortieomschrijving.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlPortieomschrijvingWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortieomschrijving & aPortieomschrijving)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("portieomschrijving"));
    Fill(aDocument, aPortieomschrijving, *element);
    return element;
}

void XmlPortieomschrijvingWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortieomschrijving & aPortieomschrijving, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aPortieomschrijving;
    (void)anElement;
  anElement.setAttribute(_T("omschrijving"), aPortieomschrijving.Getomschrijving().c_str());
}


}

//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlPortieWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlPortie.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlPortieWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortie & aPortie)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("portie"));
    Fill(aDocument, aPortie, *element);
    return element;
}

void XmlPortieWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlPortie & aPortie, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aPortie;
    (void)anElement;
  anElement.setAttribute(_T("naam"), aPortie.Getnaam().c_str());
  anElement.setAttribute(_T("eenheden"), aPortie.Geteenheden().c_str());
}


}

//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlGerechtdefWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlGerechtdef.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlGerechtdefWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerechtdef & aGerechtdef)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("gerechtdef"));
    Fill(aDocument, aGerechtdef, *element);
    return element;
}

void XmlGerechtdefWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlGerechtdef & aGerechtdef, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
    (void)aDocument;
    (void)aGerechtdef;
    (void)anElement;
  anElement.setAttribute(_T("naam"), aGerechtdef.Getnaam().c_str());
  anElement.setAttribute(_T("punten"), aGerechtdef.Getpunten().c_str());
}


}

//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================

#include "XmlBonuslistWriter.h"

#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>

#include "XmlBonuslist.h"

#include "XmlBonuscellWriter.h"
#include "XmlBonuscell.h"
namespace ww2024
{
XERCES_CPP_NAMESPACE::DOMNode * XmlBonuslistWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuslist & aBonuslist)
{
    XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("bonuslist"));
    Fill(aDocument, aBonuslist, *element);
    return element;
}

void XmlBonuslistWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlBonuslist & aBonuslist, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

    XmlBonuscellWriter Bonuscellwriter;
    for (size_t i = 0; i < aBonuslist.GetBonuscellList().size(); ++i)
    {
        XERCES_CPP_NAMESPACE::DOMNode * Bonuscellnode = Bonuscellwriter.Write(aDocument, *aBonuslist.GetBonuscellList()[i]);
        anElement.appendChild(Bonuscellnode);
    }
}


}

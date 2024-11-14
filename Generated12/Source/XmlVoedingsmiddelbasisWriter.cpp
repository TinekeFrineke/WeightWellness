#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlVoedingsmiddelbasis.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlVoedingsmiddelheaderWriter.h"
#include "../Interface\Generated\XmlVoedingsmiddelheader.h"
#include "../Interface\Generated\XmlVoedingsmiddelbasisWriter.h"

namespace ww_1_2
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddelbasisWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddelbasis & aVoedingsmiddelbasis)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddelbasis"));
  Fill(aDocument, aVoedingsmiddelbasis, *element);
  return element;
}

void XmlVoedingsmiddelbasisWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddelbasis & aVoedingsmiddelbasis, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlVoedingsmiddelheaderWriter Voedingsmiddelheaderwriter;
  anElement.appendChild(Voedingsmiddelheaderwriter.Write(aDocument, aVoedingsmiddelbasis.GetVoedingsmiddelheader()));
  anElement.setAttribute(_T("sterreportie"), aVoedingsmiddelbasis.Getsterreportie().c_str());
  switch (aVoedingsmiddelbasis.Getvrijeportie())
  {
    case XmlVoedingsmiddelbasis::vrijeportie_true:
      anElement.setAttribute(_T("vrijeportie"), _T("true"));
    break;
    case XmlVoedingsmiddelbasis::vrijeportie_false:
      anElement.setAttribute(_T("vrijeportie"), _T("false"));
    break;
    default:
      throw 1;
  }
  anElement.setAttribute(_T("vrijepunten"), aVoedingsmiddelbasis.Getvrijepunten().c_str());
  switch (aVoedingsmiddelbasis.Getvrijeppportie())
  {
    case XmlVoedingsmiddelbasis::vrijeppportie_true:
      anElement.setAttribute(_T("vrijeppportie"), _T("true"));
    break;
    case XmlVoedingsmiddelbasis::vrijeppportie_false:
      anElement.setAttribute(_T("vrijeppportie"), _T("false"));
    break;
    default:
      throw 1;
  }
  anElement.setAttribute(_T("vrijepppunten"), aVoedingsmiddelbasis.Getvrijepppunten().c_str());
}


}

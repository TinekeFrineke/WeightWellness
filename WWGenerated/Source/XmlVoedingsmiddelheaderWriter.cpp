#include "stdafx.h"

#include "XmlVoedingsmiddelheader.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlVoedingsmiddelheaderWriter.h"

namespace ww_1_1
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddelheaderWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddelheader & aVoedingsmiddelheader)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddelheader"));
  Fill(aDocument, aVoedingsmiddelheader, *element);
  return element;
}

void XmlVoedingsmiddelheaderWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddelheader & aVoedingsmiddelheader, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aVoedingsmiddelheader;
  (void)anElement;
  anElement.setAttribute(_T("naam"), aVoedingsmiddelheader.Getnaam().c_str());
  anElement.setAttribute(_T("categorie"), aVoedingsmiddelheader.Getcategorie().c_str());
  if (!aVoedingsmiddelheader.Getmerk().empty())
    anElement.setAttribute(_T("merk"), aVoedingsmiddelheader.Getmerk().c_str());
  anElement.setAttribute(_T("unit"), aVoedingsmiddelheader.Getunit().c_str());
}


}

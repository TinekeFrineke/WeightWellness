#include "../Interface/stdafx.h"

#include "../Interface/XmlVoedingsmiddel.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlStandardlotWriter.h"
#include "../Interface/XmlStandardlot.h"
#include "../Interface/XmlVoedingsmiddelWriter.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddelWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddel & aVoedingsmiddel)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddel"));
  Fill(aDocument, aVoedingsmiddel, *element);
  return element;
}

void XmlVoedingsmiddelWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddel & aVoedingsmiddel, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlStandardlotWriter Standardlotwriter;
  if (aVoedingsmiddel.GetStandardlot() != NULL)
    anElement.appendChild(Standardlotwriter.Write(aDocument, *aVoedingsmiddel.GetStandardlot()));
  anElement.setAttribute(_T("naam"), aVoedingsmiddel.Getnaam().c_str());
  anElement.setAttribute(_T("categorie"), aVoedingsmiddel.Getcategorie().c_str());
  if (!aVoedingsmiddel.Getmerk().empty())
    anElement.setAttribute(_T("merk"), aVoedingsmiddel.Getmerk().c_str());
  anElement.setAttribute(_T("unit"), aVoedingsmiddel.Getunit().c_str());
}


}

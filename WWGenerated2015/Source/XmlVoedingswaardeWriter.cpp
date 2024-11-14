#include "stdafx.h"

#include "XmlVoedingswaarde.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlVoedingswaardeWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingswaardeWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingswaarde & aVoedingswaarde)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingswaarde"));
  Fill(aDocument, aVoedingswaarde, *element);
  return element;
}

void XmlVoedingswaardeWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingswaarde & aVoedingswaarde, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{
  (void)aDocument;
  (void)aVoedingswaarde;
  (void)anElement;
  anElement.setAttribute(_T("kcalper100"), aVoedingswaarde.Getkcalper100().c_str());
  anElement.setAttribute(_T("vetper100"), aVoedingswaarde.Getvetper100().c_str());
  anElement.setAttribute(_T("koolhydratenper100"), aVoedingswaarde.Getkoolhydratenper100().c_str());
  anElement.setAttribute(_T("eiwitper100"), aVoedingswaarde.Geteiwitper100().c_str());
  anElement.setAttribute(_T("vezelsper100"), aVoedingswaarde.Getvezelsper100().c_str());
}


}

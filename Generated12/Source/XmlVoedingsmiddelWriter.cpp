#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlVoedingsmiddel.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlStandardlotWriter.h"
#include "../Interface\Generated\XmlStandardlot.h"
#include "../Interface\Generated\XmlFreelotWriter.h"
#include "../Interface\Generated\XmlFreelot.h"
#include "../Interface\Generated\XmlVoedingsmiddelWriter.h"

namespace ww_1_2
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

  XmlFreelotWriter Freelotwriter;
  if (aVoedingsmiddel.GetFreelot() != NULL)
    anElement.appendChild(Freelotwriter.Write(aDocument, *aVoedingsmiddel.GetFreelot()));
  anElement.setAttribute(_T("naam"), aVoedingsmiddel.Getnaam().c_str());
  anElement.setAttribute(_T("categorie"), aVoedingsmiddel.Getcategorie().c_str());
  if (!aVoedingsmiddel.Getmerk().empty())
    anElement.setAttribute(_T("merk"), aVoedingsmiddel.Getmerk().c_str());
  anElement.setAttribute(_T("unit"), aVoedingsmiddel.Getunit().c_str());
}


}

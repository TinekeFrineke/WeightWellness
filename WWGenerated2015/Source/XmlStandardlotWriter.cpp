#include "stdafx.h"

#include "XmlStandardlot.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlVoedingswaardeWriter.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100Writer.h"
#include "XmlPuntenper100.h"
#include "XmlPortieWriter.h"
#include "XmlPortie.h"
#include "XmlStandardlotWriter.h"

namespace ww2015
{
XERCES_CPP_NAMESPACE::DOMNode * XmlStandardlotWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStandardlot & aStandardlot)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("standardlot"));
  Fill(aDocument, aStandardlot, *element);
  return element;
}

void XmlStandardlotWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStandardlot & aStandardlot, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlVoedingswaardeWriter Voedingswaardewriter;
  if (aStandardlot.GetVoedingswaarde() != NULL)
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, *aStandardlot.GetVoedingswaarde()));

  XmlPuntenper100Writer Puntenper100writer;
  if (aStandardlot.GetPuntenper100() != NULL)
    anElement.appendChild(Puntenper100writer.Write(aDocument, *aStandardlot.GetPuntenper100()));

  XmlPortieWriter Portiewriter;
  anElement.appendChild(Portiewriter.Write(aDocument, aStandardlot.GetPortie()));
  anElement.setAttribute(_T("hoeveelheid"), aStandardlot.Gethoeveelheid().c_str());
}


}

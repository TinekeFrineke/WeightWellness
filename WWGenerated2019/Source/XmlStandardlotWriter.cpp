#include "../Interface/stdafx.h"

#include "../Interface/XmlStandardlot.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlPortieWriter.h"
#include "../Interface/XmlPortie.h"
#include "../Interface/XmlPuntenper100Writer.h"
#include "../Interface/XmlPuntenper100.h"
#include "../Interface/XmlVoedingswaardeWriter.h"
#include "../Interface/XmlVoedingswaarde.h"
#include "../Interface/XmlStandardlotWriter.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlStandardlotWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStandardlot & aStandardlot)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("standardlot"));
  Fill(aDocument, aStandardlot, *element);
  return element;
}

void XmlStandardlotWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlStandardlot & aStandardlot, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlPortieWriter Portiewriter;
  anElement.appendChild(Portiewriter.Write(aDocument, aStandardlot.GetPortie()));

  XmlPuntenper100Writer Puntenper100writer;
  if (aStandardlot.GetPuntenper100() != NULL)
    anElement.appendChild(Puntenper100writer.Write(aDocument, *aStandardlot.GetPuntenper100()));

  XmlVoedingswaardeWriter Voedingswaardewriter;
  if (aStandardlot.GetVoedingswaarde() != NULL)
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, *aStandardlot.GetVoedingswaarde()));
  anElement.setAttribute(_T("hoeveelheid"), aStandardlot.Gethoeveelheid().c_str());
}


}

#include "stdafx.h"

#include "XmlStandardlot.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "XmlPortieWriter.h"
#include "XmlPortie.h"
#include "XmlVoedingswaardeWriter.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100Writer.h"
#include "XmlPuntenper100.h"
#include "XmlStandardlotWriter.h"

namespace ww_1_1
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

  XmlVoedingswaardeWriter Voedingswaardewriter;
  if (aStandardlot.GetVoedingswaarde() != NULL)
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, *aStandardlot.GetVoedingswaarde()));

  XmlPuntenper100Writer Puntenper100writer;
  if (aStandardlot.GetPuntenper100() != NULL)
    anElement.appendChild(Puntenper100writer.Write(aDocument, *aStandardlot.GetPuntenper100()));
  switch (aStandardlot.Getsterrelot())
  {
    case XmlStandardlot::sterrelot_true:
      anElement.setAttribute(_T("sterrelot"), _T("true"));
    break;
    case XmlStandardlot::sterrelot_false:
      anElement.setAttribute(_T("sterrelot"), _T("false"));
    break;
    default:
      throw 1;
  }
  anElement.setAttribute(_T("hoeveelheid"), aStandardlot.Gethoeveelheid().c_str());
}


}

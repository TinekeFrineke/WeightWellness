#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlStandardlot.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface\Generated\XmlVoedingswaardeWriter.h"
#include "../Interface\Generated\XmlVoedingswaarde.h"
#include "../Interface\Generated\XmlPortieWriter.h"
#include "../Interface\Generated\XmlPortie.h"
#include "../Interface\Generated\XmlPuntenper100Writer.h"
#include "../Interface\Generated\XmlPuntenper100.h"
#include "../Interface\Generated\XmlStandardlotWriter.h"

namespace ww_1_2
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

  XmlPortieWriter Portiewriter;
  anElement.appendChild(Portiewriter.Write(aDocument, aStandardlot.GetPortie()));

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

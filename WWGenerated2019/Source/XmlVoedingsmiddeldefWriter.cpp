#include "../Interface/stdafx.h"

#include "../Interface/XmlVoedingsmiddeldef.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlPortieWriter.h"
#include "../Interface/XmlPortie.h"
#include "../Interface/XmlPuntenper100Writer.h"
#include "../Interface/XmlPuntenper100.h"
#include "../Interface/XmlVoedingsmiddelheaderWriter.h"
#include "../Interface/XmlVoedingsmiddelheader.h"
#include "../Interface/XmlVoedingswaardeWriter.h"
#include "../Interface/XmlVoedingswaarde.h"
#include "../Interface/XmlVoedingsmiddeldefWriter.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddeldefWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddeldef"));
  Fill(aDocument, aVoedingsmiddeldef, *element);
  return element;
}

void XmlVoedingsmiddeldefWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlPortieWriter Portiewriter;
  for (size_t i = 0; i < aVoedingsmiddeldef.GetPortieList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Portienode = Portiewriter.Write(aDocument, *aVoedingsmiddeldef.GetPortieList()[i]);
    anElement.appendChild(Portienode);
  }

  XmlPuntenper100Writer Puntenper100writer;
  if (aVoedingsmiddeldef.GetPuntenper100() != NULL)
    anElement.appendChild(Puntenper100writer.Write(aDocument, *aVoedingsmiddeldef.GetPuntenper100()));

  XmlVoedingsmiddelheaderWriter Voedingsmiddelheaderwriter;
  anElement.appendChild(Voedingsmiddelheaderwriter.Write(aDocument, aVoedingsmiddeldef.GetVoedingsmiddelheader()));

  XmlVoedingswaardeWriter Voedingswaardewriter;
  if (aVoedingsmiddeldef.GetVoedingswaarde() != NULL)
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, *aVoedingsmiddeldef.GetVoedingswaarde()));
  switch (aVoedingsmiddeldef.Getfavoriet())
  {
    case XmlVoedingsmiddeldef::favoriet_true:
      anElement.setAttribute(_T("favoriet"), _T("true"));
    break;
    case XmlVoedingsmiddeldef::favoriet_false:
      anElement.setAttribute(_T("favoriet"), _T("false"));
    break;
    default:
      throw 1;
  }
}


}

#include "../Interface\Generated\stdafx.h"

#include "../Interface\Generated\XmlVoedingsmiddeldef.h"
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
#include "../Interface\Generated\XmlVoedingsmiddelbasisWriter.h"
#include "../Interface\Generated\XmlVoedingsmiddelbasis.h"
#include "../Interface\Generated\XmlVoedingsmiddeldefWriter.h"

namespace ww_1_2
{
XERCES_CPP_NAMESPACE::DOMNode * XmlVoedingsmiddeldefWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("voedingsmiddeldef"));
  Fill(aDocument, aVoedingsmiddeldef, *element);
  return element;
}

void XmlVoedingsmiddeldefWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlVoedingsmiddeldef & aVoedingsmiddeldef, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlVoedingswaardeWriter Voedingswaardewriter;
  if (aVoedingsmiddeldef.GetVoedingswaarde() != NULL)
    anElement.appendChild(Voedingswaardewriter.Write(aDocument, *aVoedingsmiddeldef.GetVoedingswaarde()));

  XmlPortieWriter Portiewriter;
  for (size_t i = 0; i < aVoedingsmiddeldef.GetPortieList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Portienode = Portiewriter.Write(aDocument, *aVoedingsmiddeldef.GetPortieList()[i]);
    anElement.appendChild(Portienode);
  }

  XmlPuntenper100Writer Puntenper100writer;
  if (aVoedingsmiddeldef.GetPuntenper100() != NULL)
    anElement.appendChild(Puntenper100writer.Write(aDocument, *aVoedingsmiddeldef.GetPuntenper100()));

  XmlVoedingsmiddelbasisWriter Voedingsmiddelbasiswriter;
  anElement.appendChild(Voedingsmiddelbasiswriter.Write(aDocument, aVoedingsmiddeldef.GetVoedingsmiddelbasis()));
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

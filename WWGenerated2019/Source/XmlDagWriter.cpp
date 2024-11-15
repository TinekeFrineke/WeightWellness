#include "../Interface/stdafx.h"

#include "../Interface/XmlDag.h"
#include <xercesc/dom/dom.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <tchar.h>
#include "../Interface/XmlBonuscellWriter.h"
#include "../Interface/XmlBonuscell.h"
#include "../Interface/XmlGerechtWriter.h"
#include "../Interface/XmlGerecht.h"
#include "../Interface/XmlHandmatigitemWriter.h"
#include "../Interface/XmlHandmatigitem.h"
#include "../Interface/XmlVoedingsmiddelWriter.h"
#include "../Interface/XmlVoedingsmiddel.h"
#include "../Interface/XmlReceptWriter.h"
#include "../Interface/XmlRecept.h"
#include "../Interface/XmlDagWriter.h"

namespace ww2019
{
XERCES_CPP_NAMESPACE::DOMNode * XmlDagWriter::Write(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlDag & aDag)
{
  XERCES_CPP_NAMESPACE::DOMElement * element = aDocument.createElement(_T("dag"));
  Fill(aDocument, aDag, *element);
  return element;
}

void XmlDagWriter::Fill(XERCES_CPP_NAMESPACE::DOMDocument & aDocument, const XmlDag & aDag, XERCES_CPP_NAMESPACE::DOMElement & anElement)
{

  XmlBonuscellWriter Bonuscellwriter;
  for (size_t i = 0; i < aDag.GetBonuscellList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Bonuscellnode = Bonuscellwriter.Write(aDocument, *aDag.GetBonuscellList()[i]);
    anElement.appendChild(Bonuscellnode);
  }

  XmlGerechtWriter Gerechtwriter;
  for (size_t i = 0; i < aDag.GetGerechtList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Gerechtnode = Gerechtwriter.Write(aDocument, *aDag.GetGerechtList()[i]);
    anElement.appendChild(Gerechtnode);
  }

  XmlHandmatigitemWriter Handmatigitemwriter;
  for (size_t i = 0; i < aDag.GetHandmatigitemList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Handmatigitemnode = Handmatigitemwriter.Write(aDocument, *aDag.GetHandmatigitemList()[i]);
    anElement.appendChild(Handmatigitemnode);
  }

  XmlVoedingsmiddelWriter Voedingsmiddelwriter;
  for (size_t i = 0; i < aDag.GetVoedingsmiddelList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Voedingsmiddelnode = Voedingsmiddelwriter.Write(aDocument, *aDag.GetVoedingsmiddelList()[i]);
    anElement.appendChild(Voedingsmiddelnode);
  }

  XmlReceptWriter Receptwriter;
  for (size_t i = 0; i < aDag.GetReceptList().size(); ++i)
  {
    XERCES_CPP_NAMESPACE::DOMNode * Receptnode = Receptwriter.Write(aDocument, *aDag.GetReceptList()[i]);
    anElement.appendChild(Receptnode);
  }
  anElement.setAttribute(_T("bonuspunten"), aDag.Getbonuspunten().c_str());
  anElement.setAttribute(_T("datum"), aDag.Getdatum().c_str());
  anElement.setAttribute(_T("gewicht"), aDag.Getgewicht().c_str());
}


}

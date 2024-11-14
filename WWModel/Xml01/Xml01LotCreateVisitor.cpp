#include "stdafx.h"

#include "Xml01LotCreateVisitor.h"

#include "Xml01Writer.h"

#include "WW/WWGenerated01/XmlFreelot.h"
#include "WW/WWGenerated01/XmlStandardlot.h"
#include "WW/WWGenerated01/XmlVoedingsmiddel.h"


namespace WW_NAMESPACE
{

void XmlLotCreateVisitor::Visit(WW::StandardLot & aLot)
{
  Ww::XmlStandardlot * lot = new WW_GENERATED_NAMESPACE::XmlStandardlot;
  lot->Setsterrelot(WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_false);
  mWriter.Create(aLot, *lot);

  mXmlVoedingsmiddel.Add(lot);
}


void XmlLotCreateVisitor::Visit(WW::FreeLot & aLot)
{
  Ww::XmlFreelot * lot = new WW_GENERATED_NAMESPACE::XmlFreelot;
  mWriter.Create(aLot, *lot);

  mXmlVoedingsmiddel.Add(lot);
}


void XmlLotCreateVisitor::Visit(WW::SterreLot & aLot)
{
  Ww::XmlStandardlot * lot = new WW_GENERATED_NAMESPACE::XmlStandardlot;
  lot->Setsterrelot(WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_true);
  mWriter.Create(aLot, *lot);

  mXmlVoedingsmiddel.Add(lot);
}


} // namespace WW

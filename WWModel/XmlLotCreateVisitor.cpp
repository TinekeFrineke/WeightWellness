#include "stdafx.h"

#include "XmlLotCreateVisitor.h"

#include "XmlWriter.h"

#include <Generated/XmlFreelot.h>
#include <Generated/XmlStandardlot.h>
#include <Generated/XmlVoedingsmiddel.h>


namespace WW_NAMESPACE
{

void XmlLotCreateVisitor::Visit(WW::CalculatedLot & aLot)
{
  WW_GENERATED_NAMESPACE::XmlStandardlot * lot = new WW_GENERATED_NAMESPACE::XmlStandardlot;
  lot->Setsterrelot(aLot.IsSterreLot() ? WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_true : WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_false);
  mWriter.Create(aLot, *lot);

  mXmlVoedingsmiddel.Add(lot);
}


void XmlLotCreateVisitor::Visit(WW::FreeLot & aLot)
{
  WW_GENERATED_NAMESPACE::XmlFreelot * lot = new WW_GENERATED_NAMESPACE::XmlFreelot;
  mWriter.Create(aLot, *lot);

  mXmlVoedingsmiddel.Add(lot);
}


void XmlLotCreateVisitor::Visit(WW::FixedLot & aLot)
{
  WW_GENERATED_NAMESPACE::XmlStandardlot * lot = new WW_GENERATED_NAMESPACE::XmlStandardlot;
  lot->Setsterrelot(aLot.IsSterreLot() ? WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_true : WW_GENERATED_NAMESPACE::XmlStandardlot::sterrelot_false);
  mWriter.Create(aLot, *lot);

  mXmlVoedingsmiddel.Add(lot);
}


} // namespace WW

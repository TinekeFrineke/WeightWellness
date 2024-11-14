#include "stdafx.h"

#include "Xml01ItemCreateVisitor.h"
#include "Xml01Writer.h"

#include "WW/WWGenerated01/XmlDag.h"
#include "WW/WWGenerated01/XmlGerecht.h"
#include "WW/WWGenerated01/XmlHandmatigitem.h"
#include "WW/WWGenerated01/XmlPortie.h"
#include "WW/WWGenerated01/XmlRecept.h"
#include "WW/WWGenerated01/XmlReceptDef.h"
#include "WW/WWGenerated01/XmlVoedingsMiddel.h"

#include "WW/WWModel//Gerecht.h"
#include "WW/WWModel/Recept.h"
#include "WW/WWModel/Voedingsmiddel.h"

namespace WW_NAMESPACE
{


WW_GENERATED_NAMESPACE::XmlVoedingsmiddel * XmlItemCreateVisitor::Create(WW::Voedingsmiddel & aVoedingsmiddel)
{
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddel * voedingsmiddel = new WW_GENERATED_NAMESPACE::XmlVoedingsmiddel;
  mWriter.Create(aVoedingsmiddel, *voedingsmiddel);
  return voedingsmiddel;
}


WW_GENERATED_NAMESPACE::XmlRecept * XmlItemCreateVisitor::Create(WW::Recept & aRecept)
{
  WW_GENERATED_NAMESPACE::XmlRecept * recept = new WW_GENERATED_NAMESPACE::XmlRecept;
  mWriter.Create(aRecept, *recept);
  return recept;
}


WW_GENERATED_NAMESPACE::XmlGerecht * XmlItemCreateVisitor::Create(WW::Gerecht & aGerecht)
{
  WW_GENERATED_NAMESPACE::XmlGerecht * gerecht = new WW_GENERATED_NAMESPACE::XmlGerecht;
  mWriter.Create(aGerecht, *gerecht);
  return gerecht;
}


WW_GENERATED_NAMESPACE::XmlHandmatigitem * XmlItemCreateVisitor::Create(WW::ManualItem & anItem)
{
  WW_GENERATED_NAMESPACE::XmlHandmatigitem * item = new WW_GENERATED_NAMESPACE::XmlHandmatigitem;
  mWriter.Create(anItem, *item);
  return item;
}


void XmlDagItemCreateVisitor::Visit(WW::Recept & aRecept)
{
  mDag.Add(Create(aRecept));
}


void XmlDagItemCreateVisitor::Visit(WW::Gerecht & aGerecht)
{
  mDag.Add(Create(aGerecht));
}


void XmlDagItemCreateVisitor::Visit(WW::Voedingsmiddel & aVoedingsmiddel)
{
  mDag.Add(Create(aVoedingsmiddel));
}


void XmlDagItemCreateVisitor::Visit(WW::ManualItem & anItem)
{
  mDag.Add(Create(anItem));
}


void XmlReceptItemCreateVisitor::Visit(WW::Recept & aRecept)
{
  mReceptDef.Add(Create(aRecept));
}


void XmlReceptItemCreateVisitor::Visit(WW::Gerecht & aGerecht)
{
  mReceptDef.Add(Create(aGerecht));
}


void XmlReceptItemCreateVisitor::Visit(WW::Voedingsmiddel & aVoedingsmiddel)
{
  mReceptDef.Add(Create(aVoedingsmiddel));
}


void XmlReceptItemCreateVisitor::Visit(WW::ManualItem & anItem)
{
  mReceptDef.Add(Create(anItem));
}


} // namespace WW
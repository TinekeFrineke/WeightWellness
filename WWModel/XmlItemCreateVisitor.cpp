#include "stdafx.h"

#include "XmlItemCreateVisitor.h"

#include "XmlWriter.h"

#include <Generated/XmlDag.h>
#include <Generated/XmlGerecht.h>
#include <Generated/XmlHandmatigitem.h>
#include <Generated/XmlPortie.h>
#include <Generated/XmlRecept.h>
#include <Generated/XmlReceptDef.h>
#include <Generated/XmlVoedingsMiddel.h>

#include "Gerecht.h"
#include "Recept.h"
#include "Voedingsmiddel.h"

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
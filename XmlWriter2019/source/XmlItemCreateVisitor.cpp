
#include "XmlItemCreateVisitor.h"

#include "generated/XmlDag.h"
#include "generated/XmlGerecht.h"
#include "generated/XmlHandmatigitem.h"
#include "generated/XmlPortie.h"
#include "generated/XmlRecept.h"
#include "generated/XmlReceptDef.h"
#include "generated/XmlVoedingsMiddel.h"

#include "model/Gerecht.h"
#include "model/Recept.h"
#include "model/Voedingsmiddel.h"

#include "XmlWriter.h"

namespace ww2019
{


std::unique_ptr<XmlVoedingsmiddel> XmlItemCreateVisitor::Create(weight::Voedingsmiddel& aVoedingsmiddel)
{
    auto voedingsmiddel = std::make_unique<XmlVoedingsmiddel>();
    mWriter.Create(aVoedingsmiddel, *voedingsmiddel);
    return voedingsmiddel;
}


std::unique_ptr<XmlRecept> XmlItemCreateVisitor::Create(weight::Recept& aRecept)
{
    auto recept = std::make_unique<XmlRecept>();
    mWriter.Create(aRecept, *recept);
    return recept;
}


std::unique_ptr<XmlGerecht> XmlItemCreateVisitor::Create(weight::Gerecht& aGerecht)
{
    auto gerecht = std::make_unique<XmlGerecht>();
    mWriter.Create(aGerecht, *gerecht);
    return gerecht;
}


std::unique_ptr<XmlHandmatigitem> XmlItemCreateVisitor::Create(weight::ManualItem& anItem)
{
    auto item = std::make_unique<XmlHandmatigitem>();
    mWriter.Create(anItem, *item);
    return item;
}


void XmlDagItemCreateVisitor::Visit(weight::Recept& aRecept)
{
    mDag.Add(Create(aRecept));
}


void XmlDagItemCreateVisitor::Visit(weight::Gerecht& aGerecht)
{
    mDag.Add(Create(aGerecht));
}


void XmlDagItemCreateVisitor::Visit(weight::Voedingsmiddel& aVoedingsmiddel)
{
    mDag.Add(Create(aVoedingsmiddel));
}


void XmlDagItemCreateVisitor::Visit(weight::ManualItem& anItem)
{
    mDag.Add(Create(anItem));
}


void XmlReceptItemCreateVisitor::Visit(weight::Recept& aRecept)
{
    mReceptDef.Add(Create(aRecept));
}


void XmlReceptItemCreateVisitor::Visit(weight::Gerecht& aGerecht)
{
    mReceptDef.Add(Create(aGerecht));
}


void XmlReceptItemCreateVisitor::Visit(weight::Voedingsmiddel& aVoedingsmiddel)
{
    mReceptDef.Add(Create(aVoedingsmiddel));
}


void XmlReceptItemCreateVisitor::Visit(weight::ManualItem& anItem)
{
    mReceptDef.Add(Create(anItem));
}


} // namespace weight
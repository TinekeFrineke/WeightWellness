#pragma once

#include <memory>

#include "model/Item.h"

namespace WW
{
class Recept;
}


namespace ww2019
{
class XmlDag;
class XmlGerecht;
class XmlHandmatigitem;
class XmlRecept;
class XmlReceptdef;
class XmlVoedingsmiddel;
class XmlWriter;


class XmlItemCreateVisitor : public WW::ItemVisitor
{
public:
    XmlItemCreateVisitor(XmlWriter& aWriter) : mWriter(aWriter) {}

protected:
    std::unique_ptr<XmlVoedingsmiddel> Create(WW::Voedingsmiddel& aVoedingsmiddel);
    std::unique_ptr<XmlRecept> Create(WW::Recept& aRecept);
    std::unique_ptr<XmlGerecht> Create(WW::Gerecht& aGerecht);
    std::unique_ptr<XmlHandmatigitem> Create(WW::ManualItem& anItem);

private:
    XmlItemCreateVisitor& operator=(const XmlItemCreateVisitor&) = delete;
    XmlItemCreateVisitor(const XmlItemCreateVisitor&) = delete;

    XmlWriter& mWriter;
};


class XmlDagItemCreateVisitor : public XmlItemCreateVisitor
{
public:
    XmlDagItemCreateVisitor(XmlWriter& aWriter, XmlDag& aDag)
        : XmlItemCreateVisitor(aWriter),
        mDag(aDag) {}

    virtual void            Visit(WW::Recept& aRecept);
    virtual void            Visit(WW::Gerecht& aGerecht);
    virtual void            Visit(WW::Voedingsmiddel& aVoedingsmiddel);
    virtual void            Visit(WW::ManualItem& anItem);

private:
    XmlDagItemCreateVisitor& operator=(const XmlDagItemCreateVisitor&) = delete;
    XmlDagItemCreateVisitor(const XmlDagItemCreateVisitor&) = delete;

    XmlDag& mDag;
};


class XmlReceptItemCreateVisitor : public XmlItemCreateVisitor
{
public:
    XmlReceptItemCreateVisitor(XmlWriter& aWriter, XmlReceptdef& aReceptDef)
        : XmlItemCreateVisitor(aWriter)
        , mReceptDef(aReceptDef) {}

    virtual void            Visit(WW::Recept& aRecept);
    virtual void            Visit(WW::Gerecht& aGerecht);
    virtual void            Visit(WW::Voedingsmiddel& aVoedingsmiddel);
    virtual void            Visit(WW::ManualItem& anItem);

private:
    XmlReceptItemCreateVisitor& operator=(const XmlReceptItemCreateVisitor&) = delete;
    XmlReceptItemCreateVisitor(const XmlReceptItemCreateVisitor&) = delete;

    XmlReceptdef& mReceptDef;
};


}

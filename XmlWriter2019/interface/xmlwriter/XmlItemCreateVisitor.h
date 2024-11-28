#pragma once

#include <memory>

#include "model/Item.h"

namespace weight
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


class XmlItemCreateVisitor : public weight::ItemVisitor
{
public:
    XmlItemCreateVisitor(XmlWriter& aWriter) : mWriter(aWriter) {}

protected:
    std::unique_ptr<XmlVoedingsmiddel> Create(weight::Voedingsmiddel& aVoedingsmiddel);
    std::unique_ptr<XmlRecept> Create(weight::Recept& aRecept);
    std::unique_ptr<XmlGerecht> Create(weight::Gerecht& aGerecht);
    std::unique_ptr<XmlHandmatigitem> Create(weight::ManualItem& anItem);

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

    virtual void            Visit(weight::Recept& aRecept);
    virtual void            Visit(weight::Gerecht& aGerecht);
    virtual void            Visit(weight::Voedingsmiddel& aVoedingsmiddel);
    virtual void            Visit(weight::ManualItem& anItem);

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

    virtual void            Visit(weight::Recept& aRecept);
    virtual void            Visit(weight::Gerecht& aGerecht);
    virtual void            Visit(weight::Voedingsmiddel& aVoedingsmiddel);
    virtual void            Visit(weight::ManualItem& anItem);

private:
    XmlReceptItemCreateVisitor& operator=(const XmlReceptItemCreateVisitor&) = delete;
    XmlReceptItemCreateVisitor(const XmlReceptItemCreateVisitor&) = delete;

    XmlReceptdef& mReceptDef;
};


}

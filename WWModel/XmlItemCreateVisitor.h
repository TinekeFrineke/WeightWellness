#pragma once

#include "Item.h"
#include "XmlDefinitions.h"

namespace WW_GENERATED_NAMESPACE
{
class XmlDag;
class XmlGerecht;
class XmlHandmatigitem;
class XmlRecept;
class XmlReceptdef;
class XmlVoedingsmiddel;
}

namespace WW_NAMESPACE
{


class Recept;
class XmlWriter;


class XmlItemCreateVisitor : public WW::ItemVisitor
{
public:
                          XmlItemCreateVisitor(XmlWriter & aWriter) : mWriter(aWriter) {}

protected:
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddel * Create(WW::Voedingsmiddel & aVoedingsmiddel);
  WW_GENERATED_NAMESPACE::XmlRecept *         Create(WW::Recept & aRecept);
  WW_GENERATED_NAMESPACE::XmlGerecht *        Create(WW::Gerecht & aGerecht);
  WW_GENERATED_NAMESPACE::XmlHandmatigitem *  Create(WW::ManualItem & anItem);

private:
  // Prohibit assignment and copying
  XmlItemCreateVisitor &  operator=(const XmlItemCreateVisitor &);
                          XmlItemCreateVisitor(const XmlItemCreateVisitor &);

  XmlWriter &             mWriter;
};


class XmlDagItemCreateVisitor : public XmlItemCreateVisitor
{
public:
                          XmlDagItemCreateVisitor(XmlWriter & aWriter, WW_GENERATED_NAMESPACE::XmlDag & aDag)
                            : XmlItemCreateVisitor(aWriter),
                              mDag                (aDag) {}

  virtual void            Visit(WW::Recept & aRecept);
  virtual void            Visit(WW::Gerecht & aGerecht);
  virtual void            Visit(WW::Voedingsmiddel & aVoedingsmiddel);
  virtual void            Visit(WW::ManualItem & anItem);

private:
  // Prohibit assignment and copying
  XmlDagItemCreateVisitor &
                          operator=(const XmlDagItemCreateVisitor &);
                          XmlDagItemCreateVisitor(const XmlDagItemCreateVisitor &);

  WW_GENERATED_NAMESPACE::XmlDag &            mDag;
};


class XmlReceptItemCreateVisitor : public XmlItemCreateVisitor
{
public:
                          XmlReceptItemCreateVisitor(XmlWriter & aWriter, WW_GENERATED_NAMESPACE::XmlReceptdef & aReceptDef)
                            : XmlItemCreateVisitor(aWriter),
                              mReceptDef          (aReceptDef) {}

  virtual void            Visit(WW::Recept & aRecept);
  virtual void            Visit(WW::Gerecht & aGerecht);
  virtual void            Visit(WW::Voedingsmiddel & aVoedingsmiddel);
  virtual void            Visit(WW::ManualItem & anItem);

private:
  // Prohibit assignment and copying
  XmlReceptItemCreateVisitor &
                          operator=(const XmlReceptItemCreateVisitor &);
                          XmlReceptItemCreateVisitor(const XmlReceptItemCreateVisitor &);

  WW_GENERATED_NAMESPACE::XmlReceptdef &      mReceptDef;
};


}

#ifndef WWMODEL_XML01LOTCREATEVISITOR_H__
#define WWMODEL_XML01LOTCREATEVISITOR_H__

#include "Xml01Definitions.h"
#include "../Lot.h"


namespace WW_GENERATED_NAMESPACE
{
class XmlVoedingsmiddel;
}

namespace WW_NAMESPACE
{

class XmlWriter;


class XmlLotCreateVisitor : public WW::LotVisitor
{
public:
                                    XmlLotCreateVisitor(XmlWriter &                       aWriter,
                                                        WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & anXmlVoedingsmiddel)
                                    : mWriter           (aWriter),
                                      mXmlVoedingsmiddel(anXmlVoedingsmiddel) {}

  virtual void                      Visit(WW::StandardLot & aLot);
  virtual void                      Visit(WW::FreeLot & aLot);
  virtual void                      Visit(WW::SterreLot & aLot);

private:
  // prohibit copying and assignment
                                    XmlLotCreateVisitor(const XmlLotCreateVisitor &);
  XmlLotCreateVisitor &             operator=(const XmlLotCreateVisitor &);

  XmlWriter &                       mWriter;
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & mXmlVoedingsmiddel;
};


} // namespace WW

#endif // WWMODEL_XML01LOTCREATEVISITOR_H__
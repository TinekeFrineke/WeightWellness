#pragma once

#include "XmlDefinitions.h"
#include "Lot.h"


namespace WW_GENERATED_NAMESPACE
{
class XmlVoedingsmiddel;
}

namespace WW_NAMESPACE
{

class XmlWriter;


// Creates an XmlXxxLot and adds it to the anXmlVoedingsmiddel

class XmlLotCreateVisitor : public WW::LotVisitor
{
public:
                                    XmlLotCreateVisitor(XmlWriter &                                 aWriter,
                                                        WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & anXmlVoedingsmiddel)
                                    : mWriter           (aWriter),
                                      mXmlVoedingsmiddel(anXmlVoedingsmiddel) {}

  virtual void                      Visit(WW::CalculatedLot & aLot);
  virtual void                      Visit(WW::FreeLot & aLot);
  virtual void                      Visit(WW::FixedLot & aLot);

private:
  // prohibit copying and assignment
                                    XmlLotCreateVisitor(const XmlLotCreateVisitor &);
  XmlLotCreateVisitor &             operator=(const XmlLotCreateVisitor &);

  XmlWriter &                       mWriter;
  WW_GENERATED_NAMESPACE::XmlVoedingsmiddel &
                                    mXmlVoedingsmiddel;
};


} // namespace WW

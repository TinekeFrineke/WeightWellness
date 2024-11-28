#pragma once

#include "model/Lot.h"


namespace ww2019
{
class XmlVoedingsmiddel;

class XmlWriter;

// Creates an XmlXxxLot and adds it to the anXmlVoedingsmiddel

class XmlLotCreateVisitor: public weight::LotVisitor
{
public:
    XmlLotCreateVisitor(XmlWriter& aWriter,
                        XmlVoedingsmiddel& anXmlVoedingsmiddel)
        : mWriter(aWriter),
        mXmlVoedingsmiddel(anXmlVoedingsmiddel) {}

    void Visit(weight::CalculatedLot& aLot) override;
    void Visit(weight::FixedLot& aLot) override;

private:
    XmlLotCreateVisitor(const XmlLotCreateVisitor&) = delete;
    XmlLotCreateVisitor& operator=(const XmlLotCreateVisitor&) = delete;

    XmlWriter& mWriter;
    XmlVoedingsmiddel& mXmlVoedingsmiddel;
};


} // namespace weight

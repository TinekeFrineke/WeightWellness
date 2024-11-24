
#include "XmlLotCreateVisitor.h"

#include "XmlWriter.h"

#include "generated/XmlStandardlot.h"
#include "generated/XmlVoedingsmiddel.h"


namespace ww2019
{

void XmlLotCreateVisitor::Visit(WW::CalculatedLot& aLot)
{
    auto lot = std::make_unique<XmlStandardlot>();
    mWriter.Create(aLot, *lot);

    mXmlVoedingsmiddel.Add(std::move(lot));
}


void XmlLotCreateVisitor::Visit(WW::FixedLot& aLot)
{
    auto lot = std::make_unique<XmlStandardlot>();
    mWriter.Create(aLot, *lot);

    mXmlVoedingsmiddel.Add(std::move(lot));
}


} // namespace ww2019

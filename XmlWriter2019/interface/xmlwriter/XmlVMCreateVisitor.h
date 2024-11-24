#pragma once

#include "model/VoedingsmiddelDefinitie.h"

namespace WW
{
class PortionedLot;
}

namespace ww2019
{
class XmlVoedingsmiddeldef;


//class XmlVMCreateVisitor : public WW::VMDefVisitor
//{
//public:
//                                XmlVMCreateVisitor(WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef & aDefinition)
//                                : mDefinition(aDefinition)
//                                {
//                                }
//
//  virtual void                  Visit(WW::CalculatedVMDef & aDefinitie);
//  virtual void                  Visit(WW::FixedVMDef & aDefinitie);
//
//private:
//                                XmlVMCreateVisitor(const XmlVMCreateVisitor &);
//  XmlVMCreateVisitor &          operator=(const XmlVMCreateVisitor &);
//
//  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef &
//                                mDefinition;
//};


class CreateLotFromVMDef/* : public WW::VMDefVisitor*/
{
public:
    CreateLotFromVMDef(const WW::PointsCalculator& aCalculator)
        : mCalculator(aCalculator)
    {
    }

    WW::PortionedLot* Create(WW::VMDefinitie& aDefinitie,
                             WW::Portie& aPortie);

private:
    CreateLotFromVMDef(const CreateLotFromVMDef&) = delete;
    CreateLotFromVMDef& operator=(const CreateLotFromVMDef&) = delete;

    const WW::PointsCalculator& mCalculator;
};

} // namespace ww2019

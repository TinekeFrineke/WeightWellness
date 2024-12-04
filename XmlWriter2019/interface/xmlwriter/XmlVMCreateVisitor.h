#pragma once

#include "model/VoedingsmiddelDefinitie.h"

namespace weight
{
class PortionedLot;
}

namespace ww2019
{
class XmlVoedingsmiddeldef;


//class XmlVMCreateVisitor : public weight::VMDefVisitor
//{
//public:
//                                XmlVMCreateVisitor(WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef & aDefinition)
//                                : mDefinition(aDefinition)
//                                {
//                                }
//
//  virtual void                  Visit(weight::CalculatedVMDef & aDefinitie);
//  virtual void                  Visit(weight::FixedVMDef & aDefinitie);
//
//private:
//                                XmlVMCreateVisitor(const XmlVMCreateVisitor &);
//  XmlVMCreateVisitor &          operator=(const XmlVMCreateVisitor &);
//
//  WW_GENERATED_NAMESPACE::XmlVoedingsmiddeldef &
//                                mDefinition;
//};


class CreateLotFromVMDef/* : public weight::VMDefVisitor*/
{
public:
    CreateLotFromVMDef(std::shared_ptr<weight::PointsCalculator> calculator)
        : m_calculator(calculator)
    {
    }

    std::unique_ptr<weight::PortionedLot> Create(weight::VMDefinitie& aDefinitie,
                                                 weight::Portie& aPortie);

private:
    CreateLotFromVMDef(const CreateLotFromVMDef&) = delete;
    CreateLotFromVMDef& operator=(const CreateLotFromVMDef&) = delete;

    std::shared_ptr<weight::PointsCalculator> m_calculator;
};

} // namespace ww2019

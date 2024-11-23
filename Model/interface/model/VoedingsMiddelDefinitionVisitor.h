#pragma once

namespace WW {

class CalculatedVMDef;
class FixedVMDef;


class VoedingsMiddelDefinitionVisitor
{
public:
    virtual void Visit(CalculatedVMDef& definition) = 0;
    virtual void Visit(FixedVMDef& definition) = 0;
};


}
#pragma once

namespace weight {

class CalculatedVMDef;
class FixedVMDef;


class VoedingsMiddelDefinitionVisitor
{
public:
    virtual ~VoedingsMiddelDefinitionVisitor() = default;
    virtual void Visit(CalculatedVMDef& definition) = 0;
    virtual void Visit(FixedVMDef& definition) = 0;
};


} // namespace weight
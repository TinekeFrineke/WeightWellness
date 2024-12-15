#pragma once

#include <memory>


namespace weight {
class ReceptDefinitie;
}


class IRecipeDefinitionEditor
{
public:
    virtual ~IRecipeDefinitionEditor() = default;
    virtual bool Edit(weight::ReceptDefinitie& portie) const = 0;
    virtual std::unique_ptr<weight::ReceptDefinitie> Create() const = 0;
};


#include "FoodDefinitionRepository.h"

#include "StringRepository.h"
#include "VoedingsmiddelDefinitie.h"

namespace weight {

FoodDefinitionRepository::FoodDefinitionRepository()
    : m_units(std::make_shared<StringRepository>())
    , m_categories(std::make_shared<StringRepository>())
    , m_brands(std::make_shared<StringRepository>())
{
}

bool FoodDefinitionRepository::Has(const std::wstring& name) const
{
    return Repository<VMDefinitie>::Has(name);
}

VMDefinitie* FoodDefinitionRepository::Find(const std::wstring& name) const
{
    return Repository<VMDefinitie>::Find(name);
}

bool FoodDefinitionRepository::Add(std::unique_ptr<VMDefinitie> definition)
{
    auto definitionptr = definition.get();
    if (!Repository<VMDefinitie>::Add(std::move(definition)))
        return false;

    m_categories->Add(definitionptr->GetCategory());
    m_brands->Add(definitionptr->GetMerk());
    m_units->Add(definitionptr->GetUnit());
    return true;
}

bool FoodDefinitionRepository::Remove(const std::wstring& name)
{
    return Repository<VMDefinitie>::Remove(name);
}

void FoodDefinitionRepository::Clear()
{
    Repository<VMDefinitie>::Clear();
}

std::vector<VMDefinitie*> FoodDefinitionRepository::GetAll() const
{
    return Repository<VMDefinitie>::GetAll();
}

} // namespace weight

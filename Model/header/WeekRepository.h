#pragma once

#include <map>

#include "IWeekRepository.h"
//#include "UniqueRepository.h"


namespace weight {

class Week;

class WeekRepository
    : public IWeekRepository
    //, private UniqueRepository<VMDefinitie>
{
public:
    // Inherited via IFoodDefinitionRepository
    //bool Has(const std::wstring& name) const override;
    //VMDefinitie* Find(const std::wstring& name) const override;
    bool Add(std::unique_ptr<Week> definition) override;
    //bool Remove(const std::wstring& name) override;
    void Clear() override;
    std::vector<Week*> GetAll() const override;
};

} // namespace weight

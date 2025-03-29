#pragma once

#include <map>

#include "IWeekRepository.h"


namespace weight {

class Week;

class WeekRepository
    : public IWeekRepository
{
public:
    bool Add(std::unique_ptr<Week> definition) override;
    void Clear() override;
    std::vector<Week*> GetAll() const override;
};

} // namespace weight

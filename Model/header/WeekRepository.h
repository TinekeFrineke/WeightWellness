#pragma once

#include "IWeekRepository.h"


namespace weight {

class Week;

class WeekRepository
    : public IWeekRepository
{
public:
    IWeek* Create(const Utils::Date& date) override;
    bool Add(std::unique_ptr<IWeek> definition) override;
    virtual IWeek* FindWeekContaining(const Utils::Date& date) const override;
    std::vector<IWeek*> GetAll() const override;

private:
    std::vector<std::unique_ptr<IWeek>> m_weeks;
};

} // namespace weight

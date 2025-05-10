#pragma once

#include "IWeekRepository.h"


namespace weight {

class IMessageHandler;
class Week;

class WeekRepository
    : public IWeekRepository
{
public:
    WeekRepository(std::shared_ptr<IMessageHandler> messageHandler);

    IWeek* Create(const Utils::Date& date) override;
    bool Add(std::unique_ptr<IWeek> definition) override;
    virtual IWeek* FindWeekContaining(const Utils::Date& date) const override;
    std::vector<IWeek*> GetAll() const override;

private:
    std::shared_ptr<IMessageHandler> m_messageHandler;
    std::vector<std::unique_ptr<IWeek>> m_weeks;
};

} // namespace weight

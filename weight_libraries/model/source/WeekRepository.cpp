
#include "WeekRepository.h"

#include <sstream>
#include <windows.h>

#include "Utilities/date.h"

#include "IMessageHandler.h"
#include "IWeek.h"
#include "ModelFactory.h"

namespace weight {

WeekRepository::WeekRepository(std::shared_ptr<IMessageHandler> messageHandler)
    : m_messageHandler(std::move(messageHandler))
{
}

IWeek* WeekRepository::Create(const Utils::Date& date)
{
    auto weekptr = FindWeekContaining(date);
    if (weekptr != nullptr)
        return weekptr;

    // Week not found, create a new week
    Utils::Date enddate(date);
    enddate.AddDays(6);
    while (FindWeekContaining(enddate) != nullptr && enddate != date)
        enddate.SubtractDays(1);

    auto week = ModelFactory(m_messageHandler).CreateWeek(date, enddate);
    weekptr = week.get();
    if (Add(std::move(week)))
        return weekptr;

    return nullptr;
}

bool WeekRepository::Add(std::unique_ptr<IWeek> aWeek)
{
    for (const auto& week : m_weeks)
    {
        if (week->GetStartDate() == aWeek->GetStartDate())
        {
            std::stringstream message;
            message << "Could not add week with startdate  " << ToString(aWeek->GetStartDate());
            m_messageHandler->error(message.str());
            return false;
        }
        else
        {
            auto date = aWeek->GetStartDate();
            while (date != aWeek->GetEndDate()) {
                if (week->Includes(date)) {
                    std::stringstream message;
                    message << "Could not add week : Overlaps with " << ToString(week->GetStartDate())
                        << " - " << ToString(week->GetEndDate());
                    m_messageHandler->error(message.str());
                    return false;
                }

                date.AddDays(1);
            }
        }
    }

    m_weeks.push_back(std::move(aWeek));
    return true;
}

IWeek* WeekRepository::FindWeekContaining(const Utils::Date& date) const
{
    for (const auto& week : m_weeks)
        if (week->Includes(date))
            return week.get();

    return nullptr;
}

std::vector<IWeek*> WeekRepository::GetAll() const
{
    std::vector<IWeek*> weeks;
    for (const auto& week : m_weeks)
        weeks.push_back(week.get());

    return weeks;
}

} // namespace weight
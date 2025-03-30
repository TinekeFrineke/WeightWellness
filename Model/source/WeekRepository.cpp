
#include "WeekRepository.h"

#include <sstream>
#include <windows.h>

#include "Utilities/date.h"

#include "IWeek.h"
#include "ModelFactory.h"

namespace weight {

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

    auto week = ModelFactory().CreateWeek(date, enddate);
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
            std::wstringstream message;
            message << L"Could not add week with startdate  " << ToString(aWeek->GetStartDate());
            ::MessageBox(0, message.str().c_str(), _T("ERROR"), MB_OK);
            return false;
        }
        else
        {
            auto date = aWeek->GetStartDate();
            while (date != aWeek->GetEndDate()) {
                if (week->Includes(date)) {
                    std::wstringstream message;
                    message << L"Could not add week : Overlaps with " << ToString(week->GetStartDate())
                        << L" - " << ToString(week->GetEndDate());
                    ::MessageBox(0, message.str().c_str(), _T("ERROR"), MB_OK);
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
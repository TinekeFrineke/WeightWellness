
#include "ViewModelUtilities.h"

#include "model/Model.h"
#include "model/Week.h"

namespace viewmodel {


weight::Week* getOrCreateWeek(weight::Model& model, const Utils::Date& date)
{
    auto currentWeek = model.FindWeek(date);
    if (currentWeek == nullptr)
        currentWeek = model.CreateWeek(date);

    if (currentWeek == nullptr)
        throw std::runtime_error("Could not create week for " + Str::ToString(ToString(date)));

    return currentWeek;
}

weight::Day* getOrCreateDay(const weight::Model& model, weight::Week& week, const Utils::Date date)
{
    if (!week.Includes(date))
        throw std::runtime_error("Could not create day for " + Str::ToString(ToString(date)) + " in this week");

    auto currentDay = week.GetDay(date);
    if (currentDay == nullptr)
        currentDay = week.AddDay(model, date);

    if (currentDay == nullptr)
        throw std::runtime_error("Could not create day for " + Str::ToString(ToString(date)));

    return currentDay;
}

} // namespace viewmodel

#include "ModelFactory.h"

#include "Day.h"
#include "Model.h"
#include "Week.h"

namespace weight {

std::unique_ptr<IModel> ModelFactory::CreateModel()
{
    return std::make_unique<weight::Model>();
}

std::unique_ptr<IWeek> ModelFactory::CreateWeek(const Utils::Date& aStartDate, const Utils::Date& aEndDate)
{
    return std::make_unique<Week>(aStartDate, aEndDate);
}
std::unique_ptr<IDay> ModelFactory::CreateDay(const Utils::Date& date)
{
    return std::make_unique<Day>(date);
}
}
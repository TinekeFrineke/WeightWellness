
#include "ModelFactory.h"

#include "Day.h"

namespace weight {
std::unique_ptr<IDay> ModelFactory::CreateDay(const Utils::Date& date)
{
    return std::make_unique<Day>(date);
}
}
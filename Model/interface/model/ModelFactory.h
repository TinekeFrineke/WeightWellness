
#pragma once

#include <memory>

namespace Utils {
class Date;
}

namespace weight {

class IDay;
class IWeek;

class ModelFactory {
public:
    //std::unique_ptr<IModel> CreateModel();
    std::unique_ptr<IWeek> CreateWeek(const Utils::Date& aStartDate, const Utils::Date& aEndDate);
    std::unique_ptr<IDay> CreateDay(const Utils::Date& date);
};

}
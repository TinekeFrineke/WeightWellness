
#pragma once

#include <memory>

namespace Utils {
class Date;
}

namespace weight {

class IDay;

class ModelFactory {
public:
    //std::unique_ptr<IModel> CreateModel();
    //std::unique_ptr<IWeek> CreateWeek();
    std::unique_ptr<IDay> CreateDay(const Utils::Date& date);
};

}
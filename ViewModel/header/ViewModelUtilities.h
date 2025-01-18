
#pragma once

namespace Utils
{
class Date;
}

namespace weight {

class Day;
class Model;
class Week;

}

namespace viewmodel {


weight::Week* getOrCreateWeek(weight::Model& model, const Utils::Date& date);
weight::Day* getOrCreateDay(const weight::Model& model, weight::Week& week, const Utils::Date date);


} // namespace viewmodel
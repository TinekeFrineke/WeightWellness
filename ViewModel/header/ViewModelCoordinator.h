#pragma once

#include <memory>

#include <Utilities/date.h>

namespace weight {
class Day;
class Model;
class Week;
}

namespace factory {
class IViewModelFactory;
}


namespace viewmodel {


class Day;
class Week;

class Coordinator
{
public:
    Coordinator(weight::Model& model, std::unique_ptr<factory::IViewModelFactory> m_factory);
    ~Coordinator();

    // Inherited via IWeek
    void NextDay();
    void PreviousDay();
    void SetEndOfWeek(const Utils::Date& date);

private:
    void SetDate(const Utils::Date& date);

    weight::Model& m_model;
    std::unique_ptr<factory::IViewModelFactory> m_factory;
    Utils::Date m_date;
    std::unique_ptr<Day> m_day;
    std::unique_ptr<Week> m_week;
};


} // namespace viewmodel
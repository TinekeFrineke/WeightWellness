#pragma once


#include <memory>

namespace factory {

namespace viewmodel {
class IDay;
class IWeek;
}

class IViewModelFactory
{
public:
    virtual ~IViewModelFactory() = default;

    virtual std::unique_ptr<viewmodel::IWeek> CreateWeekViewModel() = 0;
    virtual std::unique_ptr<viewmodel::IDay> CreateDayViewModel() = 0;
};


} // namespace factory
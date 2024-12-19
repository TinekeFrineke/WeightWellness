#pragma once


#include <memory>

namespace factory {

//namespace viewmodel {
//class IDay;
//class IWeek;
//}

namespace Private {
class IDayInterface;
class IWeekInterface;
}
class IViewModelFactory
{
public:
    virtual ~IViewModelFactory() = default;

    //virtual std::unique_ptr<Private::IWeekInterface> CreateWeek() = 0;
    //virtual std::unique_ptr<Private::IDayInterface> CreateDay() = 0;
};


} // namespace factory
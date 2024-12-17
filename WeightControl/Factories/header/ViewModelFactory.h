#pragma once


#include "IViewModelFactory.h"

namespace weight {
class Model;
}

namespace factory {

class ViewModelFactory:
    public IViewModelFactory
{
public:
    ViewModelFactory(weight::Model& model);
    ~ViewModelFactory();

    //// Inherited via IViewModelFactory
    //std::unique_ptr<viewmodel::IWeek> CreateWeekViewModel() override;
    //std::unique_ptr<viewmodel::IDay> CreateDayViewModel() override;

private:
    weight::Model& m_model;

};

} // namespace factory
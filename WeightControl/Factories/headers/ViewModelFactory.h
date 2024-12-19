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

    // Inherited via IViewModelFactory
    //virtual std::unique_ptr<Private::IWeekInterface> CreateWeek() override;
    //virtual std::unique_ptr<Private::IDayInterface> CreateDay() override;

private:
    weight::Model& m_model;

};

} // namespace factory
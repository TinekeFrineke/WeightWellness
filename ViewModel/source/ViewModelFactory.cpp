
#include "ViewModelFactory.h"

#include "Day.h"
#include "PersonalData.h"
#include "ViewModel.h"
#include "Week.h"


namespace viewmodel
{

//void RegisterViewModelTypes()
//{
//    qmlRegisterType<IViewModel>("com.yourcompany.viewmodel", 1, 0, "ConcreteViewModel");
//}


std::unique_ptr<IViewModel> CreateViewModel(std::shared_ptr<weight::Model> model)
{
    auto personalData(std::make_unique<PersonalData>(model));
    auto day(std::make_unique<Day>(model));
    auto week(std::make_unique<Week>(model));
    return std::make_unique<ViewModel>(std::move(model), std::move(personalData), std::move (day),
                                       std::move(week));
}

} // namespace viewmodel

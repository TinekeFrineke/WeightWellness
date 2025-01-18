
#include "ViewModelFactory.h"

#include "model/Day.h"
#include "model/Model.h"
#include "model/Week.h"

#include "Day.h"
#include "PersonalData.h"
#include "ViewModel.h"
#include "ViewModelUtilities.h"
#include "Week.h"


namespace viewmodel
{

//void RegisterViewModelTypes()
//{
//    qmlRegisterType<IViewModel>("com.yourcompany.viewmodel", 1, 0, "ConcreteViewModel");
//}


std::unique_ptr<IViewModel> CreateViewModel(std::shared_ptr<weight::Model> model)
{
    std::unique_ptr<IViewModelDay> day(std::make_unique<Day>(model));
    std::unique_ptr<IViewModelWeek> week(std::make_unique<Week>(model));

    auto currentDate = Utils::Date::Today();
    auto modelPersonalia = model->GetActivePersonalia();
    auto personalData(std::make_unique<PersonalData>(model, modelPersonalia));
    auto modelWeek = getOrCreateWeek(*model, currentDate);
    auto modelDay = getOrCreateDay(*model, *modelWeek, currentDate);
    day->setDay(modelDay);
    week->setWeek(modelWeek);

    return std::make_unique<ViewModel>(currentDate, std::move(model),
                                       std::move(personalData), std::move (day),
                                       std::move(week));
}

} // namespace viewmodel

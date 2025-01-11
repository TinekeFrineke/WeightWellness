
#include "ViewModelFactory.h"

#include "ViewModel.h"


namespace viewmodel
{

//void RegisterViewModelTypes()
//{
//    qmlRegisterType<IViewModel>("com.yourcompany.viewmodel", 1, 0, "ConcreteViewModel");
//}


std::unique_ptr<IViewModel> CreateViewModel(std::shared_ptr<weight::Model> model)
{
    return std::make_unique<ViewModel>(std::move(model));
}

} // namespace viewmodel

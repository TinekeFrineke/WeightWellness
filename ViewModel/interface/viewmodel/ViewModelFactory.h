
#pragma once


#include <memory>


namespace weight
{
class Model;
}

namespace viewmodel
{

class IViewModel;


//void RegisterViewModelTypes();
std::unique_ptr<IViewModel> CreateViewModel(std::shared_ptr<weight::Model> model);



} // namespace viewmodel

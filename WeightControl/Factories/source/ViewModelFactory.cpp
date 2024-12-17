
#include "ViewModelFactory.h"

namespace factory {
ViewModelFactory::ViewModelFactory(weight::Model& model)
    : m_model(model)
{
}


ViewModelFactory::~ViewModelFactory() = default;


//std::unique_ptr<viewmodel::IWeek> ViewModelFactory::CreateWeekViewModel()
//{
//    return nullptr;//new viewmodel::IWeek(;
//}
//
//
//std::unique_ptr<viewmodel::IDay> ViewModelFactory::CreateDayViewModel()
//{
//    return nullptr;//std::unique_ptr<viewmodel::IDay>();
//}


} // namespace factory
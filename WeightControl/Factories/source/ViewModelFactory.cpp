
#include "ViewModelFactory.h"

// TODO This is not so nice as this is a rather direct include
#include "ViewModelWeek.h"

namespace factory {
ViewModelFactory::ViewModelFactory(weight::Model& model)
    : m_model(model)
{
}


ViewModelFactory::~ViewModelFactory() = default;

//std::unique_ptr<Private::IWeekInterface> ViewModelFactory::CreateWeek()
//{
//    //auto day = std::move(CreateDay());
//    //auto week = std::make_unique<viewmodel::Week>(m_model, day);
//    return {};
//}

//std::unique_ptr<Private::IDayInterface> ViewModelFactory::CreateDay()
//{
//    return {};// std::unique_ptr<Private::IDayInterface>();
//}


//std::unique_ptr<viewmodel::IWeek> ViewModelFactory::CreateWeek()
//{
//    return nullptr;//new viewmodel::IWeek(;
//}
//
//
//std::unique_ptr<viewmodel::IDay> ViewModelFactory::CreateDay()
//{
//    return nullptr;//std::unique_ptr<viewmodel::IDay>();
//}


} // namespace factory
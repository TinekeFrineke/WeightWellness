
#pragma once

#include "IViewModelDay.h"
#include "IPrivateDay.h"


namespace Private {


class IDayInterface
    : public viewmodel::IDay
    , public IDay
{

};


} // namespace Private
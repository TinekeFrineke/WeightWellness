
#pragma once

#include "IViewModelWeek.h"
#include "IPrivateWeek.h"


namespace Private {


class IWeekInterface
    : public viewmodel::IWeek
    , public IWeek
{

};


} // namespace Private
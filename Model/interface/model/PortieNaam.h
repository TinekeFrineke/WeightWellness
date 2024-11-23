#pragma once

#include <tchar.h>

#include "Utilities/StrUtils.h"

#include "Naam.h"

namespace WW
{

class Model;


class PortieNaam : public Naam
{
public:
                                PortieNaam(WW::Model & aModel, const std::tstring & aName);
};


} // namespace WW

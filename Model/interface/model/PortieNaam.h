#pragma once

#include <tchar.h>

#include "Utilities/StrUtils.h"

#include "Naam.h"

namespace weight
{

class Model;


class PortieNaam : public Naam
{
public:
                                PortieNaam(Model & aModel, const std::tstring & aName);
};


} // namespace weight

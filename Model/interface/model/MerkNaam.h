#pragma once

#include <tchar.h>

#include "Utilities/StrUtils.h"

#include "Naam.h"

namespace weight
{

class Model;


class MerkNaam : public Naam
{
public:
                                MerkNaam(Model & aModel, const std::tstring & aName);
                                MerkNaam() : Naam(_T("")) {}
};

} // namespace weight

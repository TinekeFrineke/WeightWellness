#pragma once

#include <tchar.h>

#include "Utilities/StrUtils.h"

#include "Naam.h"

namespace WW
{

class Model;


class MerkNaam : public Naam
{
public:
                                MerkNaam(WW::Model & aModel, const std::tstring & aName);
                                MerkNaam() : Naam(_T("")) {}
};

} // namespace WW

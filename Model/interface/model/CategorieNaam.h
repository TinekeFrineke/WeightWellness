#pragma once

#include <tchar.h>

#include <Utilities/StrUtils.h>

#include "Naam.h"

namespace weight
{

class Model;


class CategorieNaam: public Naam
{
public:
    CategorieNaam(Model& aModel, const std::tstring& aName);
    CategorieNaam() : Naam(_T("")) {}
};

} // namespace weight

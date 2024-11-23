#pragma once

#include <tchar.h>

#include <Utilities/StrUtils.h>

#include "Naam.h"

namespace WW
{

class Model;


class CategorieNaam: public Naam
{
public:
    CategorieNaam(WW::Model& aModel, const std::tstring& aName);
    CategorieNaam() : Naam(_T("")) {}
};

} // namespace WW

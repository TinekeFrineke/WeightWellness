
#include "CategorieNaam.h"

#include "WWModel.h"


namespace WW
{


CategorieNaam::CategorieNaam(WW::Model& aModel, const std::tstring& aName)
    : Naam(aName)
{
    if (!aName.empty())
        aModel.Add(*this);
}

} // namespace WW

#include "CategorieNaam.h"

#include "Model.h"


namespace weight
{


CategorieNaam::CategorieNaam(Model& aModel, const std::tstring& aName)
    : Naam(aName)
{
    if (!aName.empty())
        aModel.Add(*this);
}

} // namespace weight

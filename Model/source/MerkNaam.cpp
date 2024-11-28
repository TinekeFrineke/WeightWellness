
#include "MerkNaam.h"

#include "Model.h"


namespace weight
{


MerkNaam::MerkNaam(Model& aModel, const std::tstring& aName)
    : Naam(aName)
{
    if (!aName.empty())
        aModel.Add(*this);
}


} // namespace weight

#include "VoedingsmiddelDefinitie.h"

#include <algorithm>
#include <assert.h>

#ifdef FIND_LEAKS
#include <windows.h>
#endif

namespace WW
{


int   Entity<VMDefinitie>::mNumberOfInstances = 0;
int   Entity<CalculatedVMDef>::mNumberOfInstances = 0;
int   Entity<FixedVMDef>::mNumberOfInstances = 0;


VMDefinitie::VMDefinitie(const PointsCalculator& aCalculator,
                         const std::tstring& aName,
                         const Unit& aUnit,
                         VMDefBase* aDefinition)
    : mCalculator(aCalculator),
    mName(aName),
    mUnit(aUnit),
    mFavourite(false),
    mPoints(aDefinition)
{
    assert(mPoints != NULL);
#ifdef FIND_LEAKS
    Register();
#endif
}


VMDefinitie::VMDefinitie(const VMDefinitie& aDefinitie)
    : mCalculator(aDefinitie.mCalculator),
    mCategory(aDefinitie.mCategory),
    mMerk(aDefinitie.mMerk),
    mName(aDefinitie.mName),
    mUnit(aDefinitie.mUnit),
    mFavourite(aDefinitie.mFavourite),
    mPoints(aDefinitie.mPoints->Copy())
{
#ifdef FIND_LEAKS
    Register();
#endif
    for (size_t i = 0; i < aDefinitie.mPortieList.size(); ++i)
    {
        mPortieList.push_back(std::make_unique<Portie>(*aDefinitie.mPortieList[i]));
    }
}


VMDefinitie& VMDefinitie::operator=(const VMDefinitie& aDefinitie)
{
    if (&aDefinitie == this)
        return *this;

    mPoints.reset(aDefinitie.mPoints->Copy());

    mCategory = aDefinitie.mCategory;
    mMerk = aDefinitie.mMerk;
    mName = aDefinitie.mName;
    mUnit = aDefinitie.mUnit;
    mFavourite = aDefinitie.mFavourite;

    mPortieList.clear();

    for (size_t i = 0; i < aDefinitie.mPortieList.size(); ++i)
        mPortieList.push_back(std::make_unique<Portie>(*aDefinitie.mPortieList[i]));

    return *this;
}


VMDefinitie::~VMDefinitie()
{
#ifdef FIND_LEAKS
    Unregister();
#endif
}


bool VMDefinitie::IsCalculated() const
{
    assert(mPoints != NULL);
    return mPoints->IsCalculated();
}


bool VMDefinitie::IsFixed() const
{
    assert(mPoints != NULL);
    return mPoints->IsFixed();
}


CalculatedVMDef* VMDefinitie::GetCalculatedVMDef()
{
    assert(mPoints != NULL);
    return mPoints->GetCalculatedVMDef();
}


FixedVMDef* VMDefinitie::GetFixedVMDef()
{
    assert(mPoints != NULL);
    return mPoints->GetFixedVMDef();
}


bool VMDefinitie::AddPortie(std::unique_ptr<Portie> aPortie)
{
    for (size_t i = 0; i < mPortieList.size(); ++i)
        if (aPortie->GetName() == mPortieList[i]->GetName())
            return false;

    // Portie was not yet found:
    mPortieList.push_back(std::move(aPortie));
    return true;
}


bool VMDefinitie::ReleasePorties(std::vector<std::unique_ptr<Portie>>& aPorties)
{
    for (size_t i = 0; i < mPortieList.size(); ++i)
    {
        for (size_t j = 0; j < aPorties.size(); ++j)
            if (mPortieList[i]->GetName() == aPorties[j]->GetName())
                return false;
    }

    for (size_t i = 0; i < mPortieList.size(); ++i)
        aPorties.push_back(std::move(mPortieList[i]));

    mPortieList.clear();
    return true;
}


bool VMDefinitie::RemovePortie(Portie* aPortie)
{
    for (std::vector<std::unique_ptr<Portie>>::iterator iter = mPortieList.begin(); iter != mPortieList.end(); ++iter)
    {
        if (aPortie == (iter->get()))
        {
            mPortieList.erase(iter);
            return true;
        }
    }

    return false;
}


double VMDefinitie::GetPointsPer100Units() const
{
    return mPoints->GetPointsPer100Units();
}


void VMDefinitie::SetCalculated(const FoodParameters& oParameters)
{
    if (mPoints->IsCalculated())
        return;

    auto def = std::make_unique<CalculatedVMDef>(mCalculator);
    def->SetParameters(oParameters);
    mPoints = std::move(def);
}


void VMDefinitie::SetFixed()
{
    if (mPoints->IsFixed())
        return;

    auto fdef = std::make_unique<FixedVMDef>();
    fdef->SetPointsPer100Units(mPoints->GetPointsPer100Units());
    mPoints = std::move(fdef);
}


CalculatedVMDef::CalculatedVMDef(const PointsCalculator& aCalculator)
    : mCalculator(aCalculator)
{
#ifdef FIND_LEAKS
    Register();
#endif
}


CalculatedVMDef::CalculatedVMDef(const CalculatedVMDef& aVMDef)
    : VMDefBase(aVMDef),
    mCalculator(aVMDef.mCalculator),
    mParameters(aVMDef.mParameters)
{
#ifdef FIND_LEAKS
    Register();
#endif
}


CalculatedVMDef& CalculatedVMDef::operator=(const CalculatedVMDef& aVMDef)
{
    if (&aVMDef == this)
        return *this;

    mParameters = aVMDef.mParameters;
    return *this;
}


CalculatedVMDef::~CalculatedVMDef()
{
#ifdef FIND_LEAKS
    Unregister();
#endif
}


VMDefBase* CalculatedVMDef::Copy() const
{
    return new CalculatedVMDef(*this);
}


FixedVMDef::FixedVMDef()
    : mPointsPer100Units(0)
{
#ifdef FIND_LEAKS
    Register();
#endif
}


FixedVMDef::FixedVMDef(const FixedVMDef& aDef)
    : VMDefBase(aDef),
    mPointsPer100Units(aDef.mPointsPer100Units)
{
#ifdef FIND_LEAKS
    Register();
#endif
}


FixedVMDef::~FixedVMDef()
{
#ifdef FIND_LEAKS
    Unregister();
#endif
}


VMDefBase* FixedVMDef::Copy() const
{
    return new FixedVMDef(*this);
}


} // namespace WW

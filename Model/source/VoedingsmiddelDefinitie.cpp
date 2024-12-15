
#include "VoedingsmiddelDefinitie.h"

#include <algorithm>
#include <assert.h>

#ifdef FIND_LEAKS
#include <windows.h>
#endif

#include "NutritionalValue.h"

namespace weight
{


int Entity<VMDefinitie>::mNumberOfInstances = 0;


VMDefinitie::VMDefinitie(std::shared_ptr<weight::PointsCalculator> calculator,
                         const std::tstring& aName,
                         const std::wstring& aUnit,
                         std::unique_ptr<NutritionalValue> nutritionalValue)
    : m_calculator(std::move(calculator))
    , mName(aName)
    , mUnit(aUnit)
    , mFavourite(false)
    , mPoints(std::move(nutritionalValue))
{
    assert(m_calculator != nullptr);
    assert(mPoints != nullptr);
#ifdef FIND_LEAKS
    Register();
#endif
}


VMDefinitie::VMDefinitie(const VMDefinitie& aDefinitie)
    : m_calculator(aDefinitie.m_calculator)
    , mCategory(aDefinitie.mCategory)
    , mMerk(aDefinitie.mMerk)
    , mName(aDefinitie.mName)
    , mUnit(aDefinitie.mUnit)
    , mFavourite(aDefinitie.mFavourite)
    , mPoints(std::make_unique<NutritionalValue>(*aDefinitie.mPoints))
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

    mPoints = std::make_unique<NutritionalValue>(*aDefinitie.mPoints);

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


bool VMDefinitie::AddPortie(std::unique_ptr<Portie> aPortie)
{
    for (const auto& portie : mPortieList)
        if (aPortie->GetName() == portie->GetName())
            return false;

    // Portie was not yet found:
    mPortieList.push_back(std::move(aPortie));
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

bool VMDefinitie::RemovePortie(const std::wstring& name)
{
    for (std::vector<std::unique_ptr<Portie>>::iterator iter = mPortieList.begin(); iter != mPortieList.end(); ++iter)
    {
        if (name == ((*iter)->GetName()))
        {
            mPortieList.erase(iter);
            return true;
        }
    }

    return false;
}


void VMDefinitie::SetNutritionalValues(const FoodParameters& parameters)
{
    mPoints->SetParameters(parameters);
}


double VMDefinitie::GetPointsPer100Units() const
{
    return mPoints->GetPointsPer100Units();
}


void VMDefinitie::SetKCalPer100Units(double value)
{
    mPoints->SetKCalPer100Units(value);
}


void VMDefinitie::SetVetPer100Units(double value)
{
    mPoints->SetFatPer100Units(value);
}


void VMDefinitie::SetEiwitPer100Units(double value)
{
    mPoints->SetFatPer100Units(value);
}


void VMDefinitie::SetKoolhydratenPer100Units(double value)
{
    mPoints->SetCarbohydratesPer100Units(value);
}


void VMDefinitie::SetVezelsPer100Units(double value)
{
    mPoints->SetFibersPer100Units(value);
}




} // namespace weight

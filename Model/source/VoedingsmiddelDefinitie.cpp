
#include "VoedingsmiddelDefinitie.h"

#include <algorithm>
#include <assert.h>

#ifdef FIND_LEAKS
#include <windows.h>
#endif

namespace weight
{


int   Entity<VMDefinitie>::mNumberOfInstances = 0;
int   Entity<CalculatedVMDef>::mNumberOfInstances = 0;
int   Entity<FixedVMDef>::mNumberOfInstances = 0;


VMDefinitie::VMDefinitie(std::shared_ptr<weight::PointsCalculator> calculator,
                         const std::tstring& aName,
                         const std::wstring& aUnit,
                         std::unique_ptr<VMDefBase> aDefinition)
    : m_calculator(std::move(calculator)),
    mName(aName),
    mUnit(aUnit),
    mFavourite(false),
    mPoints(std::move(aDefinition))
{
    assert(mPoints != NULL);
#ifdef FIND_LEAKS
    Register();
#endif
}


VMDefinitie::VMDefinitie(const VMDefinitie& aDefinitie)
    : m_calculator(aDefinitie.m_calculator),
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

    mPoints = aDefinitie.mPoints->Copy();

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

    auto def = std::make_unique<CalculatedVMDef>(m_calculator);
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


CalculatedVMDef::CalculatedVMDef(std::shared_ptr<PointsCalculator> calculator)
    : m_calculator(calculator)
{
#ifdef FIND_LEAKS
    Register();
#endif
}


CalculatedVMDef::CalculatedVMDef(const CalculatedVMDef& aVMDef)
    : VMDefBase(aVMDef)
    , m_calculator(aVMDef.m_calculator),
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

void CalculatedVMDef::Accept(VoedingsMiddelDefinitionVisitor& visitor)
{
    visitor.Visit(* this);
}

void CalculatedVMDef::SetParameters(const FoodParameters& aParameters)
{
    mParameters = aParameters;
}


std::unique_ptr<VMDefBase> CalculatedVMDef::Copy() const
{
    return std::make_unique<CalculatedVMDef>(*this);
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

void FixedVMDef::Accept(VoedingsMiddelDefinitionVisitor& visitor)
{
    visitor.Visit(*this);
}


std::unique_ptr<VMDefBase> FixedVMDef::Copy() const
{
    return std::make_unique<FixedVMDef>(*this);
}


} // namespace weight

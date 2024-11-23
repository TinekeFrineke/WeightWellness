
#include "WWModel.h"

#include <tchar.h>
#include <assert.h>

#include "Lot.h"
#include "Personalia.h"
#include "PortieNaam.h"
#include "GerechtDefinitie.h"
#include "ReceptDefinitie.h"
#include "VoedingsmiddelDefinitie.h"
#include "Week.h"

namespace WW
{


Model::Model()
    : mStrategyType(STRATEGY_TYPE::KCal)
{
    mCalculator.SetStrategy(STRATEGY_TYPE::KCal);
}


Model::~Model()
{
    Clear();
}


void Model::SetStrategy(STRATEGY_TYPE eType)
{
    if (eType == mStrategyType)
        return;

    mStrategyType = eType;
    mCalculator.SetStrategy(eType);
    if (GetActivePersonalia() != NULL)
        GetActivePersonalia()->SetStrategy(eType);

    Week* week = FindWeek(Utils::Date::Today());

    if (week != NULL)
        week->SetStrategy(eType, *this);
}


void Model::Clear()
{
    mPersonalia.clear();
    mWeeks.clear();
    mVMDefinities.clear();
    mGerechtDefinities.clear();
    mReceptDefinities.clear();
    mUnits.clear();
}


Week* Model::FindWeek(const Utils::Date& aDate)
{
    for (size_t i = 0; i < mWeeks.size(); ++i)
        if (mWeeks[i]->Includes(aDate))
            return mWeeks[i].get();

    return NULL;
}


bool Model::SetEndDate(Week& aWeek, const Utils::Date& aDate)
{
    return aWeek.SetEndDate(aDate);
}


VMDefinitie* Model::FindVoedingsmiddelDefinitie(const std::tstring& aName)
{
    for (size_t i = 0; i < mVMDefinities.size(); ++i)
        if (mVMDefinities[i]->GetName() == aName)
            return mVMDefinities[i].get();

    return NULL;
}


ReceptDefinitie* Model::FindReceptDefinitie(const std::tstring& aName)
{
    for (size_t i = 0; i < mReceptDefinities.size(); ++i)
        if (mReceptDefinities[i]->GetName() == aName)
            return mReceptDefinities[i].get();

    return NULL;
}


bool Model::Add(const Unit& aUnit)
{
    for (size_t i = 0; i < mUnits.size(); ++i)
    {
        if (mUnits[i].GetName() == aUnit.GetName())
            return false;
    }

    mUnits.push_back(aUnit);
    return true;
}


bool Model::Add(std::unique_ptr<Week> aWeek)
{
    for (size_t i = 0; i < mWeeks.size(); ++i)
    {
        if (mWeeks[i]->GetStartDate() == aWeek->GetStartDate())
        {
            TCHAR smsg[1024];
            _stprintf_s(smsg, _T("Could not add week with startdate %s\n"), ToString(aWeek->GetStartDate()).c_str());
            ::MessageBox(0, smsg, _T("ERROR"), MB_OK);
            return false;
        }
    }

    mWeeks.push_back(std::move(aWeek));
    return true;
}


bool Model::Add(std::unique_ptr<VMDefinitie> aDefinitie)
{
    for (size_t i = 0; i < mVMDefinities.size(); ++i)
    {
        if (mVMDefinities[i]->GetName() == aDefinitie->GetName())
        {
            TCHAR smsg[1024];
            _stprintf_s(smsg, _T("Could not add Voedingsmiddeldefinitie %s\n"), aDefinitie->GetName().c_str());
            ::MessageBox(0, smsg, _T("ERROR"), MB_OK);
            return false;
        }
    }

    Add(aDefinitie->GetCategory());
    mVMDefinities.push_back(std::move(aDefinitie));
    return true;
}


bool Model::Add(std::unique_ptr<ReceptDefinitie> aReceptDef)
{
    for (size_t i = 0; i < mReceptDefinities.size(); ++i)
    {
        if (mReceptDefinities[i]->GetName() == aReceptDef->GetName())
        {
            TCHAR smsg[1024];
            _stprintf_s(smsg, _T("Could not add duplicate Recept %s\n"), aReceptDef->GetName().c_str());
            ::MessageBox(0, smsg, _T("ERROR"), MB_OK);
            return false;
        }
    }

    mReceptDefinities.push_back(std::move(aReceptDef));
    return true;
}


bool Model::Add(std::unique_ptr<GerechtDefinitie> aGerechtDef)
{
    for (size_t i = 0; i < mGerechtDefinities.size(); ++i)
    {
        if (mGerechtDefinities[i]->GetName() == aGerechtDef->GetName())
        {
            TCHAR smsg[1024];
            _stprintf_s(smsg, _T("Could not add duplicate Restaurantgerecht %s\n"), aGerechtDef->GetName().c_str());
            ::MessageBox(0, smsg, _T("ERROR"), MB_OK);
            return false;
        }
    }

    mGerechtDefinities.push_back(std::move(aGerechtDef));
    return true;
}


bool Model::Add(const PortieNaam& aOmschrijving)
{
    for (size_t i = 0; i < mPortieNamen.size(); ++i)
        if (mPortieNamen[i].Get() == aOmschrijving.Get())
            return false;

    mPortieNamen.push_back(aOmschrijving);
    return true;
}


bool Model::Add(std::unique_ptr<Personalia> aPersonalia)
{
    if (HasPersonalia(aPersonalia->GetUserName()))
        throw std::runtime_error("Personalia already exists");

    if (mPersonalia.empty())
        SetStrategy(aPersonalia->GetStrategy());

    mPersonalia.push_back(std::move(aPersonalia));
    return true;
}


bool Model::Add(const CategorieNaam& aCategory)
{
    if (aCategory.Get().empty())
        return false;

    for (size_t i = 0; i < mCategorieNamen.size(); ++i)
        if (mCategorieNamen[i] == aCategory)
            return false;

    mCategorieNamen.push_back(aCategory);
    return true;
}


bool Model::Add(const MerkNaam& aMerk)
{
    if (aMerk.Get().empty())
        return false;

    for (size_t i = 0; i < mMerkNamen.size(); ++i)
        if (mMerkNamen[i] == aMerk)
            return false;

    mMerkNamen.push_back(aMerk);
    return true;
}


bool Model::Remove(VMDefinitie* aDefinitie)
{
    for (auto iter = mVMDefinities.begin(); iter != mVMDefinities.end(); ++iter)
    {
        if (iter->get() == aDefinitie)
        {
            mVMDefinities.erase(iter);
            return true;
        }
    }

    return false;
}


bool Model::Remove(ReceptDefinitie* aReceptDef)
{
    for (auto iter = mReceptDefinities.begin();
         iter != mReceptDefinities.end();
         ++iter)
    {
        if (iter->get() == aReceptDef)
        {
            mReceptDefinities.erase(iter);
            return true;
        }
    }

    return false;
}


bool Model::Remove(GerechtDefinitie* aGerechtDef)
{
    for (auto iter = mGerechtDefinities.begin();
         iter != mGerechtDefinities.end();
         ++iter)
    {
        if (iter->get() == aGerechtDef)
        {
            mGerechtDefinities.erase(iter);
            return true;
        }
    }

    return false;
}


bool Model::Remove(Personalia* aPersonalia)
{
    for (auto iter = mPersonalia.begin(); iter != mPersonalia.end(); ++iter)
    {
        if (iter->get() == aPersonalia)
        {
            mPersonalia.erase(iter);
            return true;
        }
    }

    return false;
}


double Model::GetVrijePunten() const
{
    switch (mStrategyType) {
        case STRATEGY_TYPE::KCal:
            return GetPersonalia()[0]->GetKCWeekPuntenTotaal();
        case STRATEGY_TYPE::CarboHydrates:
            return GetPersonalia()[0]->GetCHWeekPuntenTotaal() / 7 - GetPersonalia()[0]->GetCHPuntenTotaal();
        default:
            assert(false);
            return 0;
    }
}

bool Model::HasPersonalia(const std::tstring& name) const
{
    return std::find_if(mPersonalia.begin(),
                        mPersonalia.end(),
                        [name](const std::unique_ptr<Personalia>& personalia) { return personalia->GetUserName() == name; })
        != mPersonalia.end();
}

Personalia* Model::GetActivePersonalia()
{
    if (mPersonalia.empty())
        return NULL;

    return mPersonalia[0].get();
}


const Personalia* Model::GetActivePersonalia() const
{
    if (mPersonalia.empty())
        return NULL;

    return mPersonalia[0].get();
}

Personalia* Model::AddPersonalia(const std::tstring& aName)
{
    if (HasPersonalia(aName))
        throw std::runtime_error("Personalia already exists");

    // Temporary until more persons are supported
    if (!mPersonalia.empty())
        throw std::runtime_error("Personalia not empty");

    mPersonalia.push_back(std::make_unique<Personalia>(aName));
    return mPersonalia.back().get();
}

double Model::GetPuntenTotaal(STRATEGY_TYPE eType) const
{
    return GetActivePersonalia()->GetPuntenTotaal(eType);
}


double Model::GetWeekPuntenTotaal() const
{
    switch (mStrategyType)
    {
        case STRATEGY_TYPE::KCal:
            return GetActivePersonalia()->GetKCWeekPuntenTotaal();
        case STRATEGY_TYPE::CarboHydrates:
            return GetActivePersonalia()->GetCHWeekPuntenTotaal();
        default:
            return 0;
    }
}


}

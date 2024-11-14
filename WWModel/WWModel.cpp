#include "stdafx.h"

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
: mStrategyType(STRATEGY_TYPE::FlexiPoints)
{
  mCalculator.SetStrategy(STRATEGY_TYPE::FlexiPoints);
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

  Week * week = FindWeek(Utils::Date::Today());

  VMDefinitie::SetAllowSterrePortion(eType == STRATEGY_TYPE::FlexiPoints);

  if (week != NULL)
    week->SetStrategy(eType, *this);
}


void Model::Clear()
{
  for (size_t i = 0; i < mWeeks.size(); ++i)
    delete mWeeks[i];
  for (size_t i = 0; i < mVMDefinities.size(); ++i)
    delete mVMDefinities[i];
  for (size_t i = 0; i < mGerechtDefinities.size(); ++i)
    delete mGerechtDefinities[i];
  for (size_t i = 0; i < mReceptDefinities.size(); ++i)
    delete mReceptDefinities[i];
  for (size_t i = 0; i < mPersonalia.size(); ++i)
    delete mPersonalia[i];

  mPersonalia.clear();
  mWeeks.clear();
  mVMDefinities.clear();
  mGerechtDefinities.clear();
  mReceptDefinities.clear();
  mUnits.clear();
}


Week * Model::FindWeek(const Utils::Date & aDate)
{
  for (size_t i = 0; i < mWeeks.size(); ++i)
    if (mWeeks[i]->Includes(aDate))
      return mWeeks[i];

  return NULL;
}


bool Model::SetEndDate(Week & aWeek, const Utils::Date & aDate)
{
  return aWeek.SetEndDate(aDate);
}


VMDefinitie * Model::FindVoedingsmiddelDefinitie(const std::tstring & aName)
{
  for (size_t i = 0; i < mVMDefinities.size(); ++i)
    if (mVMDefinities[i]->GetName() == aName)
      return mVMDefinities[i];

  return NULL;
}


ReceptDefinitie * Model::FindReceptDefinitie(const std::tstring & aName)
{
  for (size_t i = 0; i < mReceptDefinities.size(); ++i)
    if (mReceptDefinities[i]->GetName() == aName)
      return mReceptDefinities[i];

  return NULL;
}


bool Model::Add(const Unit & aUnit)
{
  for (size_t i = 0; i < mUnits.size(); ++i)
  {
    if (mUnits[i].GetName() == aUnit.GetName())
    {
      return false;
    }
  }

  mUnits.push_back(aUnit);
  return true;
}


bool Model::Add(Week * aWeek)
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
      
  mWeeks.push_back(aWeek);
  return true;
}


bool Model::Add(VMDefinitie * aDefinitie)
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

  mVMDefinities.push_back(aDefinitie);
  Add(aDefinitie->GetCategory());
  return true;
}


bool Model::Add(ReceptDefinitie * aReceptDef)
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

  mReceptDefinities.push_back(aReceptDef);
  return true;
}


bool Model::Add(GerechtDefinitie * aGerechtDef)
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

  mGerechtDefinities.push_back(aGerechtDef);
  return true;
}


bool Model::Add(const PortieNaam & aOmschrijving)
{
  for (size_t i = 0; i < mPortieNamen.size(); ++i)
    if (mPortieNamen[i].Get() == aOmschrijving.Get())
      return false;

  mPortieNamen.push_back(aOmschrijving);
  return true;
}


bool Model::Add(Personalia * aPersonalia)
{
  if (HasPersonalia(aPersonalia->GetUserName()))
    throw std::runtime_error("Personalia already exists");

  if (mPersonalia.empty())
    SetStrategy(aPersonalia->GetStrategy());

  mPersonalia.push_back(aPersonalia);
  return true;
}


bool Model::Add(const CategorieNaam & aCategory)
{
  if (aCategory.Get().empty())
    return false;

  for (size_t i = 0; i < mCategorieNamen.size(); ++i)
    if (mCategorieNamen[i] == aCategory)
      return false;

  mCategorieNamen.push_back(aCategory);
  return true;
}


bool Model::Add(const MerkNaam & aMerk)
{
  if (aMerk.Get().empty())
    return false;

  for (size_t i = 0; i < mMerkNamen.size(); ++i)
    if (mMerkNamen[i] == aMerk)
      return false;

  mMerkNamen.push_back(aMerk);
  return true;
}


bool Model::Remove(VMDefinitie * aDefinitie)
{
  for (std::vector<VMDefinitie *>::iterator iter = mVMDefinities.begin(); iter != mVMDefinities.end(); ++iter)
  {
    if (*iter == aDefinitie)
    {
      mVMDefinities.erase(iter);
      delete aDefinitie;
      return true;
    }
  }

  return false;
}


bool Model::Remove(ReceptDefinitie * aReceptDef)
{
  for (std::vector<ReceptDefinitie *>::iterator iter = mReceptDefinities.begin();
       iter != mReceptDefinities.end();
       ++iter)
  {
    if (*iter == aReceptDef)
    {
      mReceptDefinities.erase(iter);
      delete aReceptDef;
      return true;
    }
  }

  return false;
}


bool Model::Remove(GerechtDefinitie * aGerechtDef)
{
  for (std::vector<GerechtDefinitie *>::iterator iter = mGerechtDefinities.begin();
       iter != mGerechtDefinities.end();
       ++iter)
  {
    if (*iter == aGerechtDef)
    {
      mGerechtDefinities.erase(iter);
      delete aGerechtDef;
      return true;
    }
  }

  return false;
}


bool Model::Remove(Personalia * aPersonalia)
{
  for (std::vector<Personalia *>::iterator iter = mPersonalia.begin(); iter != mPersonalia.end(); ++iter)
  {
    if (*iter == aPersonalia)
    {
      mPersonalia.erase(iter);
      delete aPersonalia;
      return true;
    }
  }

  return false;
}


double Model::GetVrijePunten() const
{
  switch (mStrategyType) {
    case STRATEGY_TYPE::FlexiPoints:
      return 4;
    case STRATEGY_TYPE::ProPoints:
      return 7;
    case STRATEGY_TYPE::KCal:
      return GetPersonalia()[0]->GetKCWeekPuntenTotaal() / 7 - GetPersonalia()[0]->GetKCPuntenTotaal();
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
    [name](Personalia* personalia) { return personalia->GetUserName() == name; })
    != mPersonalia.end();
}

Personalia * Model::GetActivePersonalia()
{
  if (mPersonalia.empty())
    return NULL;

  return mPersonalia[0];
}


const Personalia * Model::GetActivePersonalia() const
{
  if (mPersonalia.empty())
    return NULL;

  return mPersonalia[0];
}

Personalia* Model::AddPersonalia(const std::tstring& aName)
{
  if (HasPersonalia(aName))
    throw std::runtime_error("Personalia already exists");

  // Temporary until more persons are supported
  if (!mPersonalia.empty())
    throw std::runtime_error("Personalia not empty");

  Personalia* personalia(new Personalia(aName));
  mPersonalia.push_back(personalia);
  return personalia;
}

double Model::GetPuntenTotaal(STRATEGY_TYPE eType) const
{
  return GetActivePersonalia()->GetPuntenTotaal(eType);
}


double Model::GetWeekPuntenTotaal() const
{
  switch (mStrategyType)
  {
    case STRATEGY_TYPE::ProPoints:
      return GetActivePersonalia()->GetPPWeekPuntenTotaal();
    case STRATEGY_TYPE::KCal:
      return GetActivePersonalia()->GetKCWeekPuntenTotaal();
    case STRATEGY_TYPE::CarboHydrates:
      return GetActivePersonalia()->GetCHWeekPuntenTotaal();
    default:
      return 0;
  }
}


}

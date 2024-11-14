#include "stdafx.h"

#include "VoedingsmiddelDefinitie.h"

#include <algorithm>
#include <assert.h>

#ifdef FIND_LEAKS
#include <windows.h>
#endif

namespace WW
{


bool  VMDefinitie::mAllowSterrePortion            = false;
int   Entity<VMDefinitie>::mNumberOfInstances     = 0;
int   Entity<CalculatedVMDef>::mNumberOfInstances = 0;
int   Entity<FixedVMDef>::mNumberOfInstances      = 0;


VMDefinitie::VMDefinitie(const PointsCalculator & aCalculator,
                         const std::tstring &     aName,
                         const Unit &             aUnit,
                         VMDefBase *              aDefinition)
: mCalculator         (aCalculator),
  mName               (aName),
  mUnit               (aUnit),
  mFavourite          (false),
  mHasFreeFPPortion   (false),
  mFreeFPPortionPoints(0),
  mHasFreePPPortion   (false),
  mFreePPPortionPoints(0),
  mSterrePortie       (NULL),
  mPoints             (aDefinition)
{
  assert(mPoints != NULL);
#ifdef FIND_LEAKS
  Register();
#endif
}


VMDefinitie::VMDefinitie(const VMDefinitie & aDefinitie)
: mCalculator         (aDefinitie.mCalculator),
  mCategory           (aDefinitie.mCategory),
  mMerk               (aDefinitie.mMerk),
  mName               (aDefinitie.mName),
  mUnit               (aDefinitie.mUnit),
  mFavourite          (aDefinitie.mFavourite),
  mHasFreeFPPortion   (aDefinitie.mHasFreeFPPortion),
  mFreeFPPortionPoints(aDefinitie.mFreeFPPortionPoints),
  mHasFreePPPortion   (aDefinitie.mHasFreePPPortion),
  mFreePPPortionPoints(aDefinitie.mFreePPPortionPoints),
  mSterrePortie       (NULL),
  mPoints             (aDefinitie.mPoints->Copy())
{
#ifdef FIND_LEAKS
  Register();
#endif
  for (size_t i = 0; i < aDefinitie.mPortieList.size(); ++i)
  {
    Portie * newportie = new Portie(*aDefinitie.mPortieList[i]);
    mPortieList.push_back(newportie);
    if (aDefinitie.mPortieList[i] == aDefinitie.GetSterrePortion())
      mSterrePortie = newportie;
  }
}


VMDefinitie & VMDefinitie::operator=(const VMDefinitie & aDefinitie)
{
  if (&aDefinitie == this)
    return *this;

  delete mPoints;
  mPoints             = aDefinitie.mPoints->Copy();

  mCategory           = aDefinitie.mCategory;
  mMerk               = aDefinitie.mMerk;
  mName               = aDefinitie.mName;
  mUnit               = aDefinitie.mUnit;
  mFavourite          = aDefinitie.mFavourite;
  mHasFreeFPPortion   = aDefinitie.mHasFreeFPPortion;
  mFreeFPPortionPoints= aDefinitie.mFreeFPPortionPoints;
  mHasFreePPPortion   = aDefinitie.mHasFreePPPortion;
  mFreePPPortionPoints= aDefinitie.mFreePPPortionPoints;
  mSterrePortie       = NULL;
  mSterrePortie       = NULL;

  for (size_t i = 0; i < mPortieList.size(); ++i)
    delete mPortieList[i];

  mPortieList.clear();

  for (size_t i = 0; i < aDefinitie.mPortieList.size(); ++i)
  {
    Portie * newportie = new Portie(*aDefinitie.mPortieList[i]);
    mPortieList.push_back(newportie);
    if (aDefinitie.mPortieList[i] == aDefinitie.GetSterrePortion())
      mSterrePortie = newportie;
  }

  return *this;
}


VMDefinitie::~VMDefinitie()
{
  for (size_t i = 0; i < mPortieList.size(); ++i)
    delete mPortieList[i];

  delete mPoints;

  mSterrePortie = NULL;
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


CalculatedVMDef * VMDefinitie::GetCalculatedVMDef()
{
  assert(mPoints != NULL);
  return mPoints->GetCalculatedVMDef();
}


FixedVMDef * VMDefinitie::GetFixedVMDef()
{
  assert(mPoints != NULL);
  return mPoints->GetFixedVMDef();
}


bool VMDefinitie::AddPortie(Portie * aPortie)
{
  for (size_t i = 0; i < mPortieList.size(); ++i)
    if (aPortie->GetName() == mPortieList[i]->GetName())
      return false;

  // Portie was not yet found:
  mPortieList.push_back(aPortie);
  return true;
}


bool VMDefinitie::ReleasePorties(std::vector<Portie *> & aPorties)
{
  for (size_t i = 0; i < mPortieList.size(); ++i)
  {
    for (size_t j = 0; j < aPorties.size(); ++j)
      if (mPortieList[i]->GetName() == aPorties[j]->GetName())
        return false;
  }

  for (size_t i = 0; i < mPortieList.size(); ++i)
    aPorties.push_back(mPortieList[i]);

  mPortieList.clear();
  return true;
}


bool VMDefinitie::HasFreePortion(STRATEGY_TYPE eType) const
{
  switch (eType)
  {
  case STRATEGY_TYPE::FlexiPoints:
    return HasFreeFPPortion();
  case STRATEGY_TYPE::ProPoints:
    return HasFreePPPortion();
  case STRATEGY_TYPE::KCal:
  case STRATEGY_TYPE::CarboHydrates:
    return false;
  default:
    assert(false);
    return false;
  }
}


double VMDefinitie::GetFreePortionPoints(STRATEGY_TYPE eType) const
{
  switch (eType)
  {
  case STRATEGY_TYPE::FlexiPoints:
    return GetFreeFPPortionPoints();
  case STRATEGY_TYPE::ProPoints:
    return GetFreePPPortionPoints();
  default:
    assert(false);
    return 0;
  }
}


void VMDefinitie::SetHasFreePortion(STRATEGY_TYPE eType, bool aHasFreePortion)
{
  switch (eType)
  {
  case STRATEGY_TYPE::FlexiPoints:
    SetHasFreeFPPortion(aHasFreePortion);
    return;
  case STRATEGY_TYPE::ProPoints:
    SetHasFreePPPortion(aHasFreePortion);
    return;
  case STRATEGY_TYPE::KCal:
  case STRATEGY_TYPE::CarboHydrates:
    assert(!aHasFreePortion);
    return;
  default:
    assert(false);
  }
}


void VMDefinitie::SetFreePortionPoints(STRATEGY_TYPE eType, double aPoints)
{
  switch (eType)
  {
  case STRATEGY_TYPE::FlexiPoints:
    SetFreeFPPortionPoints(aPoints);
    return;
  case STRATEGY_TYPE::ProPoints:
    SetFreePPPortionPoints(aPoints);
    return;
  default:
    assert(false);
  }
}


// Transfers ownership
bool VMDefinitie::SetSterrePortie(const PortieNaam & aNaam)
{
  if (mSterrePortie != NULL && mSterrePortie->GetName() == aNaam)
    return true;

  for (std::vector<Portie *>::iterator iter = mPortieList.begin(); iter != mPortieList.end(); ++iter)
  {
    if ((*iter)->GetName() == aNaam)
    {
      mSterrePortie = *iter;
      return true;
    }
  }

  return false;
}


bool VMDefinitie::RemovePortie(Portie * aPortie)
{
  if (mSterrePortie == aPortie)
    mSterrePortie = NULL;

  for (std::vector<Portie *>::iterator iter = mPortieList.begin(); iter != mPortieList.end(); ++iter)
  {
    if (aPortie == (*iter))
    {
      mPortieList.erase(iter);
      delete aPortie;
      return true;
    }
  }

  return false;
}


void VMDefinitie::RemoveAsSterrePortie(const PortieNaam & aNaam)
{
  if (mSterrePortie != NULL && mSterrePortie->GetName() == aNaam)
    mSterrePortie = NULL;
}


double VMDefinitie::GetPointsPer100Units() const
{
  return mPoints->GetPointsPer100Units();
}


void VMDefinitie::SetCalculated(const FoodParameters & oParameters)
{
  if (mPoints->IsCalculated())
    return;

  delete mPoints;
  CalculatedVMDef * def = new CalculatedVMDef(mCalculator);
  mPoints = def;
  def->SetParameters(oParameters);
}


void VMDefinitie::SetFixed()
{
  if (mPoints->IsFixed())
    return;

  FixedVMDef * fdef = new FixedVMDef;
  fdef->SetPointsPer100Units(mPoints->GetPointsPer100Units());
  delete mPoints;
  mPoints = fdef;
}


CalculatedVMDef::CalculatedVMDef(const PointsCalculator &  aCalculator)
: mCalculator (aCalculator)
{
#ifdef FIND_LEAKS
  Register();
#endif
}


CalculatedVMDef::CalculatedVMDef(const CalculatedVMDef & aVMDef)
: VMDefBase  (aVMDef),
  mCalculator(aVMDef.mCalculator),
  mParameters(aVMDef.mParameters)
{
#ifdef FIND_LEAKS
  Register();
#endif
}


CalculatedVMDef & CalculatedVMDef::operator=(const CalculatedVMDef & aVMDef)
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


VMDefBase * CalculatedVMDef::Copy() const
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


FixedVMDef::FixedVMDef(const FixedVMDef & aDef)
: VMDefBase         (aDef),
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


VMDefBase * FixedVMDef::Copy() const
{
  return new FixedVMDef(*this);
}


} // namespace WW

#pragma once

#include "CategorieNaam.h"
#include "Entity.h"
#include "MerkNaam.h"
#include "PointsCalculator.h"
#include "Portie.h"
#include "PortieNaam.h"
#include "Unit.h"
#include "WWDefinitions.h"

namespace WW
{

class CalculatedVMDef;
class FixedVMDef;


class VMDefBase;
// This is the voedingsmiddel instance in the items page, wchich can be used
// in a concrete voedingsmiddel portion
class VMDefinitie : public Entity<VMDefinitie>
{
public:
                            VMDefinitie(const PointsCalculator &  aCalculator,
                                        const std::tstring &      aName,
                                        const Unit &              aUnit,
                                        VMDefBase *               aDefinition);
                            VMDefinitie(const VMDefinitie &);
  VMDefinitie &             operator=(const VMDefinitie &);

  virtual                   ~VMDefinitie();

  virtual std::tstring      GetName() const     { return mName; }
  const CategorieNaam &     GetCategory() const { return mCategory; }
  const MerkNaam &          GetMerk() const     { return mMerk; }

  virtual double            GetPointsPer100Units() const;

  // Transfers ownership
  bool                      SetSterrePortie(const PortieNaam & aNaam);
  // Transfers ownership
  bool                      AddPortie(Portie * aPortie);
  bool                      RemovePortie(Portie * aPortie);

  void                      SetCategory(const CategorieNaam & aCategory) { mCategory = aCategory; }
  void                      SetMerk(const MerkNaam & aMerk)           { mMerk = aMerk; }
  void                      SetUnit(const Unit & aUnit)               { mUnit = aUnit; }

  void                      SetHasFreePortion(STRATEGY_TYPE eType, bool aHasFreePortion);
  void                      SetFreePortionPoints(STRATEGY_TYPE eType, double aPoints);

  void                      SetHasFreeFPPortion(bool aHasFreePortion) { mHasFreeFPPortion = aHasFreePortion; }
  void                      SetFreeFPPortionPoints(double aPoints)    { mFreeFPPortionPoints = aPoints; }
  void                      SetHasFreePPPortion(bool aHasFreePortion) { mHasFreePPPortion = aHasFreePortion; }
  void                      SetFreePPPortionPoints(double aPoints)    { mFreePPPortionPoints = aPoints; }
  void                      SetFavourite(bool aFavourite)             { mFavourite = aFavourite; }

  bool                      ReleasePorties(std::vector<Portie *> & aPorties);

  // Leaves the normal portion
  void                      RemoveAsSterrePortie(const PortieNaam & aNaam);

  const Unit &              GetUnit() const                         { return mUnit; }

  std::vector<Portie *> &   GetPortieList()                         { return mPortieList; }
  const std::vector<Portie *> &
                            GetPortieList() const                   { return mPortieList; }

  bool                      HasFreePortion(STRATEGY_TYPE eType) const;
  double                    GetFreePortionPoints(STRATEGY_TYPE eType) const;

  bool                      HasFreeFPPortion() const                { return mHasFreeFPPortion; }
  double                    GetFreeFPPortionPoints() const          { return mFreeFPPortionPoints; }
  bool                      HasFreePPPortion() const                { return mHasFreePPPortion; }
  double                    GetFreePPPortionPoints() const          { return mFreePPPortionPoints; }
  bool                      HasSterrePortion() const                { return mAllowSterrePortion && mSterrePortie != NULL; }
  bool                      IsSterrePortion(const Portie * aPortie) { return mAllowSterrePortion && mSterrePortie == aPortie; }
  Portie *                  GetSterrePortion()                      { return mSterrePortie; }
  const Portie *            GetSterrePortion() const                { return mSterrePortie; }

  bool                      IsCalculated() const;
  bool                      IsFixed() const;
  bool                      IsFavourite() const                     { return mFavourite; }

  VMDefBase *               GetVMDef() { return mPoints; }
  CalculatedVMDef *         GetCalculatedVMDef();
  FixedVMDef *              GetFixedVMDef();

  void                      SetCalculated(const FoodParameters & oParameters);
  void                      SetFixed();

  // Entity overrides
  virtual std::tstring      GetInstanceName() const             { return mName; }
  static std::tstring       GetClassName()                      { return _T("VMDefinitie"); }

  static void               SetAllowSterrePortion(bool bAllow)  { mAllowSterrePortion = bAllow; }

private:
  Unit                      mUnit;
  std::tstring              mName;
  CategorieNaam             mCategory;
  MerkNaam                  mMerk;
  std::vector<Portie *>     mPortieList;
  // FlexiPoints
  Portie *                  mSterrePortie;

  bool                      mHasFreeFPPortion;
  double                    mFreeFPPortionPoints;
  bool                      mHasFreePPPortion;
  double                    mFreePPPortionPoints;
  bool                      mFavourite;

  // Can calculate the amount of points based upon the strategy used
  const PointsCalculator &  mCalculator;
  // A voedingsmiddel definition can either be fixed (x points for any amount)
  // or calculated based upon the kcal, fat, protein etc.
  VMDefBase *               mPoints;

  static bool               mAllowSterrePortion;
}; // class VMDefinitie


class CalculatedVMDef;
class FixedVMDef;

class VMDefBase
{
public:
  virtual                   ~VMDefBase() {}

  virtual bool              IsCalculated() const  { return false; }
  virtual bool              IsFixed() const       { return false; }

  virtual CalculatedVMDef * GetCalculatedVMDef()  { return NULL; }
  virtual FixedVMDef *      GetFixedVMDef()       { return NULL; }

  virtual VMDefBase *       Copy() const = 0;
  virtual double            GetPointsPer100Units() const = 0;
};

class CalculatedVMDef : public VMDefBase, public Entity<CalculatedVMDef>
{
public:
                            CalculatedVMDef(const PointsCalculator &  aCalculator);
                            CalculatedVMDef(const CalculatedVMDef &);
  CalculatedVMDef &         operator=(const CalculatedVMDef &);

  virtual                   ~CalculatedVMDef();

  void                      SetParameters(const FoodParameters & aParameters)
                                                                      { mParameters = aParameters; }
  void                      SetKCalPer100Units(double aKCalPer100)    { mParameters.SetKCalPer100Units(aKCalPer100); }
  void                      SetVetPer100Units(double aVetPer100)      { mParameters.SetVetPer100Units(aVetPer100); }
  void                      SetEiwitPer100Units(double anEiwit)       { mParameters.SetEiwitPer100Units(anEiwit); }
  void                      SetKoolhydratenPer100Units(double akh)    { mParameters.SetKoolhydratenPer100Units(akh); }
  void                      SetVezelsPer100Units(double aVezels)      { mParameters.SetVezelsPer100Units(aVezels); }

  const FoodParameters &    GetParameters() const                     { return mParameters; }
  double                    GetPointsPer100Units() const              { return mCalculator.GetPointsPer100Units(mParameters); }
  double                    GetKCalPer100Units() const                { return mParameters.GetKCalPer100Units(); }
  double                    GetVetPer100Units() const                 { return mParameters.GetVetPer100Units(); }
  double                    GetEiwitPer100Units() const               { return mParameters.GetEiwitPer100Units(); }
  double                    GetKoolhydratenPer100Units() const        { return mParameters.GetKoolhydratenPer100Units(); }
  double                    GetVezelsPer100Units() const              { return mParameters.GetVezelsPer100Units(); }

  virtual bool              IsCalculated() const  { return true; }
  virtual CalculatedVMDef * GetCalculatedVMDef()  { return this; }
  virtual VMDefBase *       Copy() const;

  // Entity overrides
  virtual std::tstring      GetInstanceName() const             { return _T("None"); }
  static std::tstring       GetClassName()                      { return _T("CalculatedVMDef"); }

private:
        
  const PointsCalculator &  mCalculator;
  FoodParameters            mParameters;
};


class FixedVMDef : public VMDefBase, public Entity<FixedVMDef>
{
public:
                            FixedVMDef();
                            FixedVMDef(const FixedVMDef &);
  virtual                   ~FixedVMDef();

  void                      SetPointsPer100Units(double aPoints)  { mPointsPer100Units = aPoints; }
  double                    GetPointsPer100Units() const          { return mPointsPer100Units; }

  virtual bool              IsFixed() const                       { return true; }
  virtual FixedVMDef *      GetFixedVMDef()                       { return this; }
  virtual VMDefBase *       Copy() const;

  // Entity overrides
  virtual std::tstring      GetInstanceName() const               { return _T("None"); }
  static std::tstring       GetClassName()                        { return _T("FixedVMDef"); }

private:
  double                    mPointsPer100Units;
};


} // namespace WW

#pragma once

#include <vector>

#include "Utilities/Date.h"
#include "Utilities/StrUtils.h"

#include "BonusPointsMap.h"
#include "MerkNaam.h"
#include "CategorieNaam.h"
#include "PointsCalculator.h"
#include "PortieNaam.h"

namespace WW
{

class CategorieNaam;
class Day;
class Personalia;
class PortieNaam;
class Recept;
class ReceptDefinitie;
class GerechtDefinitie;
class Unit;
class VMDefinitie;
class Week;

class Model
{
public:
                                          Model();
                                          ~Model();

  void                                    Clear();

  STRATEGY_TYPE                           GetStrategy() const { return mStrategyType; }
  void                                    SetStrategy(STRATEGY_TYPE eType);

  bool                                    Add(std::unique_ptr<Week> aWeek);
  bool                                    Add(std::unique_ptr<VMDefinitie> aDefinitie);
  bool                                    Add(std::unique_ptr<ReceptDefinitie> aReceptDef);
  bool                                    Add(std::unique_ptr<GerechtDefinitie> aGerechtDef);
  bool                                    Add(std::unique_ptr<Personalia> aPersonalia);

  bool                                    Add(const Unit & aUnit);
  bool                                    Add(const PortieNaam & aOmschrijving);
  bool                                    Add(const CategorieNaam & aCategory);
  bool                                    Add(const MerkNaam & aMerk);

  bool                                    Remove(VMDefinitie * aDefinitie);
  bool                                    Remove(ReceptDefinitie * aRecept);
  bool                                    Remove(GerechtDefinitie * aGerecht);
  bool                                    Remove(Personalia * aPersonalia);

  Week *                                  FindWeek(const Utils::Date & aDate);
  bool                                    SetEndDate(Week & aWeek, const Utils::Date & aDate);

  VMDefinitie *                           FindVoedingsmiddelDefinitie(const std::tstring & aName);
  ReceptDefinitie *                       FindReceptDefinitie(const std::tstring & aName);

  std::vector<Unit> &                     GetUnits()                          { return mUnits; }
  const std::vector<Unit> &               GetUnits() const                    { return mUnits; }
  std::vector<std::unique_ptr<VMDefinitie>> &            GetVoedingsmiddelDefinities()       { return mVMDefinities; }
  const std::vector<std::unique_ptr<VMDefinitie>> &      GetVoedingsmiddelDefinities() const { return mVMDefinities; }
  std::vector< std::unique_ptr<ReceptDefinitie>> &        GetReceptDefs()                     { return mReceptDefinities; }
  const std::vector<std::unique_ptr<ReceptDefinitie>> &  GetReceptDefs() const               { return mReceptDefinities; }
  std::vector<std::unique_ptr<GerechtDefinitie>> &       GetGerechtDefs()                    { return mGerechtDefinities; }
  const std::vector<std::unique_ptr<GerechtDefinitie>> & GetGerechtDefs() const              { return mGerechtDefinities; }
  std::vector<std::unique_ptr<Week>> &                   GetWeeks()                          { return mWeeks; }
  const std::vector<std::unique_ptr<Week>> &             GetWeeks() const                    { return mWeeks; }
  std::vector<PortieNaam> &               GetPortieNamen()                    { return mPortieNamen; }
  const std::vector<PortieNaam> &         GetPortieNamen() const              { return mPortieNamen; }
  std::vector<CategorieNaam> &            GetCategorieNamen()                 { return mCategorieNamen; }
  const std::vector<CategorieNaam> &      GetCategorieNamen() const           { return mCategorieNamen; }
  std::vector<MerkNaam> &                 GetMerkNamen()                      { return mMerkNamen; }
  const std::vector<MerkNaam> &           GetMerkNamen() const                { return mMerkNamen; }
  std::vector<std::unique_ptr<Personalia>> &             GetPersonalia()                     { return mPersonalia; }
  const std::vector<std::unique_ptr<Personalia>> &       GetPersonalia() const               { return mPersonalia; }
  BonusPointsMap &                        GetBonusPointsMap()                 { return mBonusPointsMap; }
  const BonusPointsMap &                  GetBonusPointsMap() const           { return mBonusPointsMap; }

  double                                  GetPuntenTotaal(STRATEGY_TYPE eType) const;
  double                                  GetWeekPuntenTotaal() const;
  double                                  GetVrijePunten() const;

  bool                                    HasPersonalia(const std::tstring& name) const;
  Personalia *                            GetActivePersonalia();
  const Personalia *                      GetActivePersonalia() const;
  Personalia *                            AddPersonalia(const std::tstring & aName);

  const PointsCalculator &                GetCalculator() const  { return mCalculator; }

private:
  std::vector<Unit> mUnits;
  std::vector<std::unique_ptr<Week>> mWeeks;
  std::vector<std::unique_ptr<VMDefinitie>> mVMDefinities;
  std::vector<std::unique_ptr<ReceptDefinitie>> mReceptDefinities;
  std::vector<std::unique_ptr<GerechtDefinitie>> mGerechtDefinities;
  std::vector<PortieNaam> mPortieNamen;
  std::vector<CategorieNaam> mCategorieNamen;
  std::vector<MerkNaam> mMerkNamen;
  std::vector<std::unique_ptr<Personalia>> mPersonalia;

  BonusPointsMap                          mBonusPointsMap;

  PointsCalculator                        mCalculator;
  STRATEGY_TYPE                           mStrategyType;
};


}

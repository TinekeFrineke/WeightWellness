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

  bool                                    Add(Week * aWeek);
  bool                                    Add(VMDefinitie * aDefinitie);
  bool                                    Add(ReceptDefinitie * aReceptDef);
  bool                                    Add(GerechtDefinitie * aGerechtDef);
  bool                                    Add(Personalia * aPersonalia);

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
  std::vector<VMDefinitie *> &            GetVoedingsmiddelDefinities()       { return mVMDefinities; }
  const std::vector<VMDefinitie *> &      GetVoedingsmiddelDefinities() const { return mVMDefinities; }
  std::vector<ReceptDefinitie *> &        GetReceptDefs()                     { return mReceptDefinities; }
  const std::vector<ReceptDefinitie *> &  GetReceptDefs() const               { return mReceptDefinities; }
  std::vector<GerechtDefinitie *> &       GetGerechtDefs()                    { return mGerechtDefinities; }
  const std::vector<GerechtDefinitie *> & GetGerechtDefs() const              { return mGerechtDefinities; }
  std::vector<Week *> &                   GetWeeks()                          { return mWeeks; }
  const std::vector<Week *> &             GetWeeks() const                    { return mWeeks; }
  std::vector<PortieNaam> &               GetPortieNamen()                    { return mPortieNamen; }
  const std::vector<PortieNaam> &         GetPortieNamen() const              { return mPortieNamen; }
  std::vector<CategorieNaam> &            GetCategorieNamen()                 { return mCategorieNamen; }
  const std::vector<CategorieNaam> &      GetCategorieNamen() const           { return mCategorieNamen; }
  std::vector<MerkNaam> &                 GetMerkNamen()                      { return mMerkNamen; }
  const std::vector<MerkNaam> &           GetMerkNamen() const                { return mMerkNamen; }
  std::vector<Personalia *> &             GetPersonalia()                     { return mPersonalia; }
  const std::vector<Personalia *> &       GetPersonalia() const               { return mPersonalia; }
  BonusPointsMap &                        GetBonusPointsMap()                 { return mBonusPointsMap; }
  const BonusPointsMap &                  GetBonusPointsMap() const           { return mBonusPointsMap; }

  double                                  GetPuntenTotaal(STRATEGY_TYPE eType) const;
  double                                  GetWeekPuntenTotaal() const;

  bool                                    HasPersonalia(const std::tstring& name) const;
  Personalia *                            GetActivePersonalia();
  const Personalia *                      GetActivePersonalia() const;
  Personalia *                            AddPersonalia(const std::tstring & aName);

  const PointsCalculator &                GetCalculator() const  { return mCalculator; }

  bool                                    KentVrijePortie() const { return mStrategyType == STRATEGY_TYPE::FlexiPoints || mStrategyType == STRATEGY_TYPE::ProPoints; }
  double                                  GetVrijePunten() const;

private:
  std::vector<Unit>                       mUnits;
  std::vector<Week *>                     mWeeks;
  std::vector<VMDefinitie *>              mVMDefinities;
  std::vector<ReceptDefinitie *>          mReceptDefinities;
  std::vector<GerechtDefinitie *>         mGerechtDefinities;
  std::vector<PortieNaam>                 mPortieNamen;
  std::vector<CategorieNaam>              mCategorieNamen;
  std::vector<MerkNaam>                   mMerkNamen;
  std::vector<Personalia *>               mPersonalia;

  BonusPointsMap                          mBonusPointsMap;

  PointsCalculator                        mCalculator;
  STRATEGY_TYPE                           mStrategyType;
};


}

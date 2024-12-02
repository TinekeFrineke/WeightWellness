#pragma once

#include <vector>

#include "Utilities/Date.h"
#include "Utilities/StrUtils.h"

#include "BonusPointsMap.h"
#include "PointsCalculator.h"

namespace weight
{

class IBrandRepository;
class ICategoryRepository;
class CategorieNaam;
class Day;
class IRepository;
class Personalia;
class PortieNaam;
class Recept;
class ReceptDefinitie;
class GerechtDefinitie;
class VMDefinitie;
class Week;

class Model
{
public:
    Model();
    ~Model();

    void                                    Clear();

    STRATEGY_TYPE                           GetStrategy() const noexcept { return mStrategyType; }
    void                                    SetStrategy(STRATEGY_TYPE eType);

    bool                                    Add(std::unique_ptr<Week> aWeek);
    bool                                    Add(std::unique_ptr<VMDefinitie> aDefinitie);
    bool                                    Add(std::unique_ptr<ReceptDefinitie> aReceptDef);
    bool                                    Add(std::unique_ptr<GerechtDefinitie> aGerechtDef);
    bool                                    Add(std::unique_ptr<Personalia> aPersonalia);

    void                                    AddUnit(const std::wstring& aUnit);
    bool                                    Add(const PortieNaam& aOmschrijving);
    void                                    AddCategory(const std::wstring& aCategory);
    void                                    AddBrand(const std::wstring& brand);

    bool                                    Remove(VMDefinitie* aDefinitie);
    bool                                    Remove(ReceptDefinitie* aRecept);
    bool                                    Remove(GerechtDefinitie* aGerecht);
    bool                                    Remove(Personalia* aPersonalia);

    Week* FindWeek(const Utils::Date& aDate);
    bool                                    SetEndDate(Week& aWeek, const Utils::Date& aDate);

    VMDefinitie* FindVoedingsmiddelDefinitie(const std::tstring& aName);
    ReceptDefinitie* FindReceptDefinitie(const std::tstring& aName);

    std::vector<std::wstring> GetUnits() const;
    std::vector<std::wstring> GetCategories() const;
    std::vector<std::wstring> GetBrands() const;
    std::vector<std::wstring> GetPortions() const;
    std::vector<std::unique_ptr<VMDefinitie>>& GetVoedingsmiddelDefinities() { return mVMDefinities; }
    const std::vector<std::unique_ptr<VMDefinitie>>& GetVoedingsmiddelDefinities() const { return mVMDefinities; }
    std::vector< std::unique_ptr<ReceptDefinitie>>& GetReceptDefs() { return mReceptDefinities; }
    const std::vector<std::unique_ptr<ReceptDefinitie>>& GetReceptDefs() const { return mReceptDefinities; }
    std::vector<std::unique_ptr<GerechtDefinitie>>& GetGerechtDefs() { return mGerechtDefinities; }
    const std::vector<std::unique_ptr<GerechtDefinitie>>& GetGerechtDefs() const { return mGerechtDefinities; }
    std::vector<std::unique_ptr<Week>>& GetWeeks() { return mWeeks; }
    const std::vector<std::unique_ptr<Week>>& GetWeeks() const { return mWeeks; }
    //std::vector<CategorieNaam>& GetCategorieNamen() { return mCategorieNamen; }
    //const std::vector<CategorieNaam>& GetCategorieNamen() const { return mCategorieNamen; }
    //std::vector<MerkNaam>& GetMerkNamen() { return mMerkNamen; }
    //const std::vector<MerkNaam>& GetMerkNamen() const { return mMerkNamen; }
    std::vector<std::unique_ptr<Personalia>>& GetPersonalia() { return mPersonalia; }
    const std::vector<std::unique_ptr<Personalia>>& GetPersonalia() const { return mPersonalia; }
    BonusPointsMap& GetBonusPointsMap() { return mBonusPointsMap; }
    const BonusPointsMap& GetBonusPointsMap() const { return mBonusPointsMap; }

    double                                  GetPuntenTotaal(STRATEGY_TYPE eType) const;
    double                                  GetWeekPuntenTotaal() const;
    double                                  GetVrijePunten() const;

    bool                                    HasPersonalia(const std::tstring& name) const;
    Personalia* GetActivePersonalia();
    const Personalia* GetActivePersonalia() const;
    Personalia* AddPersonalia(const std::tstring& aName);

    std::shared_ptr<PointsCalculator>       GetCalculator() const { return m_calculator; }

private:
    //std::vector<Unit> mUnits;
    std::shared_ptr<IRepository> m_units;
    std::vector<std::unique_ptr<Week>> mWeeks;
    std::vector<std::unique_ptr<VMDefinitie>> mVMDefinities;
    std::vector<std::unique_ptr<ReceptDefinitie>> mReceptDefinities;
    std::vector<std::unique_ptr<GerechtDefinitie>> mGerechtDefinities;
    std::shared_ptr<IRepository> m_portions;
    //std::vector<PortieNaam> mPortieNamen;
    std::shared_ptr<IRepository> m_categories;
    std::shared_ptr<IRepository> m_brands;
    //std::vector<CategorieNaam> mCategorieNamen;
    //std::vector<MerkNaam> mMerkNamen;
    std::vector<std::unique_ptr<Personalia>> mPersonalia;

    BonusPointsMap                          mBonusPointsMap;

    std::shared_ptr<PointsCalculator>       m_calculator;
    STRATEGY_TYPE                           mStrategyType;
};


}

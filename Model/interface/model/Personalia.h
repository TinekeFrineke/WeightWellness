#pragma once

#include "Utilities/Date.h"
#include "WWDefinitions.h"

namespace weight
{


class Personalia
{
public:
    enum class GESLACHT { Mannelijk, Vrouwelijk };
    enum class WERKTYPE { Zittend, Staand, Lopend, Zwaar };

    explicit Personalia(const std::tstring& aUserName);
    virtual               ~Personalia() = default;

    std::tstring          GetName() const { return mName; }
    std::tstring          GetUserName() const { return mUserName; }
    GESLACHT              GetGeslacht() const { return mGeslacht; }
    Utils::Date           GetDateOfBirth() const { return mDateOfBirth; }
    WERKTYPE              GetTypeOfWork() const { return mWerkType; }
    STRATEGY_TYPE         GetStrategy() const { return mStrategy; }
    double                GetPuntenTotaal(STRATEGY_TYPE eType) const;
    int                   GetKCPuntenTotaal() const { return mKCPuntenTotaal; }
    double                GetCHPuntenTotaal() const { return mCHPuntenTotaal; }
    int                   GetKCWeekPuntenTotaal() const { return mKCWeekPuntenTotaal; }
    double                GetCHWeekPuntenTotaal() const { return mCHWeekPuntenTotaal; }
    double                GetStartGewicht() const { return mStartGewicht; }
    double                GetHuidigGewicht() const { return mHuidigGewicht; }
    double                GetStreefGewicht() const { return mStreefGewicht; }
    int                   GetLengte() const { return mLengte; }

    void                  SetName(const std::tstring& aName) { mName = aName; }
    void                  SetGeslacht(GESLACHT aGeslacht) { mGeslacht = aGeslacht; }
    void                  SetDateOfBirth(const Utils::Date& aDate) { mDateOfBirth = aDate; }
    void                  SetTypeOfWork(WERKTYPE aType) { mWerkType = aType; }
    void                  SetStrategy(STRATEGY_TYPE aType) { mStrategy = aType; }
    void                  SetPuntenTotaal(STRATEGY_TYPE eType, double aValue);
    void                  SetKCPuntenTotaal(int aValue) { mKCPuntenTotaal = aValue; }
    void                  SetCHPuntenTotaal(double value) { mCHPuntenTotaal = value; }
    void                  SetKCWeekPuntenTotaal(int aValue) { mKCWeekPuntenTotaal = aValue; }
    void                  SetCHWeekPuntenTotaal(double aValue) { mCHWeekPuntenTotaal = aValue; }
    void                  SetStartGewicht(double dValue) { mStartGewicht = dValue; }
    void                  SetHuidigGewicht(double dValue) { mHuidigGewicht = dValue; }
    void                  SetStreefGewicht(double aValue) { mStreefGewicht = aValue; }
    void                  SetLengte(int aValue) { mLengte = aValue; }

private:
    std::tstring          mName;
    std::tstring          mUserName;
    GESLACHT              mGeslacht{ GESLACHT::Vrouwelijk };
    Utils::Date           mDateOfBirth;
    WERKTYPE              mWerkType{ WERKTYPE::Zittend };
    STRATEGY_TYPE         mStrategy{ STRATEGY_TYPE::KCal };
    int                   mKCPuntenTotaal{ 0 };
    double                mCHPuntenTotaal{ 0 };
    int                   mKCWeekPuntenTotaal{ 0 };
    double                mCHWeekPuntenTotaal{ 0 };
    double                mStartGewicht{ 0 };
    double                mHuidigGewicht{ 0 };
    double                mStreefGewicht{ 0 };
    int                   mLengte{ 0 };
};


}

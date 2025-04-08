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
    GESLACHT              GetGeslacht() const noexcept { return mGeslacht; }
    Utils::Date           GetDateOfBirth() const noexcept { return mDateOfBirth; }
    WERKTYPE              GetTypeOfWork() const noexcept { return mWerkType; }
    double                GetPuntenTotaal(STRATEGY_TYPE eType) const noexcept;
    int                   GetKCPuntenTotaal() const noexcept { return mKCPuntenTotaal; }
    double                GetCHPuntenTotaal() const noexcept { return mCHPuntenTotaal; }
    int                   GetKCWeekPuntenTotaal() const noexcept { return mKCWeekPuntenTotaal; }
    double                GetCHWeekPuntenTotaal() const noexcept { return mCHWeekPuntenTotaal; }
    double                GetStartGewicht() const noexcept { return mStartGewicht; }
    double                GetHuidigGewicht() const noexcept { return mHuidigGewicht; }
    double                GetStreefGewicht() const noexcept { return mStreefGewicht; }
    int                   GetLengte() const noexcept { return mLengte; }

    void                  SetName(const std::tstring& aName) { mName = aName; }
    void                  SetGeslacht(GESLACHT aGeslacht) noexcept { mGeslacht = aGeslacht; }
    void                  SetDateOfBirth(const Utils::Date& aDate) noexcept { mDateOfBirth = aDate; }
    void                  SetTypeOfWork(WERKTYPE aType) noexcept { mWerkType = aType; }
    void                  SetPuntenTotaal(STRATEGY_TYPE eType, double aValue) noexcept;
    void                  SetKCPuntenTotaal(int aValue) noexcept { mKCPuntenTotaal = aValue; }
    void                  SetCHPuntenTotaal(double value) noexcept { mCHPuntenTotaal = value; }
    void                  SetKCWeekPuntenTotaal(int aValue) noexcept { mKCWeekPuntenTotaal = aValue; }
    void                  SetCHWeekPuntenTotaal(double aValue) noexcept { mCHWeekPuntenTotaal = aValue; }
    void                  SetStartGewicht(double dValue) noexcept { mStartGewicht = dValue; }
    void                  SetHuidigGewicht(double dValue) noexcept { mHuidigGewicht = dValue; }
    void                  SetStreefGewicht(double aValue) noexcept { mStreefGewicht = aValue; }
    void                  SetLengte(int aValue) noexcept { mLengte = aValue; }

private:
    std::tstring          mName;
    std::tstring          mUserName;
    GESLACHT              mGeslacht{ GESLACHT::Vrouwelijk };
    Utils::Date           mDateOfBirth;
    WERKTYPE              mWerkType{ WERKTYPE::Zittend };
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

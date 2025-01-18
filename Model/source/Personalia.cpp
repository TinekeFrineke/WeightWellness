
#include "Personalia.h"

#include <assert.h>


namespace weight
{


Personalia::Personalia(const std::tstring& aUserName)
    : mUserName(aUserName),
    mDateOfBirth(Utils::Date::Today()),
    mKCPuntenTotaal(0),
    mCHPuntenTotaal(0),
    mKCWeekPuntenTotaal(0),
    mCHWeekPuntenTotaal(0),
    mStreefGewicht(0),
    mLengte(0)
{
}


double Personalia::GetPuntenTotaal(STRATEGY_TYPE eType) const
{
    switch (eType)
    {
        case STRATEGY_TYPE::KCal:
            return mKCPuntenTotaal;
        case STRATEGY_TYPE::CarboHydrates:
            return mCHPuntenTotaal;
        default:
            assert(false);
            return 0;
    }
}

double Personalia::GetWeekPuntenTotaal(STRATEGY_TYPE eType) const
{
    switch (eType)
    {
        case STRATEGY_TYPE::KCal:
            return mKCWeekPuntenTotaal;
        case STRATEGY_TYPE::CarboHydrates:
            return mCHWeekPuntenTotaal;
        default:
            assert(false);
            return 0;
    }
}


void Personalia::SetPuntenTotaal(STRATEGY_TYPE eType, double aValue)
{
    switch (eType)
    {
    case STRATEGY_TYPE::KCal:
        mKCPuntenTotaal = static_cast<int>(aValue);
        break;
    case STRATEGY_TYPE::CarboHydrates:
        mCHPuntenTotaal = aValue;
        break;
    default:
        assert(false);
    }
}

void Personalia::SetWeekPuntenTotaal(STRATEGY_TYPE eType, int aValue)
{
    switch (eType)
    {
        case STRATEGY_TYPE::KCal:
            mKCWeekPuntenTotaal = static_cast<int>(aValue);
            break;
        case STRATEGY_TYPE::CarboHydrates:
            mCHWeekPuntenTotaal = aValue;
            break;
        default:
            assert(false);
    }
}


} // namespace weight

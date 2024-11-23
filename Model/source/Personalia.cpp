
#include "Personalia.h"

#include <assert.h>


namespace WW
{


Personalia::Personalia(const std::tstring& aUserName)
    : mUserName(aUserName),
    mDateOfBirth(Utils::Date::Today()),
    mFPPuntenTotaal(0),
    mPPPuntenTotaal(0),
    mKCPuntenTotaal(0),
    mCHPuntenTotaal(0),
    mPPWeekPuntenTotaal(0),
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


} // namespace WW

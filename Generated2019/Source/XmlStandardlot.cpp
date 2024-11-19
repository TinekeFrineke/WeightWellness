//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlStandardlot.h"

#include <assert.h>
#include <tchar.h>

#include "XmlPortie.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100.h"

namespace ww2019
{
XmlStandardlot::XmlStandardlot()
    : mVoedingswaarde(nullptr)
    , mPuntenper100(nullptr)
{
}

XmlStandardlot::~XmlStandardlot()
{
}

XmlPortie & XmlStandardlot::GetPortie()
{
    return mPortie;
}

const XmlPortie & XmlStandardlot::GetPortie() const
{
    return mPortie;
}
const XmlVoedingswaarde * XmlStandardlot::GetVoedingswaarde() const
{
    return mVoedingswaarde.get();
}
const XmlPuntenper100 * XmlStandardlot::GetPuntenper100() const
{
    return mPuntenper100.get();
}


void XmlStandardlot::Add(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde)
{
    assert(mVoedingswaarde == nullptr);
    mVoedingswaarde = std::move(aVoedingswaarde);
}


void XmlStandardlot::Add(std::unique_ptr<XmlPuntenper100> aPuntenper100)
{
    assert(mPuntenper100 == nullptr);
    mPuntenper100 = std::move(aPuntenper100);
}
std::wstring XmlStandardlot::Gethoeveelheid() const
{
    return mhoeveelheid;
}

void XmlStandardlot::Sethoeveelheid(const std::wstring & ahoeveelheid)
{
    mhoeveelheid = ahoeveelheid;
}

}
//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddeldef.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingswaarde.h"
#include "XmlPortie.h"

namespace ww2024
{
XmlVoedingsmiddeldef::XmlVoedingsmiddeldef()
    : mVoedingswaarde(nullptr)    , mfavoriet(favoriet::no)

{
}

XmlVoedingsmiddeldef::~XmlVoedingsmiddeldef()
{
}

XmlVoedingswaarde & XmlVoedingsmiddeldef::GetVoedingswaarde()
{
    return *mVoedingswaarde;
}

const XmlVoedingswaarde & XmlVoedingsmiddeldef::GetVoedingswaarde() const
{
    return *mVoedingswaarde;
}


const std::vector<std::unique_ptr<XmlPortie>> & XmlVoedingsmiddeldef::GetPortieList() const
{
    return mPortieList;
}


void XmlVoedingsmiddeldef::Setvoedingswaarde(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde)
{
    assert(mVoedingswaarde == nullptr);
    mVoedingswaarde = std::move(aVoedingswaarde);
}


void XmlVoedingsmiddeldef::Add(std::unique_ptr<XmlPortie> aPortie)
{
    mPortieList.push_back(std::move(aPortie));
}
std::wstring XmlVoedingsmiddeldef::Getnaam() const
{
    return mnaam;
}

std::wstring XmlVoedingsmiddeldef::Getcategorie() const
{
    return mcategorie;
}

std::wstring XmlVoedingsmiddeldef::Getmerk() const
{
    return mmerk;
}

std::wstring XmlVoedingsmiddeldef::Getunit() const
{
    return munit;
}

XmlVoedingsmiddeldef::favoriet XmlVoedingsmiddeldef::Getfavoriet() const
{
    return mfavoriet;
}

void XmlVoedingsmiddeldef::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlVoedingsmiddeldef::Setcategorie(const std::wstring & acategorie)
{
    mcategorie = acategorie;
}

void XmlVoedingsmiddeldef::Setmerk(const std::wstring & amerk)
{
    mmerk = amerk;
}

void XmlVoedingsmiddeldef::Setunit(const std::wstring & aunit)
{
    munit = aunit;
}

void XmlVoedingsmiddeldef::Setfavoriet(favoriet afavoriet)
{
    mfavoriet = afavoriet;
}

}
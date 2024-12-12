//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddel.h"

#include <assert.h>
#include <tchar.h>

#include "XmlPortie.h"
#include "XmlVoedingswaarde.h"

namespace ww2024
{
XmlVoedingsmiddel::XmlVoedingsmiddel()
    : mPortie(nullptr)
    , mVoedingswaarde(nullptr)    , maantalporties(0)

{
}

XmlVoedingsmiddel::~XmlVoedingsmiddel()
{
}

XmlPortie & XmlVoedingsmiddel::GetPortie()
{
    return *mPortie;
}

const XmlPortie & XmlVoedingsmiddel::GetPortie() const
{
    return *mPortie;
}
XmlVoedingswaarde & XmlVoedingsmiddel::GetVoedingswaarde()
{
    return *mVoedingswaarde;
}

const XmlVoedingswaarde & XmlVoedingsmiddel::GetVoedingswaarde() const
{
    return *mVoedingswaarde;
}


void XmlVoedingsmiddel::Setportie(std::unique_ptr<XmlPortie> aPortie)
{
    assert(mPortie == nullptr);
    mPortie = std::move(aPortie);
}


void XmlVoedingsmiddel::Setvoedingswaarde(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde)
{
    assert(mVoedingswaarde == nullptr);
    mVoedingswaarde = std::move(aVoedingswaarde);
}
std::wstring XmlVoedingsmiddel::Getnaam() const
{
    return mnaam;
}

std::wstring XmlVoedingsmiddel::Getcategorie() const
{
    return mcategorie;
}

std::wstring XmlVoedingsmiddel::Getunit() const
{
    return munit;
}

double XmlVoedingsmiddel::Getaantalporties() const
{
    return maantalporties;
}

void XmlVoedingsmiddel::Setnaam(const std::wstring & anaam)
{
    mnaam = anaam;
}

void XmlVoedingsmiddel::Setcategorie(const std::wstring & acategorie)
{
    mcategorie = acategorie;
}

void XmlVoedingsmiddel::Setunit(const std::wstring & aunit)
{
    munit = aunit;
}

void XmlVoedingsmiddel::Setaantalporties(double aaantalporties)
{
    maantalporties = aaantalporties;
}

}
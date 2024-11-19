//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#include "XmlVoedingsmiddeldef.h"

#include <assert.h>
#include <tchar.h>

#include "XmlVoedingsmiddelheader.h"
#include "XmlPortie.h"
#include "XmlVoedingswaarde.h"
#include "XmlPuntenper100.h"

namespace ww2019
{
XmlVoedingsmiddeldef::XmlVoedingsmiddeldef()
    : mVoedingswaarde(nullptr)
    , mPuntenper100(nullptr)    , mfavoriet(favoriet::no)

{
}

XmlVoedingsmiddeldef::~XmlVoedingsmiddeldef()
{
}

XmlVoedingsmiddelheader & XmlVoedingsmiddeldef::GetVoedingsmiddelheader()
{
    return mVoedingsmiddelheader;
}

const XmlVoedingsmiddelheader & XmlVoedingsmiddeldef::GetVoedingsmiddelheader() const
{
    return mVoedingsmiddelheader;
}


const std::vector<std::unique_ptr<XmlPortie>> & XmlVoedingsmiddeldef::GetPortieList() const
{
    return mPortieList;
}
const XmlVoedingswaarde * XmlVoedingsmiddeldef::GetVoedingswaarde() const
{
    return mVoedingswaarde.get();
}
const XmlPuntenper100 * XmlVoedingsmiddeldef::GetPuntenper100() const
{
    return mPuntenper100.get();
}


void XmlVoedingsmiddeldef::Add(std::unique_ptr<XmlPortie> aPortie)
{
    mPortieList.push_back(std::move(aPortie));
}


void XmlVoedingsmiddeldef::Add(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde)
{
    assert(mVoedingswaarde == nullptr);
    mVoedingswaarde = std::move(aVoedingswaarde);
}


void XmlVoedingsmiddeldef::Add(std::unique_ptr<XmlPuntenper100> aPuntenper100)
{
    assert(mPuntenper100 == nullptr);
    mPuntenper100 = std::move(aPuntenper100);
}
XmlVoedingsmiddeldef::favoriet XmlVoedingsmiddeldef::Getfavoriet() const
{
    return mfavoriet;
}

void XmlVoedingsmiddeldef::Setfavoriet(favoriet afavoriet)
{
    mfavoriet = afavoriet;
}

}
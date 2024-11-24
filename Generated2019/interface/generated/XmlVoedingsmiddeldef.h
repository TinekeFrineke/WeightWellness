//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

// Includes for children
#include "XmlVoedingsmiddelheader.h"

namespace ww2019
{


class XmlPortie;
class XmlVoedingswaarde;
class XmlPuntenper100;


class XmlVoedingsmiddeldef : public XmlClass
{
public:
    enum class favoriet
    {
        yes,
        no
    };

    XmlVoedingsmiddeldef();
    ~XmlVoedingsmiddeldef() override;

    const XmlVoedingsmiddelheader & GetVoedingsmiddelheader() const;
    XmlVoedingsmiddelheader & GetVoedingsmiddelheader();
    const std::vector<std::unique_ptr<XmlPortie>> & GetPortieList() const;
    const XmlVoedingswaarde * GetVoedingswaarde() const;
    const XmlPuntenper100 * GetPuntenper100() const;
    void Add(std::unique_ptr<XmlPortie> aPortie);
    void Add(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde);
    void Add(std::unique_ptr<XmlPuntenper100> aPuntenper100);
    favoriet Getfavoriet() const;
    void Setfavoriet(favoriet afavoriet);

private:
    XmlVoedingsmiddeldef(const XmlVoedingsmiddeldef& anOriginal) = delete;
    XmlVoedingsmiddeldef& operator=(const XmlVoedingsmiddeldef& anOriginal) = delete;

    XmlVoedingsmiddelheader mVoedingsmiddelheader;
    std::vector<std::unique_ptr<XmlPortie>> mPortieList;
    std::unique_ptr<XmlVoedingswaarde> mVoedingswaarde;
    std::unique_ptr<XmlPuntenper100> mPuntenper100;
    favoriet mfavoriet;
};


}

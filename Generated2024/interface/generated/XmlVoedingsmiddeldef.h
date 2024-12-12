//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

namespace ww2024
{

// Forward declarations
class XmlVoedingswaarde;
class XmlPortie;


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

    const XmlVoedingswaarde & GetVoedingswaarde() const;
    XmlVoedingswaarde & GetVoedingswaarde();
    const std::vector<std::unique_ptr<XmlPortie>> & GetPortieList() const;
    void Setvoedingswaarde(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde);
    void Add(std::unique_ptr<XmlPortie> aPortie);
    std::wstring Getnaam() const;
    std::wstring Getcategorie() const;
    std::wstring Getmerk() const;
    std::wstring Getunit() const;
    favoriet Getfavoriet() const;
    void Setnaam(const std::wstring & anaam);
    void Setcategorie(const std::wstring & acategorie);
    void Setmerk(const std::wstring & amerk);
    void Setunit(const std::wstring & aunit);
    void Setfavoriet(favoriet afavoriet);

private:
    XmlVoedingsmiddeldef(const XmlVoedingsmiddeldef& anOriginal) = delete;
    XmlVoedingsmiddeldef& operator=(const XmlVoedingsmiddeldef& anOriginal) = delete;

    std::unique_ptr<XmlVoedingswaarde> mVoedingswaarde;
    std::vector<std::unique_ptr<XmlPortie>> mPortieList;
    std::wstring mnaam;
    std::wstring mcategorie;
    std::wstring mmerk;
    std::wstring munit;
    favoriet mfavoriet;
};


}

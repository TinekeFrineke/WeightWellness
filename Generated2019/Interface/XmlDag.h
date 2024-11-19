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

namespace ww2019
{


class XmlVoedingsmiddel;
class XmlRecept;
class XmlGerecht;
class XmlHandmatigitem;
class XmlBonuscell;


class XmlDag : public XmlClass
{
public:
    XmlDag();
    ~XmlDag() override;

    const std::vector<std::unique_ptr<XmlVoedingsmiddel>> & GetVoedingsmiddelList() const;
    const std::vector<std::unique_ptr<XmlRecept>> & GetReceptList() const;
    const std::vector<std::unique_ptr<XmlGerecht>> & GetGerechtList() const;
    const std::vector<std::unique_ptr<XmlHandmatigitem>> & GetHandmatigitemList() const;
    const std::vector<std::unique_ptr<XmlBonuscell>> & GetBonuscellList() const;
    void Add(std::unique_ptr<XmlVoedingsmiddel> aVoedingsmiddel);
    void Add(std::unique_ptr<XmlRecept> aRecept);
    void Add(std::unique_ptr<XmlGerecht> aGerecht);
    void Add(std::unique_ptr<XmlHandmatigitem> aHandmatigitem);
    void Add(std::unique_ptr<XmlBonuscell> aBonuscell);
    std::wstring Getbonuspunten() const;
    std::wstring Getdatum() const;
    std::wstring Getgewicht() const;
    void Setbonuspunten(const std::wstring & abonuspunten);
    void Setdatum(const std::wstring & adatum);
    void Setgewicht(const std::wstring & agewicht);

private:
    XmlDag(const XmlDag& anOriginal) = delete;
    XmlDag& operator=(const XmlDag& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlVoedingsmiddel>> mVoedingsmiddelList;
    std::vector<std::unique_ptr<XmlRecept>> mReceptList;
    std::vector<std::unique_ptr<XmlGerecht>> mGerechtList;
    std::vector<std::unique_ptr<XmlHandmatigitem>> mHandmatigitemList;
    std::vector<std::unique_ptr<XmlBonuscell>> mBonuscellList;
    std::wstring mbonuspunten;
    std::wstring mdatum;
    std::wstring mgewicht;
};


}

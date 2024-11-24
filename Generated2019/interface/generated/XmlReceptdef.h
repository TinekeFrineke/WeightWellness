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


class XmlReceptdef : public XmlClass
{
public:
    XmlReceptdef();
    ~XmlReceptdef() override;

    const std::vector<std::unique_ptr<XmlVoedingsmiddel>> & GetVoedingsmiddelList() const;
    const std::vector<std::unique_ptr<XmlRecept>> & GetReceptList() const;
    const std::vector<std::unique_ptr<XmlGerecht>> & GetGerechtList() const;
    const std::vector<std::unique_ptr<XmlHandmatigitem>> & GetHandmatigitemList() const;
    void Add(std::unique_ptr<XmlVoedingsmiddel> aVoedingsmiddel);
    void Add(std::unique_ptr<XmlRecept> aRecept);
    void Add(std::unique_ptr<XmlGerecht> aGerecht);
    void Add(std::unique_ptr<XmlHandmatigitem> aHandmatigitem);
    std::wstring Getnaam() const;
    std::wstring Getporties() const;
    void Setnaam(const std::wstring & anaam);
    void Setporties(const std::wstring & aporties);

private:
    XmlReceptdef(const XmlReceptdef& anOriginal) = delete;
    XmlReceptdef& operator=(const XmlReceptdef& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlVoedingsmiddel>> mVoedingsmiddelList;
    std::vector<std::unique_ptr<XmlRecept>> mReceptList;
    std::vector<std::unique_ptr<XmlGerecht>> mGerechtList;
    std::vector<std::unique_ptr<XmlHandmatigitem>> mHandmatigitemList;
    std::wstring mnaam;
    std::wstring mporties;
};


}

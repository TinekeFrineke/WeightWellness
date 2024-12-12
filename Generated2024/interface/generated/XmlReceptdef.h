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
class XmlVoedingsmiddel;
class XmlRecept;
class XmlHandmatigitem;


class XmlReceptdef : public XmlClass
{
public:
    XmlReceptdef();
    ~XmlReceptdef() override;

    const std::vector<std::unique_ptr<XmlVoedingsmiddel>> & GetVoedingsmiddelList() const;
    const std::vector<std::unique_ptr<XmlRecept>> & GetReceptList() const;
    const std::vector<std::unique_ptr<XmlHandmatigitem>> & GetHandmatigitemList() const;
    void Add(std::unique_ptr<XmlVoedingsmiddel> aVoedingsmiddel);
    void Add(std::unique_ptr<XmlRecept> aRecept);
    void Add(std::unique_ptr<XmlHandmatigitem> aHandmatigitem);
    std::wstring Getnaam() const;
    int Getporties() const;
    void Setnaam(const std::wstring & anaam);
    void Setporties(int aporties);

private:
    XmlReceptdef(const XmlReceptdef& anOriginal) = delete;
    XmlReceptdef& operator=(const XmlReceptdef& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlVoedingsmiddel>> mVoedingsmiddelList;
    std::vector<std::unique_ptr<XmlRecept>> mReceptList;
    std::vector<std::unique_ptr<XmlHandmatigitem>> mHandmatigitemList;
    std::wstring mnaam;
    int mporties;
};


}

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
class XmlBonuscell;


class XmlBonuslist : public XmlClass
{
public:
    XmlBonuslist();
    ~XmlBonuslist() override;

    const std::vector<std::unique_ptr<XmlBonuscell>> & GetBonuscellList() const;
    void Add(std::unique_ptr<XmlBonuscell> aBonuscell);

private:
    XmlBonuslist(const XmlBonuslist& anOriginal) = delete;
    XmlBonuslist& operator=(const XmlBonuslist& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlBonuscell>> mBonuscellList;
};


}

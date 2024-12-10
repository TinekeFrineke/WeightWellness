//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

namespace ww2024
{



class XmlUnit : public XmlClass
{
public:
    XmlUnit();
    ~XmlUnit() override;

    std::wstring Getnaam() const;
    void Setnaam(const std::wstring & anaam);

private:
    XmlUnit(const XmlUnit& anOriginal) = delete;
    XmlUnit& operator=(const XmlUnit& anOriginal) = delete;

    std::wstring mnaam;
};


}

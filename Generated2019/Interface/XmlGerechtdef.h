//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <vector>

#include "XmlClass.h"

// Includes for children
namespace ww2019
{



class XmlGerechtdef : public XmlClass
{
public:
    XmlGerechtdef();
    ~XmlGerechtdef() override;

    std::wstring Getnaam() const;
    std::wstring Getpunten() const;
    void Setnaam(const std::wstring & anaam);
    void Setpunten(const std::wstring & apunten);

private:
    XmlGerechtdef(const XmlGerechtdef& anOriginal) = delete;
    XmlGerechtdef& operator=(const XmlGerechtdef& anOriginal) = delete;

    std::wstring mnaam;
    std::wstring mpunten;
};


}

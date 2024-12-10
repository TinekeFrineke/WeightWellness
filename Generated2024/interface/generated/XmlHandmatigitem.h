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



class XmlHandmatigitem : public XmlClass
{
public:
    XmlHandmatigitem();
    ~XmlHandmatigitem() override;

    std::wstring Getnaam() const;
    double Getpunten() const;
    double Gethoeveelheid() const;
    void Setnaam(const std::wstring & anaam);
    void Setpunten(double apunten);
    void Sethoeveelheid(double ahoeveelheid);

private:
    XmlHandmatigitem(const XmlHandmatigitem& anOriginal) = delete;
    XmlHandmatigitem& operator=(const XmlHandmatigitem& anOriginal) = delete;

    std::wstring mnaam;
    double mpunten;
    double mhoeveelheid;
};


}

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



class XmlPuntenper100 : public XmlClass
{
public:
    XmlPuntenper100();
    ~XmlPuntenper100() override;

    std::wstring Getpunten() const;
    void Setpunten(const std::wstring & apunten);

private:
    XmlPuntenper100(const XmlPuntenper100& anOriginal) = delete;
    XmlPuntenper100& operator=(const XmlPuntenper100& anOriginal) = delete;

    std::wstring mpunten;
};


}

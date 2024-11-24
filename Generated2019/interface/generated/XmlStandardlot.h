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
#include "XmlPortie.h"

namespace ww2019
{


class XmlVoedingswaarde;
class XmlPuntenper100;


class XmlStandardlot : public XmlClass
{
public:
    XmlStandardlot();
    ~XmlStandardlot() override;

    const XmlPortie & GetPortie() const;
    XmlPortie & GetPortie();
    const XmlVoedingswaarde * GetVoedingswaarde() const;
    const XmlPuntenper100 * GetPuntenper100() const;
    void Add(std::unique_ptr<XmlVoedingswaarde> aVoedingswaarde);
    void Add(std::unique_ptr<XmlPuntenper100> aPuntenper100);
    std::wstring Gethoeveelheid() const;
    void Sethoeveelheid(const std::wstring & ahoeveelheid);

private:
    XmlStandardlot(const XmlStandardlot& anOriginal) = delete;
    XmlStandardlot& operator=(const XmlStandardlot& anOriginal) = delete;

    XmlPortie mPortie;
    std::unique_ptr<XmlVoedingswaarde> mVoedingswaarde;
    std::unique_ptr<XmlPuntenper100> mPuntenper100;
    std::wstring mhoeveelheid;
};


}

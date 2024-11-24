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



class XmlPortieomschrijving : public XmlClass
{
public:
    XmlPortieomschrijving();
    ~XmlPortieomschrijving() override;

    std::wstring Getomschrijving() const;
    void Setomschrijving(const std::wstring & aomschrijving);

private:
    XmlPortieomschrijving(const XmlPortieomschrijving& anOriginal) = delete;
    XmlPortieomschrijving& operator=(const XmlPortieomschrijving& anOriginal) = delete;

    std::wstring momschrijving;
};


}

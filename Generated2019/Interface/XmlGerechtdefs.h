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


class XmlGerechtdef;


class XmlGerechtdefs : public XmlClass
{
public:
    XmlGerechtdefs();
    ~XmlGerechtdefs() override;

    const std::vector<std::unique_ptr<XmlGerechtdef>> & GetGerechtdefList() const;
    void Add(std::unique_ptr<XmlGerechtdef> aGerechtdef);

private:
    XmlGerechtdefs(const XmlGerechtdefs& anOriginal) = delete;
    XmlGerechtdefs& operator=(const XmlGerechtdefs& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlGerechtdef>> mGerechtdefList;
};


}

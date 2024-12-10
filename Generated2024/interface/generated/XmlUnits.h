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
class XmlUnit;


class XmlUnits : public XmlClass
{
public:
    XmlUnits();
    ~XmlUnits() override;

    const std::vector<std::unique_ptr<XmlUnit>> & GetUnitList() const;
    void Add(std::unique_ptr<XmlUnit> aUnit);

private:
    XmlUnits(const XmlUnits& anOriginal) = delete;
    XmlUnits& operator=(const XmlUnits& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlUnit>> mUnitList;
};


}

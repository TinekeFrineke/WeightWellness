#pragma once

#include "Utilities/StrUtils.h"

#include "xmlbase/XmlBase.h"

namespace ww2024
{
class XmlBonuscell;
class XmlDag;
class XmlHandmatigitem;
class XmlLot;
class XmlModel;
class XmlPortie;
class XmlRecept;
class XmlVoedingsmiddel;
}

namespace weight
{

class Day;
class Gerecht;
class ManualItem;
class Model;
class Portie;
class Recept;
class Voedingsmiddel;

}

namespace ww2024
{

class XmlReader
{
public:
    XmlReader(weight::Model& aModel);

    weight::Result                      Read(const std::tstring& aDirectory);

    weight::Result                      ReadPersonalia(const std::tstring& aDirectory);
    weight::Result                      ReadUnits(const std::tstring& aDirectory);
    weight::Result                      ReadVoedingsmiddelDefinities(const std::tstring& aDirectory);
    weight::Result                      ReadRecepten(const std::tstring& aDirectory);
    weight::Result                      ReadGerechten(const std::tstring& aDirectory);
    weight::Result                      ReadWeeks(const std::tstring& aDirectory);
    weight::Result                      ReadBonusCells(const std::tstring& aDirectory);

private:
    XmlReader& operator=(const XmlReader&) = delete;
    XmlReader(const XmlReader&) = delete;

    weight::Result                      ReadWeek(const std::tstring& aDirectory);

    weight::Portie Create(const ww2024::XmlPortie& aPortie);
    std::unique_ptr<weight::Voedingsmiddel> Create(const ww2024::XmlVoedingsmiddel& aVoedingsmiddel);
    std::unique_ptr<weight::Recept> Create(const ww2024::XmlRecept& aRecept);
    std::unique_ptr<weight::ManualItem> Create(const ww2024::XmlHandmatigitem& aGerecht);
    std::unique_ptr<weight::Day> Create(const ww2024::XmlDag& aDag);

    weight::Model& mModel;
};


} // namespace ww2024

#pragma once

#include "Utilities/StrUtils.h"

#include "model/Day.h"
#include "model/Portie.h"
#include "model/Model.h"

#include "xmlbase/XmlBase.h"

namespace ww2019
{
class XmlBonuscell;
class XmlDag;
class XmlGerecht;
class XmlHandmatigitem;
class XmlLot;
class XmlModel;
class XmlPortie;
class XmlRecept;
class XmlVoedingsmiddel;
}

namespace weight
{

class Gerecht;
class ManualItem;
class Recept;
class Voedingsmiddel;

}

namespace ww2019
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

    weight::Portie Create(const ww2019::XmlPortie& aPortie);
    std::unique_ptr<weight::Voedingsmiddel> Create(const ww2019::XmlVoedingsmiddel& aVoedingsmiddel);
    std::unique_ptr<weight::Recept> Create(const ww2019::XmlRecept& aRecept);
    std::unique_ptr<weight::Gerecht> Create(const ww2019::XmlGerecht& aGerecht);
    std::unique_ptr<weight::ManualItem> Create(const ww2019::XmlHandmatigitem& aGerecht);
    std::unique_ptr<weight::Day> Create(const ww2019::XmlDag& aDag);
    weight::Bonus Create(const ww2019::XmlBonuscell& aCell);
    weight::Model& mModel;
};


} // namespace ww2019

#pragma once

#include "Utilities/StrUtils.h"

#include "model/Day.h"
#include "model/Portie.h"
#include "model/WWModel.h"

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

namespace WW
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
    XmlReader(WW::Model& aModel);

    WW::Result                      Read(const std::tstring& aDirectory);

    WW::Result                      ReadPersonalia(const std::tstring& aDirectory);
    WW::Result                      ReadUnits(const std::tstring& aDirectory);
    WW::Result                      ReadVoedingsmiddelDefinities(const std::tstring& aDirectory);
    WW::Result                      ReadRecepten(const std::tstring& aDirectory);
    WW::Result                      ReadGerechten(const std::tstring& aDirectory);
    WW::Result                      ReadWeeks(const std::tstring& aDirectory);
    WW::Result                      ReadBonusCells(const std::tstring& aDirectory);

private:
    XmlReader& operator=(const XmlReader&) = delete;
    XmlReader(const XmlReader&) = delete;

    WW::Result                      ReadWeek(const std::tstring& aDirectory);

    WW::Portie Create(const ww2019::XmlPortie& aPortie);
    std::unique_ptr<WW::Voedingsmiddel> Create(const ww2019::XmlVoedingsmiddel& aVoedingsmiddel);
    std::unique_ptr<WW::Recept> Create(const ww2019::XmlRecept& aRecept);
    std::unique_ptr<WW::Gerecht> Create(const ww2019::XmlGerecht& aGerecht);
    std::unique_ptr<WW::ManualItem> Create(const ww2019::XmlHandmatigitem& aGerecht);
    std::unique_ptr<WW::Day> Create(const ww2019::XmlDag& aDag);
    WW::Bonus Create(const ww2019::XmlBonuscell& aCell);
    WW::Model& mModel;
};


} // namespace ww2019

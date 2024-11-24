#pragma once

#include "Utilities/StrUtils.h"

#include "xmlbase/XmlBase.h"

namespace WW
{
class Day;
class FixedLot;
class Gerecht;
class ManualItem;
class Model;
class Portie;
class Recept;
class CalculatedLot;
class Voedingsmiddel;
class Week;
}

namespace ww2019
{
class XmlDag;
class XmlFixedlot;
class XmlFreelot;
class XmlGerecht;
class XmlHandmatigitem;
class XmlModel;
class XmlPortie;
class XmlRecept;
class XmlStandardlot;
class XmlSterrelot;
class XmlVoedingsmiddel;


class XmlWriter
{
public:
    // TF_TODO Writer for bonus points
    XmlWriter(WW::Model & aModel) : mModel(aModel) {}

    WW::Result Write(const std::tstring & aDirectory);

    WW::Result Create(const WW::Day & aDag, XmlDag & aDay);
    WW::Result Create(const WW::Voedingsmiddel & aMiddel, XmlVoedingsmiddel & aDay);
    WW::Result Create(const WW::Recept & aMiddel, XmlRecept & aRecept);
    WW::Result Create(const WW::Gerecht & aMiddel, XmlGerecht & aGerecht);
    WW::Result Create(const WW::ManualItem & anItem, XmlHandmatigitem & anXmlItem);
    WW::Result Create(const WW::Portie & aPortie, XmlPortie & anXmlPortie);
    WW::Result Create(const WW::CalculatedLot & aLot, XmlStandardlot & anXmlLot);
    WW::Result Create(const WW::FixedLot & aLot, XmlStandardlot & anXmlLot);

private:
    XmlWriter & operator=(const XmlWriter &) = delete;

    WW::Result WritePersonalia(const std::tstring & aFilename);
    WW::Result WriteUnits(const std::tstring & aFilename);
    WW::Result WriteVoedingsmiddelDefinities(const std::tstring & aFilename);
    WW::Result WriteRecepten(const std::tstring & aFilename);
    WW::Result WriteGerechten(const std::tstring & aFilename);
    WW::Result WriteWeeks(const std::tstring & aDirectory);

    WW::Result Write(WW::Week & aWeek, const std::tstring & aFilename);

    WW::Model& mModel;
};


} // namespace ww2019

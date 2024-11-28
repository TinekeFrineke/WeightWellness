#pragma once

#include "Utilities/StrUtils.h"

#include "xmlbase/XmlBase.h"

namespace weight
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
    XmlWriter(weight::Model & aModel) : mModel(aModel) {}

    weight::Result Write(const std::tstring & aDirectory);

    weight::Result Create(const weight::Day & aDag, XmlDag & aDay);
    weight::Result Create(const weight::Voedingsmiddel & aMiddel, XmlVoedingsmiddel & aDay);
    weight::Result Create(const weight::Recept & aMiddel, XmlRecept & aRecept);
    weight::Result Create(const weight::Gerecht & aMiddel, XmlGerecht & aGerecht);
    weight::Result Create(const weight::ManualItem & anItem, XmlHandmatigitem & anXmlItem);
    weight::Result Create(const weight::Portie & aPortie, XmlPortie & anXmlPortie);
    weight::Result Create(const weight::CalculatedLot & aLot, XmlStandardlot & anXmlLot);
    weight::Result Create(const weight::FixedLot & aLot, XmlStandardlot & anXmlLot);

private:
    XmlWriter & operator=(const XmlWriter &) = delete;

    weight::Result WritePersonalia(const std::tstring & aFilename);
    weight::Result WriteUnits(const std::tstring & aFilename);
    weight::Result WriteVoedingsmiddelDefinities(const std::tstring & aFilename);
    weight::Result WriteRecepten(const std::tstring & aFilename);
    weight::Result WriteGerechten(const std::tstring & aFilename);
    weight::Result WriteWeeks(const std::tstring & aDirectory);

    weight::Result Write(weight::Week & aWeek, const std::tstring & aFilename);

    weight::Model& mModel;
};


} // namespace ww2019

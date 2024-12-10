#pragma once

#include "Utilities/StrUtils.h"

#include "xmlbase/XmlBase.h"

namespace weight
{
class Day;
class ManualItem;
class Model;
class Portie;
class PortionedLot;
class Recept;
class CalculatedLot;
class Voedingsmiddel;
class Week;

struct FoodParameters;
}

namespace ww2024
{
class XmlDag;
class XmlHandmatigitem;
class XmlModel;
class XmlPortie;
class XmlRecept;
class XmlVoedingsmiddel;
class XmlVoedingswaarde;


class XmlWriter
{
public:
    // TF_TODO Writer for bonus points
    XmlWriter(weight::Model & aModel) : mModel(aModel) {}

    weight::Result Write(const std::tstring & aDirectory);

    weight::Result Create(const weight::Day & aDag, XmlDag & aDay);
    weight::Result Create(const weight::Voedingsmiddel & aMiddel, XmlVoedingsmiddel & aDay);
    weight::Result Create(const weight::Recept & aMiddel, XmlRecept & aRecept);
    weight::Result Create(const weight::ManualItem & anItem, XmlHandmatigitem & anXmlItem);
    weight::Result Create(const weight::Portie & aPortie, XmlPortie & anXmlPortie);
    //std::unique_ptr<XmlVoedingswaarde> CreateVoedingswaarde(const weight::FoodParameters& parameters);

private:
    XmlWriter & operator=(const XmlWriter &) = delete;

    weight::Result WritePersonalia(const std::tstring & aFilename);
    weight::Result WriteUnits(const std::tstring & aFilename);
    weight::Result WriteVoedingsmiddelDefinities(const std::tstring & aFilename);
    weight::Result WriteRecepten(const std::tstring & aFilename);
    weight::Result WriteWeeks(const std::tstring & aDirectory);

    weight::Result Write(weight::Week & aWeek, const std::tstring & aFilename);

    weight::Model& mModel;
};


} // namespace ww2024

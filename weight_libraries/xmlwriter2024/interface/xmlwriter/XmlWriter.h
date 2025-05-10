#pragma once

#include <string>

#include "xmlbase/XmlBase.h"

namespace weight
{
class IDay;
class IModel;
class IWeek;
class ManualItem;
class Portie;
class PortionedLot;
class Recept;
class CalculatedLot;
class Voedingsmiddel;

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
    XmlWriter(weight::IModel & aModel) : mModel(aModel) {}

    weight::Result Write(const std::string & aDirectory);

    weight::Result Create(const weight::IDay & aDag, XmlDag & aDay);
    weight::Result Create(const weight::Voedingsmiddel & aMiddel, XmlVoedingsmiddel & aDay);
    weight::Result Create(const weight::Recept & aMiddel, XmlRecept & aRecept);
    weight::Result Create(const weight::ManualItem & anItem, XmlHandmatigitem & anXmlItem);
    weight::Result Create(const weight::Portie & aPortie, XmlPortie & anXmlPortie);
    //std::unique_ptr<XmlVoedingswaarde> CreateVoedingswaarde(const weight::FoodParameters& parameters);

private:
    XmlWriter & operator=(const XmlWriter &) = delete;

    weight::Result WritePersonalia(const std::string & aFilename);
    weight::Result WriteUnits(const std::string & aFilename);
    weight::Result WriteVoedingsmiddelDefinities(const std::string & aFilename);
    weight::Result WriteRecepten(const std::string & aFilename);
    weight::Result WriteWeeks(const std::string & aDirectory);

    weight::Result Write(weight::IWeek & aWeek, const std::string & aFilename);

    weight::IModel& mModel;
};


} // namespace ww2024

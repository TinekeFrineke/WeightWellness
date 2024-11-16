#pragma once

#include "XmlDefinitions.h"
#include "XmlBase.h"

#include "Utilities/StrUtils.h"

namespace WW_GENERATED_NAMESPACE
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
}

namespace WW
{

class Day;
class FixedLot;
class FreeLot;
class Gerecht;
class ManualItem;
class Model;
class Portie;
class Recept;
class CalculatedLot;
class Voedingsmiddel;
class Week;

}

namespace WW_1_0
{


class XmlWriter : public XmlBase
{
public:
  // TF_TODO Writer for bonus points
                              XmlWriter(WW::Model & aModel) : mModel(aModel) {}

  Result                     Write(const std::tstring & aDirectory);

  Result                     Create(const WW::Day & aDag, WW_GENERATED_NAMESPACE::XmlDag & aDay);
  Result                     Create(const WW::Voedingsmiddel & aMiddel, WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & aDay);
  Result                     Create(const WW::Recept & aMiddel, WW_GENERATED_NAMESPACE::XmlRecept & aRecept);
  Result                     Create(const WW::Gerecht & aMiddel, WW_GENERATED_NAMESPACE::XmlGerecht & aGerecht);
  Result                     Create(const WW::ManualItem & anItem, WW_GENERATED_NAMESPACE::XmlHandmatigitem & anXmlItem);
  Result                     Create(const WW::Portie & aPortie, WW_GENERATED_NAMESPACE::XmlPortie & anXmlPortie);
  Result                     Create(const WW::CalculatedLot & aLot, WW_GENERATED_NAMESPACE::XmlStandardlot & anXmlLot);
  Result                     Create(const WW::FreeLot & aLot, WW_GENERATED_NAMESPACE::XmlFreelot & anXmlLot);
  Result                     Create(const WW::FixedLot & aLot, WW_GENERATED_NAMESPACE::XmlStandardlot & anXmlLot);

private:
  XmlWriter &                 operator=(const XmlWriter &);

  Result                     WritePersonalia(const std::tstring & aFilename);
  Result                     WriteUnits(const std::tstring & aFilename);
  Result                     WriteVoedingsmiddelDefinities(const std::tstring & aFilename);
  Result                     WriteRecepten(const std::tstring & aFilename);
  Result                     WriteGerechten(const std::tstring & aFilename);
  Result                     WriteWeeks(const std::tstring & aDirectory);

  Result                     Write(WW::Week & aWeek, const std::tstring & aFilename);

  WW::Model &                 mModel;
};


} // namespace WW

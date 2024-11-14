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

  eRESULT                     Write(const std::tstring & aDirectory);

  eRESULT                     Create(const WW::Day & aDag, WW_GENERATED_NAMESPACE::XmlDag & aDay);
  eRESULT                     Create(const WW::Voedingsmiddel & aMiddel, WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & aDay);
  eRESULT                     Create(const WW::Recept & aMiddel, WW_GENERATED_NAMESPACE::XmlRecept & aRecept);
  eRESULT                     Create(const WW::Gerecht & aMiddel, WW_GENERATED_NAMESPACE::XmlGerecht & aGerecht);
  eRESULT                     Create(const WW::ManualItem & anItem, WW_GENERATED_NAMESPACE::XmlHandmatigitem & anXmlItem);
  eRESULT                     Create(const WW::Portie & aPortie, WW_GENERATED_NAMESPACE::XmlPortie & anXmlPortie);
  eRESULT                     Create(const WW::CalculatedLot & aLot, WW_GENERATED_NAMESPACE::XmlStandardlot & anXmlLot);
  eRESULT                     Create(const WW::FreeLot & aLot, WW_GENERATED_NAMESPACE::XmlFreelot & anXmlLot);
  eRESULT                     Create(const WW::FixedLot & aLot, WW_GENERATED_NAMESPACE::XmlStandardlot & anXmlLot);

private:
  XmlWriter &                 operator=(const XmlWriter &);

  eRESULT                     WritePersonalia(const std::tstring & aFilename);
  eRESULT                     WriteUnits(const std::tstring & aFilename);
  eRESULT                     WriteVoedingsmiddelDefinities(const std::tstring & aFilename);
  eRESULT                     WriteRecepten(const std::tstring & aFilename);
  eRESULT                     WriteGerechten(const std::tstring & aFilename);
  eRESULT                     WriteWeeks(const std::tstring & aDirectory);

  eRESULT                     Write(WW::Week & aWeek, const std::tstring & aFilename);

  WW::Model &                 mModel;
};


} // namespace WW

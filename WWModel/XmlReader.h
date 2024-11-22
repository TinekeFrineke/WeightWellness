#pragma once

#include "XmlDefinitions.h"
#include "XmlBase.h"

#include "Utilities/StrUtils.h"

#include "Day.h"
#include "Portie.h"
#include "WWModel.h"

namespace WW_GENERATED_NAMESPACE
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

namespace WW_NAMESPACE
{

class XmlReader : public XmlBase
{
public:
                              XmlReader(WW::Model & aModel);

  Result                      Read(const std::tstring & aDirectory);

  Result                      ReadPersonalia(const std::tstring & aDirectory);
  Result                      ReadUnits(const std::tstring & aDirectory);
  Result                      ReadVoedingsmiddelDefinities(const std::tstring & aDirectory);
  Result                      ReadRecepten(const std::tstring & aDirectory);
  Result                      ReadGerechten(const std::tstring & aDirectory);
  Result                      ReadWeeks(const std::tstring & aDirectory);
  Result                      ReadBonusCells(const std::tstring & aDirectory);

private:
  XmlReader &                 operator=(const XmlReader &);
                              XmlReader(const XmlReader &);

  Result                      ReadWeek(const std::tstring & aDirectory);

  WW::Portie                  Create(const WW_GENERATED_NAMESPACE::XmlPortie & aPortie);
  WW::Voedingsmiddel *        Create(const WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & aVoedingsmiddel);
  WW::Recept *                Create(const WW_GENERATED_NAMESPACE::XmlRecept & aRecept);
  WW::Gerecht *               Create(const WW_GENERATED_NAMESPACE::XmlGerecht & aGerecht);
  WW::ManualItem *            Create(const WW_GENERATED_NAMESPACE::XmlHandmatigitem & aGerecht);
  WW::Day *                   Create(const WW_GENERATED_NAMESPACE::XmlDag & aDag);
  WW::Bonus                   Create(const WW_GENERATED_NAMESPACE::XmlBonuscell & aCell);
  WW::Model &                 mModel;
};


} // namespace WW

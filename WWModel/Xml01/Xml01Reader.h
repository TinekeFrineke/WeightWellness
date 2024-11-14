#ifndef WW_WWMODEL_XML01MODELREADER_H__
#define WW_WWMODEL_XML01MODELREADER_H__

#include "Xml01Definitions.h"
#include "../XmlBase.h"

#include "Utilities/StrUtils.h"

#include "../Day.h"
#include "../Portie.h"
#include "../WWModel.h"

namespace WW_GENERATED_NAMESPACE
{
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

  eRESULT                     Read(const std::tstring & aDirectory);

  eRESULT                     ReadPersonalia(const std::tstring & aDirectory);
  eRESULT                     ReadUnits(const std::tstring & aDirectory);
  eRESULT                     ReadVoedingsmiddelDefinities(const std::tstring & aDirectory);
  eRESULT                     ReadRecepten(const std::tstring & aDirectory);
  eRESULT                     ReadGerechten(const std::tstring & aDirectory);
  eRESULT                     ReadWeeks(const std::tstring & aDirectory);

private:
  XmlReader &                 operator=(const XmlReader &);
                              XmlReader(const XmlReader &);

  eRESULT                     ReadWeek(const std::tstring & aDirectory);

  WW::Portie                  Create(const WW_GENERATED_NAMESPACE::XmlPortie & aPortie);
  WW::Voedingsmiddel *        Create(const WW_GENERATED_NAMESPACE::XmlVoedingsmiddel & aVoedingsmiddel);
  WW::Recept *                Create(const WW_GENERATED_NAMESPACE::XmlRecept & aRecept);
  WW::Gerecht *               Create(const WW_GENERATED_NAMESPACE::XmlGerecht & aGerecht);
  WW::ManualItem *            Create(const WW_GENERATED_NAMESPACE::XmlHandmatigitem & aGerecht);
  WW::Day *                   Create(const WW_GENERATED_NAMESPACE::XmlDag & aDag);
  WW::Model &                 mModel;
};


} // namespace WW


#endif // WW_WWMODEL_XML01MODELREADER_H__
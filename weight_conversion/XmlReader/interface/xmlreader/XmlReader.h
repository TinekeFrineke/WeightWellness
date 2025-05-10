#pragma once

#include "Utilities/StrUtils.h"

#include "model/IDay.h"
#include "model/IModel.h"
#include "model/Portie.h"

#include "xmlbase/XmlBase.h"

namespace ww_1_2
{
class XmlBonuscell;
class XmlDag;
class XmlHandmatigitem;
class XmlLot;
class XmlModel;
class XmlPortie;
class XmlRecept;
class XmlVoedingsmiddel;
class XmlVoedingsmiddeldef;
}

namespace weight
{

class IMessageHandler;
class ManualItem;
class Recept;
class Voedingsmiddel;

}

namespace ww_1_2
{

class XmlReader
{
public:
    XmlReader(const std::string& logfile, weight::IModel& aModel, std::shared_ptr<weight::IMessageHandler> messageHandler);

    weight::Result Read(const std::string& aDirectory);

    weight::Result ReadPersonalia(const std::string& aDirectory);
    weight::Result ReadUnits(const std::string& aDirectory);
    weight::Result ReadVoedingsmiddelDefinities(const std::string& aDirectory);
    weight::Result ReadRecepten(const std::string& aDirectory);
    weight::Result ReadGerechten(const std::string& aDirectory);
    weight::Result ReadWeeks(const std::string& aDirectory);
    weight::Result ReadBonusCells(const std::string& aDirectory);

private:
    XmlReader& operator=(const XmlReader&) = delete;
    XmlReader(const XmlReader&) = delete;

    weight::Result ReadWeek(const std::string& aDirectory);

    weight::Portie Create(const ww_1_2::XmlPortie& aPortie);
    std::unique_ptr<weight::Voedingsmiddel> Create(const ww_1_2::XmlVoedingsmiddel& aVoedingsmiddel);
    std::unique_ptr<weight::Recept> Create(const ww_1_2::XmlRecept& aRecept);
    std::unique_ptr<weight::ManualItem> Create(const ww_1_2::XmlHandmatigitem& aGerecht);
    std::unique_ptr<weight::IDay> Create(const ww_1_2::XmlDag& aDag);
    weight::Bonus Create(const ww_1_2::XmlBonuscell& aCell);
    void LogMessage(const std::wstring& message) const;

    std::string m_logfile;
    weight::IModel& mModel;
    std::shared_ptr<weight::IMessageHandler> m_messageHandler;
};


} // namespace ww_1_2

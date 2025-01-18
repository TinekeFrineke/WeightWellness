
#include "PersonalData.h"

#include "model/Personalia.h"

namespace viewmodel {



PersonalData::PersonalData(std::shared_ptr<weight::Model> model,
                           weight::Personalia* personalia, QObject* parent)
    : IPersonalData(parent)
    , m_model(model)
    , m_personalia(personalia)
{
}

QString PersonalData::name() const
{
    return QString(m_personalia->GetName().c_str());
}

void PersonalData::setName(const QString& name)
{
    m_personalia->SetName(name.toStdWString());
}

QString PersonalData::userName() const
{
    return QString(m_personalia->GetUserName().c_str());
}

void PersonalData::setUserName(const QString& name)
{
    //m_personalia->GetUserName(name.toStdWString());
}

double PersonalData::startWeight() const
{
    return m_personalia->GetStartGewicht();
}

double PersonalData::currentWeight() const
{
    return m_personalia->GetHuidigGewicht();
}

double PersonalData::targetWeight() const
{
    return m_personalia->GetStreefGewicht();
}

double PersonalData::pointsPerDay() const
{
    return m_personalia->GetPuntenTotaal(m_personalia->GetStrategy());
}

void PersonalData::setPointsPerDay(double points)
{
    m_personalia->SetPuntenTotaal(m_personalia->GetStrategy(), points);
}

double PersonalData::extraWeekPointsPerDay() const
{
    return m_personalia->GetWeekPuntenTotaal(m_personalia->GetStrategy());
}

void PersonalData::setExtraWeekPointsPerDay(double points)
{
    m_personalia->SetWeekPuntenTotaal(m_personalia->GetStrategy(), points);
}

} // namespace viewmodel
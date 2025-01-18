
#pragma once

#include "model/Personalia.h"

#include "IPersonalData.h"

namespace weight {
class Model;
}


namespace viewmodel {


class PersonalData
    : public IPersonalData
{
public:
    PersonalData(std::shared_ptr<weight::Model> model,
                 weight::Personalia* personalia, QObject* parent = nullptr);

    // Inherited via IPersonalData
    QString name() const override;
    void setName(const QString& name) override;
    QString userName() const override;
    void setUserName(const QString& name) override;
    double startWeight() const override;
    double currentWeight() const override;
    double targetWeight() const override;
    double pointsPerDay() const override;
    void setPointsPerDay(double points) override;
    double extraWeekPointsPerDay() const override;
    void setExtraWeekPointsPerDay(double points) override;

private:
    std::shared_ptr<weight::Model> m_model;
    weight::Personalia* m_personalia{};


    // Inherited via IPersonalData

};

} // namespace viewmodel

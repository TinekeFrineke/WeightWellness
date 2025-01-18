
#pragma once


#include <QObject>

namespace viewmodel
{

class IPersonalData
    : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(double startWeight READ startWeight NOTIFY startWeightChanged)
    Q_PROPERTY(double currentWeight READ currentWeight NOTIFY currentWeightChanged)
    Q_PROPERTY(double targetWeight READ targetWeight NOTIFY targetWeightChanged)
    Q_PROPERTY(double pointsPerDay READ pointsPerDay WRITE setPointsPerDay NOTIFY pointsPerDayChanged)
    Q_PROPERTY(double extraWeekPointsPerDay READ extraWeekPointsPerDay WRITE setExtraWeekPointsPerDay NOTIFY extraWeekPointsPerDayChanged)

public:
    virtual ~IPersonalData() = default;
    IPersonalData(QObject* parent) : QObject(parent) {}

    virtual QString name() const = 0;
    virtual void setName(const QString& name) = 0;
    virtual QString userName() const = 0;
    virtual void setUserName(const QString& name) = 0;
    virtual double startWeight() const = 0;
    virtual double currentWeight() const = 0;
    virtual double targetWeight() const = 0;
    virtual double pointsPerDay() const = 0;
    virtual void setPointsPerDay(double points) = 0;
    virtual double extraWeekPointsPerDay() const = 0;
    virtual void setExtraWeekPointsPerDay(double points) = 0;

signals:
    void nameChanged(const QString& name);
    void userNameChanged(const QString& name);
    void startWeightChanged(double weight);
    void currentWeightChanged(double weight);
    void targetWeightChanged(double weight);
    void pointsPerDayChanged(double points);
    void extraWeekPointsPerDayChanged(double points);
};


} // namespace viewmodel
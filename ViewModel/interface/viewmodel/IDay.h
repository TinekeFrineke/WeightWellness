
#pragma once


#include <QObject>

namespace viewmodel
{

class IDay
    : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(double freeBonus READ freeBonus WRITE setFreeBonus NOTIFY freeBonusChanged)
    Q_PROPERTY(double totalPointsSpent READ totalPointsSpent NOTIFY totalPointsSpentChanged)

public:
    virtual ~IDay() = default;
    IDay(QObject* parent) : QObject(parent) {}

    virtual double weight() const = 0;
    virtual void setWeight(double weight) = 0;
    virtual double freeBonus() const = 0;
    virtual void setFreeBonus(double bonus) = 0;
    virtual double totalPointsSpent() const = 0;

signals:
    void weightChanged(double newWeight);
    void freeBonusChanged(double newBonus);
    void totalPointsSpentChanged(double points);
};


} // namespace viewmodel
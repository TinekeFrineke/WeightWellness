
#pragma once


#include <QObject>

namespace viewmodel
{

class IWeek
    : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString strategy READ strategy/* NOTIFY strategyChanged*/ CONSTANT)
    Q_PROPERTY(double pointsAvailable READ pointsAvailable /*NOTIFY pointsChanged*/ CONSTANT)

public:
    virtual ~IWeek() = default;
    IWeek(QObject* parent) : QObject(parent) {}

    virtual QString strategy() const = 0;
    virtual double pointsAvailable() const = 0;

signals:
    //void pointsAvailableChanged(double points);
    //void weekPointsChanged(double points);
};


} // namespace viewmodel
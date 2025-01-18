
#pragma once


#include <QObject>

namespace viewmodel
{

class IWeek
    : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString strategy READ strategy/* NOTIFY strategyChanged*/)
    Q_PROPERTY(double points READ points NOTIFY pointsChanged)

public:
    virtual ~IWeek() = default;
    IWeek(QObject* parent) : QObject(parent) {}

    virtual QString strategy() const = 0;
    virtual double points() const = 0;

signals:
    void pointsChanged(double points);
};


} // namespace viewmodel
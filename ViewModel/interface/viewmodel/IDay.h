
#pragma once


#include <QObject>

namespace viewmodel
{

class IDay
    : public QObject
{
    Q_OBJECT

public:
    virtual ~IDay() = default;
    IDay(QObject* parent) : QObject(parent) {}

public slots:
    virtual void freeBonusChanged(double newValue) = 0;
    virtual void itemChanged() = 0;
    virtual void weightChanged(double newWeight) = 0;
};


} // namespace viewmodel
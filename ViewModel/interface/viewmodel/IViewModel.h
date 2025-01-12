
#pragma once


#include <QObject>

namespace viewmodel
{

class IViewModel
    : public QObject
{
    Q_OBJECT

public:
    virtual ~IViewModel() = default;
    IViewModel(QObject* parent) : QObject(parent) {}

public slots:
    virtual void DayPlusOne() = 0;
    virtual void DayMinusOne() = 0;
};


} // namespace viewmodel
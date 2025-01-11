
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


};


} // namespace viewmodel
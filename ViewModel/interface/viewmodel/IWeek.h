
#pragma once


#include <QObject>

namespace viewmodel
{

class IWeek
    : public QObject
{
    Q_OBJECT

public:
    virtual ~IWeek() = default;
    IWeek(QObject* parent) : QObject(parent) {}


};


} // namespace viewmodel
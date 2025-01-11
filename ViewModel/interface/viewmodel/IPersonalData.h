
#pragma once


#include <QObject>

namespace viewmodel
{

class IPersonalData
    : public QObject
{
    Q_OBJECT

public:
    virtual ~IPersonalData() = default;
    IPersonalData(QObject* parent) : QObject(parent) {}


};


} // namespace viewmodel
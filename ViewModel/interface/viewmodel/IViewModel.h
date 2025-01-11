
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


};


} // namespace viewmodel
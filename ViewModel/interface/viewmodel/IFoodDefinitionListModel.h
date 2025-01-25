
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>


namespace viewmodel {

class FoodDefinitionModel;

class IFoodDefinitionListModel: public QAbstractListModel {
    Q_OBJECT

public:
    explicit IFoodDefinitionListModel(QObject* parent = nullptr) : QAbstractListModel(parent) {}

    virtual void addDefinition(const FoodDefinitionModel& model) = 0;
    Q_INVOKABLE virtual QVariantList getFoodDefinitionsForQML() const = 0;
    Q_INVOKABLE virtual void remove(int index, int count = 1) = 0;
    Q_INVOKABLE virtual void push(const QString& name, const QString& category, const QString& unit, double points) = 0;
};

} // namespace viewmodel
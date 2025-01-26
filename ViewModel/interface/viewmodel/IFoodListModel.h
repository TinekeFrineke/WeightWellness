
#pragma once

#include <optional>

#include <QObject>
#include <QAbstractListModel>
#include <QList>


namespace viewmodel {

class FoodModel;

class IFoodListModel: public QAbstractListModel {
    Q_OBJECT

public:
    explicit IFoodListModel(QObject* parent = nullptr) : QAbstractListModel(parent) {}

    virtual void addFood(const FoodModel& model) = 0;
    virtual std::optional<FoodModel> getAtIndex(int index) = 0;
    Q_INVOKABLE virtual void remove(int index, int count = 1) = 0;
    Q_INVOKABLE virtual void push(const QString& name, double points) = 0;
};

} // namespace viewmodel
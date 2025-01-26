
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>

#include "IFoodListModel.h"

namespace viewmodel {

class FoodModel;

class FoodListModel
    : public IFoodListModel {
    Q_OBJECT

public:
    explicit FoodListModel(QObject* parent = nullptr);

    void addFood(const FoodModel& model) override;
    std::optional<FoodModel> getAtIndex(int index);
    Q_INVOKABLE void remove(int index, int count = 1) override;
    Q_INVOKABLE void push(const QString& name, double points) override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<FoodModel> m_foods;
};

} // namespace viewmodel
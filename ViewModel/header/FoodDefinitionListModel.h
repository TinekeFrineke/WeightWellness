
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>

#include "IFoodDefinitionListModel.h"

namespace viewmodel {

class FoodDefinitionListModel
    : public IFoodDefinitionListModel {
    Q_OBJECT

public:
    explicit FoodDefinitionListModel(QObject* parent = nullptr);

    void addDefinition(const FoodDefinitionModel& model) override;
    Q_INVOKABLE QVariantList getFoodDefinitionsForQML() const override;
    Q_INVOKABLE void remove(int index, int count = 1) override;
    Q_INVOKABLE void push(const QString& name, const QString& category, const QString& unit, double points) override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<FoodDefinitionModel> m_definition;
};

} // namespace viewmodel
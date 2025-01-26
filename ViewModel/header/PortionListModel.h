
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>

#include "IPortionListModel.h"

namespace viewmodel {

class PortionModel;

class PortionListModel
    : public IPortionListModel {
    Q_OBJECT

public:
    explicit PortionListModel(QObject* parent = nullptr);

    void add(const PortionModel& model) override;
    Q_INVOKABLE QVariantList getPortionsForQML() const override;
    Q_INVOKABLE void remove(int index, int count = 1) override;
    Q_INVOKABLE void push(const QString& name) override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                                            int role = Qt::DisplayRole) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<PortionModel> m_portions;
};

} // namespace viewmodel

#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>

#include "IRecipeListModel.h"

namespace viewmodel {

class RecipeModel;

class RecipeListModel
    : public IRecipeListModel {
    Q_OBJECT

public:
    explicit RecipeListModel(QObject* parent = nullptr);

    void addRecipe(const RecipeModel& model);

    Q_INVOKABLE QVariantList getRecipesForQML() const;
    Q_INVOKABLE void remove(int index, int count = 1);
    Q_INVOKABLE void push(const QString& name, double points);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                                            int role = Qt::DisplayRole) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<RecipeModel> m_recipies;
};

} // namespace viewmodel
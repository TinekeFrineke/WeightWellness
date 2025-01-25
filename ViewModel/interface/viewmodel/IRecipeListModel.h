
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QList>


namespace viewmodel {

class RecipeModel;

class IRecipeListModel: public QAbstractListModel {
    Q_OBJECT

public:

    explicit IRecipeListModel(QObject* parent = nullptr) : QAbstractListModel(parent) {}

    virtual void addRecipe(const RecipeModel& model) = 0;
    Q_INVOKABLE virtual  QVariantList getRecipesForQML() const = 0;
    Q_INVOKABLE virtual void remove(int index, int count = 1) = 0;
    Q_INVOKABLE virtual void push(const QString& name, double points) = 0;
};

} // namespace viewmodel
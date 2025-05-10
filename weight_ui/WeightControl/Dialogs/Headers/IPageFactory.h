
#pragma once

#include <memory>

namespace weight {
class ReceptDefinitie;
}

class CDiaryPage;
class CWnd;
class EditReceptDefDialog;
class FoodDefinitionEditor;
class ReceptenPage;

class IPageFactory {
public:
    virtual ~IPageFactory() = default;

    virtual std::unique_ptr<ReceptenPage> CreateRecipesPage() const = 0;
    virtual std::unique_ptr<EditReceptDefDialog> CreateEditRecipeDefinitionsDialog(weight::ReceptDefinitie& aRecept, CWnd* parent) const = 0;
    virtual std::unique_ptr<CDiaryPage> CreateDiaryPage(CWnd* parent) const = 0;

    virtual std::unique_ptr<FoodDefinitionEditor> CreateFoodDefinitionEditor(CWnd* parent) const = 0;
}; // class PageFactory
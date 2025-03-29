
#pragma once

#include <memory>

namespace weight {
class ReceptDefinitie;
}

class EditReceptDefDialog;
class CWnd;
class ReceptenPage;

class IPageFactory {
public:
    virtual ~IPageFactory() = default;

    virtual std::unique_ptr<ReceptenPage> CreateRecipesPage() const = 0;
    virtual std::unique_ptr<EditReceptDefDialog> CreateEditRecipeDefinitionsDialog(weight::ReceptDefinitie& aRecept, CWnd* parent) const = 0;
}; // class PageFactory
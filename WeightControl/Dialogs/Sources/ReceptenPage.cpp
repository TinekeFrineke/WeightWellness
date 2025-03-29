// ReceptenPage.cpp : implementation file
//

#include "stdafx.h"

#include "ReceptenPage.h"

#include "model/IRepository.h"
#include "model/ReceptDefinitie.h"

#include "EditReceptDefDialog.h"
#include "RecipeDefinitionEditor.h"


// ReceptenPage dialog

// TODO ww2024: Now the page directly removes recepies from the model. 
// It would be better if this happens only when the user presses "OK".

IMPLEMENT_DYNAMIC(ReceptenPage, CDialog)
ReceptenPage::ReceptenPage(weight::IModel& aModel, std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes, CWnd* pParent)
    : CDialog(ReceptenPage::IDD, pParent)
    , mReceptenList(recipes)
    , mModel(aModel)
    , m_recipes(recipes)
{
}

ReceptenPage::~ReceptenPage()
{
}

void ReceptenPage::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, mReceptenList);
}


BEGIN_MESSAGE_MAP(ReceptenPage, CDialog)
    ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
    ON_BN_CLICKED(IDC_EDIT, OnBnClickedEdit)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnNMDblclkList1)
    ON_BN_CLICKED(IDC_DELETE, &ReceptenPage::OnBnClickedDelete)
END_MESSAGE_MAP()


BOOL ReceptenPage::OnInitDialog()
{
    if (CDialog::OnInitDialog() == FALSE)
        return FALSE;

    mReceptenList.Initialize();
    View(m_recipes->GetAll());
    return TRUE;
}


// ReceptenPage message handlers

void ReceptenPage::OnBnClickedAdd()
{
    RecipeDefinitionEditor editor(mModel, mModel.GetRecipeDefinitionRepository(), this);
    auto definition = editor.Create();
    if (definition != nullptr)
        m_recipes->Add(std::move(definition));

    mReceptenList.View(m_recipes->GetAll());
}


void ReceptenPage::View(const std::vector<weight::ReceptDefinitie*>& aRecepten)
{
    mReceptenList.View(aRecepten);
}

void ReceptenPage::OnBnClickedEdit()
{
    auto* definition = mReceptenList.GetSelectedDefinition();
    if (definition == nullptr)
        return;

    RecipeDefinitionEditor editor(mModel, m_recipes, this);
    if (editor.Edit(*definition))
        mReceptenList.View(m_recipes->GetAll());
}

void ReceptenPage::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
    (void)pNMHDR;

    auto definition = mReceptenList.GetSelectedDefinition();
    if (definition == nullptr)
        return;

    RecipeDefinitionEditor editor(mModel, m_recipes, this);
    if (editor.Edit(*definition))
        mReceptenList.View(m_recipes->GetAll());

    *pResult = 0;
}


void ReceptenPage::OnBnClickedDelete()
{
    auto definition = mReceptenList.GetSelectedDefinition();
    if (definition == nullptr)
        return;

    if (::MessageBox(m_hWnd, _T("Zeker weten?"), _T("Waarschuwing"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
        m_recipes->Remove(definition->GetName());
    }

    View(m_recipes->GetAll());
}

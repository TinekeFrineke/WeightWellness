#pragma once

#include "controls/tabpage.h"
#include "model/IModel.h"
#include "ReceptDefinitiesList.h"
#include "resource.h"

// ReceptenPage dialog

namespace weight
{
class ReceptDefinitie;
}

class ReceptenPage: public CDialog, public TabPage
{
    DECLARE_DYNAMIC(ReceptenPage)

public:
    explicit ReceptenPage(weight::IModel& aModel, std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes, CWnd* pParent = NULL);   // standard constructor
    ~ReceptenPage() override;

    virtual CDialog* GetDialog() { return this; }

    virtual void              OnCancel() {}
    virtual void              OnOK() {}

    BOOL                      OnInitDialog();

    // Dialog Data
    enum { IDD = IDD_RECEPTEN_PAGE };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    afx_msg void OnBnClickedAdd();
    afx_msg void OnBnClickedEdit();
    afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnBnClickedDelete();

    void View(const std::vector<weight::ReceptDefinitie*>& aRecepten);

private:
    weight::IModel& mModel;
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    ReceptDefinitiesList mReceptenList;
};

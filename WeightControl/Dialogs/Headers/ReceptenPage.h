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
    explicit ReceptenPage(std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes,
                          std::shared_ptr<weight::IRepository<weight::VMDefinitie>> foodDefinitions,
                          std::shared_ptr<weight::PointsCalculator> calculator,
                          std::shared_ptr<weight::IStringRepository> categories,
                          std::shared_ptr<weight::IStringRepository> brands,
                          CWnd* pParent = NULL);
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
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    std::shared_ptr<weight::IRepository<weight::VMDefinitie>> m_foodDefinitions;
    std::shared_ptr<weight::PointsCalculator> m_calculator;
    std::shared_ptr<weight::IStringRepository> m_categories;
    std::shared_ptr<weight::IStringRepository> m_brands;
    ReceptDefinitiesList mReceptenList;
};

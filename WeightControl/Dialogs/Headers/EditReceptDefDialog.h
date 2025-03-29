#pragma once
#include "itemlist.h"
#include "afxwin.h"
#include "controls/stringedit.h"
#include "resource.h"
#include "controls/doubleedit.h"
#include "controls/intedit.h"

namespace weight
{
class IModel;
class ReceptDefinitie;
class Voedingsmiddel;

template <typename TYPE> class IRepository;
}

// EditReceptDefDialog dialog

class EditReceptDefDialog: public CDialog
{
    DECLARE_DYNAMIC(EditReceptDefDialog)

public:
    EditReceptDefDialog(weight::IModel& aModel, std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipes, weight::ReceptDefinitie& aRecept, CWnd* pParent = NULL);   // standard constructor
    virtual ~EditReceptDefDialog();

    // Dialog Data
    enum { IDD = IDD_EDITRECEPT_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL OnInitDialog();

    afx_msg void OnBnClickedAdd();
    afx_msg void OnBnClickedEdit();
    afx_msg void OnBnClickedOk();
    afx_msg void OnLvnItemchangedItemsList(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnNMDblclkItemsList(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnEnChangePorties();
    afx_msg void OnBnClickedDelete();

private:
    void EditSelectedItem();

    weight::IModel& mModel;
    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipes;
    weight::ReceptDefinitie& mRecept;

    ItemList mItemList;
    CStringEdit mName;
    CDoubleEdit mPointsPerPortion;
    CIntEdit mPorties;
};

#pragma once

#include "afxwin.h"

#include "controls/doubleedit.h"
#include "controls/IntEdit.h"
#include "controls/stringedit.h"

#include "receptdefinitieslist.h"
#include "resource.h"


class VMState;

namespace weight
{
class Day;
class IModel;
class Recept;
class ReceptDefinitie;
}

// CFindRecept dialog

class CFindRecept: public CDialog
{
    DECLARE_DYNAMIC(CFindRecept)

public:
    CFindRecept(std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> recipies,
                weight::ReceptDefinitie* aDefinitie,
                CWnd* pParent = NULL);   // standard constructor
    virtual               ~CFindRecept();

    // Dialog Data
    enum { IDD = IDD_FIND_RECEPT };

    std::unique_ptr<weight::Recept> ExtractRecept() { return std::move(mRecept); }

protected:
    virtual void          DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL                  OnInitDialog();

    afx_msg void          OnBnClickedOk();
    afx_msg void          OnBnClickedCancel();
    afx_msg void          OnEnChangeNaam();
    afx_msg void          OnLvnItemchangedItemlist(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void          OnEnChangePorties();
    afx_msg void          OnNMDblclkItemlist(NMHDR* pNMHDR, LRESULT* pResult);

private:
    void                  UpdateItemFilter();

    CStringEdit           mNaam;
    // Food items to pick from
    ReceptDefinitiesList  mItemList;
    // The number of porties
    CIntEdit              mPorties;
    CDoubleEdit           mPoints;

    std::shared_ptr<weight::IRepository<weight::ReceptDefinitie>> m_recipies;
    std::unique_ptr<weight::Recept> mRecept;
    weight::ReceptDefinitie* mDefinitie;

    bool                  mUpdating;
    bool                  mUpdatingFilter;
};

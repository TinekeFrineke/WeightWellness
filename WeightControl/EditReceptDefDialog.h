#pragma once
#include "itemlist.h"
#include "afxwin.h"
#include "stringedit.h"
#include "resource.h"
#include "doubleedit.h"
#include "intedit.h"

namespace WW
{
class ReceptDefinitie;
class Model;
class Voedingsmiddel;
}

// EditReceptDefDialog dialog

class EditReceptDefDialog: public CDialog
{
    DECLARE_DYNAMIC(EditReceptDefDialog)

public:
    EditReceptDefDialog(WW::Model& aModel, WW::ReceptDefinitie* aRecept, CWnd* pParent = NULL);   // standard constructor
    virtual ~EditReceptDefDialog();

    // Dialog Data
    enum { IDD = IDD_EDITRECEPT_DIALOG };

    std::unique_ptr<WW::ReceptDefinitie> ExtractRecept();

protected:
    virtual void          DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL                  OnInitDialog();

    afx_msg void          OnBnClickedAdd();
    afx_msg void          OnBnClickedEdit();
    afx_msg void          OnBnClickedOk();

private:
    void                  EditSelectedItem();

    WW::Model& mModel;
    std::unique_ptr<WW::ReceptDefinitie> mRecept;

    ItemList              mItemList;
    CStringEdit           mName;
    CDoubleEdit           mPointsPerPortion;
public:
    afx_msg void OnLvnItemchangedItemsList(NMHDR* pNMHDR, LRESULT* pResult);
    // // Aantal porties in het recept
    CIntEdit mPorties;
    afx_msg void OnNMDblclkItemsList(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnEnChangePorties();
    afx_msg void OnBnClickedDelete();
};

#pragma once

#include "resource.h"
#include "controls/stringedit.h"
#include "controls/doubleedit.h"
#include "controls/IntEdit.h"


// EditReceptDialog dialog

class EditReceptDialog : public CDialog
{
    DECLARE_DYNAMIC(EditReceptDialog)

public:
    EditReceptDialog(weight::Model& aModel, weight::Recept& aRecept, CWnd* pParent = NULL);   // standard constructor
    virtual ~EditReceptDialog();

    // Dialog Data
    enum { IDD = IDD_EDIT_RECEPT };

protected:
    virtual void                  DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL                          OnInitDialog();

    afx_msg void                  OnEnChangePorties();
    afx_msg void                  OnBnClickedOk();

private:
    CStringEdit                   mName;
    CIntEdit                      mPorties;
    CDoubleEdit                   mPunten;

    weight::Model& mModel;
    weight::Recept& mRecept;
};

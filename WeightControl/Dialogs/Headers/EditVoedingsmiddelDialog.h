#pragma once

#include "controls/doubleedit.h"
#include "controls/stringedit.h"
#include "model/lot.h"

#include "portiecombobox.h"
#include "resource.h"

#include "afxwin.h"


namespace weight
{
class Model;
class Voedingsmiddel;
class VMDefinitie;
}

// EditVoedingsmiddelDialog dialog
class EditVoedingsmiddelDialog: public CDialog
{
    DECLARE_DYNAMIC(EditVoedingsmiddelDialog)

public:
    class EditState
    {
    public:
        EditState(EditVoedingsmiddelDialog& aDialog,
                  weight::VMDefinitie& aDefinitie,
                  weight::Voedingsmiddel& aMiddel,
                  weight::Model& aModel)
            : mDialog(aDialog),
            mDefinitie(aDefinitie),
            mMiddel(aMiddel),
            mModel(aModel)
        {}

        void                          UpdatePortionValues(const weight::PortionedLot& aLot);
        virtual void                  Initialize() = 0;

    protected:
        CDoubleEdit& GetAantalPorties() { return mDialog.mAantalPorties; }
        CDoubleEdit& GetAantalEenheden() { return mDialog.mAantalEenheden; }
        CDoubleEdit& GetPunten() { return mDialog.mPunten; }
        PortieComboBox& GetPortieBox() { return mDialog.mPortie; }

        weight::VMDefinitie& GetDefinitie() { return mDefinitie; }
        weight::Voedingsmiddel& GetVoedingsMiddel() { return mMiddel; }

    private:
        EditVoedingsmiddelDialog& mDialog;
        weight::VMDefinitie& mDefinitie;
        weight::Voedingsmiddel& mMiddel;
        weight::Model& mModel;
    };

    EditVoedingsmiddelDialog(weight::Model& aModel,
                             weight::Voedingsmiddel& aVoedingsmiddel,
                             weight::VMDefinitie& aDefinitie,
                             CWnd* pParent = NULL);

    virtual                       ~EditVoedingsmiddelDialog();

    // Dialog Data
    enum { IDD = IDD_EDIT_VOEDINGSMIDDEL };

protected:
    virtual void                  DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

    BOOL                          OnInitDialog();

    afx_msg void                  OnCbnSelchangePortienaam();
    afx_msg void                  OnEnChangeAantalPorties();
    afx_msg void                  OnEnChangeAantalUnits();
    afx_msg void                  OnBnClickedOk();

private:
    void                          SetState(std::unique_ptr<EditState> aState);
    std::unique_ptr<EditState>    CreateState();

    weight::Model& mModel;
    weight::Voedingsmiddel& mVoedingsmiddel;
    weight::VMDefinitie& mVoedingsmiddelDef;

    CStringEdit                   mNaam;
    CDoubleEdit                   mAantalPorties;
    CDoubleEdit                   mAantalEenheden;
    CDoubleEdit                   mPunten;
    PortieComboBox                mPortie;

    std::unique_ptr<EditState> mState;
    bool                          mUpdating;
};


class EditNoPortionsState: public EditVoedingsmiddelDialog::EditState
{
public:
    EditNoPortionsState(EditVoedingsmiddelDialog& aDialog,
                        weight::VMDefinitie& aDefinitie,
                        weight::Voedingsmiddel& aMiddel,
                        weight::Model& aModel)
        : EditVoedingsmiddelDialog::EditState(aDialog, aDefinitie, aMiddel, aModel) {}

    void Initialize() override;
};


class EditStandardPortionsState: public EditVoedingsmiddelDialog::EditState
{
public:
    EditStandardPortionsState(EditVoedingsmiddelDialog& aDialog,
                              weight::VMDefinitie& aDefinitie,
                              weight::Voedingsmiddel& aMiddel,
                              weight::Model& aModel)
        : EditVoedingsmiddelDialog::EditState(aDialog, aDefinitie, aMiddel, aModel) {}

    void Initialize() override;
};

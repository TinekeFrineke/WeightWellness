#pragma once
#include "doubleedit.h"
#include "portiecombobox.h"
#include "resource.h"
#include "stringedit.h"

#include "model/lot.h"
#include "afxwin.h"


namespace WW
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
                  WW::VMDefinitie& aDefinitie,
                  WW::Voedingsmiddel& aMiddel,
                  WW::Model& aModel)
            : mDialog(aDialog),
            mDefinitie(aDefinitie),
            mMiddel(aMiddel),
            mModel(aModel)
        {}

        void                          UpdatePortionValues(const WW::PortionedLot& aLot);
        virtual void                  Initialize() = 0;

    protected:
        CDoubleEdit& GetAantalPorties() { return mDialog.mAantalPorties; }
        CDoubleEdit& GetAantalEenheden() { return mDialog.mAantalEenheden; }
        CDoubleEdit& GetPunten() { return mDialog.mPunten; }
        PortieComboBox& GetPortieBox() { return mDialog.mPortie; }

        WW::VMDefinitie& GetDefinitie() { return mDefinitie; }
        WW::Voedingsmiddel& GetVoedingsMiddel() { return mMiddel; }

    private:
        EditVoedingsmiddelDialog& mDialog;
        WW::VMDefinitie& mDefinitie;
        WW::Voedingsmiddel& mMiddel;
        WW::Model& mModel;
    };

    EditVoedingsmiddelDialog(WW::Model& aModel,
                             WW::Voedingsmiddel& aVoedingsmiddel,
                             WW::VMDefinitie& aDefinitie,
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

    WW::Model& mModel;
    WW::Voedingsmiddel& mVoedingsmiddel;
    WW::VMDefinitie& mVoedingsmiddelDef;

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
                        WW::VMDefinitie& aDefinitie,
                        WW::Voedingsmiddel& aMiddel,
                        WW::Model& aModel)
        : EditVoedingsmiddelDialog::EditState(aDialog, aDefinitie, aMiddel, aModel) {}

    void Initialize() override;
};


class EditStandardPortionsState: public EditVoedingsmiddelDialog::EditState
{
public:
    EditStandardPortionsState(EditVoedingsmiddelDialog& aDialog,
                              WW::VMDefinitie& aDefinitie,
                              WW::Voedingsmiddel& aMiddel,
                              WW::Model& aModel)
        : EditVoedingsmiddelDialog::EditState(aDialog, aDefinitie, aMiddel, aModel) {}

    void Initialize() override;
};

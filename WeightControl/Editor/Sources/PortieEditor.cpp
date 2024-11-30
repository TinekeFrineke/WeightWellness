#include "PortieEditor.h"

#include "stdafx.h"

#include "afxcmn.h"

#include "model/Portie.h"
#include "model/VoedingsMiddelDefinitie.h"

#include "EditPortieDialog.h"

bool PortieEditor::Edit(weight::Portie& portie) const
{
    CEditPortieDialog dialog(m_definitie, portie, m_definitie.GetPortieList(), m_parent);
    INT_PTR nResponse = dialog.DoModal();
    return nResponse == IDOK;
}

std::unique_ptr<weight::Portie> PortieEditor::Create() const
{
    auto portie = std::make_unique<weight::Portie>(L"");
    if (Edit(*portie.get()))
        return portie;

    return {};
}

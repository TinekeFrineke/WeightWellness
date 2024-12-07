#pragma once

#include "IPortieEditor.h"

class CWnd;

namespace weight {
class VMDefinitie;
}

class PortieEditor
    : public IPortieEditor
{
public:
    PortieEditor(weight::VMDefinitie& aDefinitie, CWnd* parent) : m_definitie(aDefinitie), m_parent(parent) {}

    bool Edit(weight::Portie& portie) const override;
    std::unique_ptr<weight::Portie> Create() const override;

private:
    weight::VMDefinitie& m_definitie;
    CWnd* m_parent;
};

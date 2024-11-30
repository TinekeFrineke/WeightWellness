#pragma once

#include <memory>

class CWnd;

namespace weight {
class Portie;
class VMDefinitie;
}

class PortieEditor
{
public:
    PortieEditor(weight::VMDefinitie& aDefinitie, CWnd* parent) : m_definitie(aDefinitie), m_parent(parent) {}

    bool Edit(weight::Portie& portie) const;
    std::unique_ptr<weight::Portie> Create() const;

private:
    weight::VMDefinitie& m_definitie;
    CWnd* m_parent;
};

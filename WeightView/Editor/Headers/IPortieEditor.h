#pragma once

#include <memory>


namespace weight {
class Portie;
}


class IPortieEditor
{
public:
    virtual ~IPortieEditor() = default;
    virtual bool Edit(weight::Portie& portie) const = 0;
    virtual std::unique_ptr<weight::Portie> Create() const = 0;
};

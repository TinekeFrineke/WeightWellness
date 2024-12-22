

#pragma once

#include <string>

using INT_PTR = int;
//#if !defined _W64
//#define _W64
//#endif
//typedef _W64 int INT_PTR;

namespace weightview {

class INewNameDialog
{
public:
    virtual ~INewNameDialog() = default;

    virtual INT_PTR DoModal() = 0;
    virtual std::wstring GetName() const = 0;
};


} // namespace weightview
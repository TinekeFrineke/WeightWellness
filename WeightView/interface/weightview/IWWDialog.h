
#pragma once


class CDialog;

namespace weightview {


class IWWDialog
{
public:
    virtual ~IWWDialog() = default;

    virtual CDialog* GetWindow() = 0;
    virtual INT_PTR DoModal() = 0;
};


} // namespace weightview
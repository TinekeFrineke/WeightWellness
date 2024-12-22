#pragma once


#include <memory>


class CWnd;

namespace weight {
class Model;
}

namespace weightview
{

class INewNameDialog;
class IWWDialog;


class ViewFactory
{
public:
    ViewFactory(weight::Model& model);

    std::unique_ptr<IWWDialog> CreateWWDialog(CWnd* parent);
    std::unique_ptr<INewNameDialog> CreateNewNameDialog(CWnd* parent);

private:
    weight::Model& m_model;
};

} // namespace weightview
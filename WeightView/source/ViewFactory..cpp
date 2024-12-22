

#include "ViewFactory.h"

#include "NewNameDialog.h"
#include "WWDialog.h"

namespace weightview {

ViewFactory::ViewFactory(weight::Model& model)
    : m_model(model)
{

}
std::unique_ptr<IWWDialog> ViewFactory::CreateWWDialog(CWnd* parent)
{
    return std::make_unique<CWWDialog>(m_model, parent);
}
std::unique_ptr<INewNameDialog> ViewFactory::CreateNewNameDialog(CWnd* parent)
{
    return std::make_unique<NewNameDialog>(parent);
}


} // namespace weightview


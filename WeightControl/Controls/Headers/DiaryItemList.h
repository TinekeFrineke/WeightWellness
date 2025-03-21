#pragma once

#include "afxcmn.h"

#include <vector>

#include "Utilities/Date.h"
#include "itemlist.h"

namespace weight
{
class IDay;
class Item;
class IModel;
}


/////////////////////////////////////////////////////////////////////////////
// CDiaryItemList window

class CDiaryItemList: public ItemList
{
    // Construction
public:
    explicit CDiaryItemList(weight::IModel& aModel);
    virtual ~CDiaryItemList();

    void View(weight::IDay* aDay);

protected:

    DECLARE_MESSAGE_MAP()

private:
    Utils::Date mDate;
    weight::IDay* mDay{};
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

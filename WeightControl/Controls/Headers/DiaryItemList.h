#pragma once

#include "afxcmn.h"

#include <vector>

#include "Utilities/Date.h"
#include "itemlist.h"

namespace weight
{
class Day;
class Item;
class Model;
}


/////////////////////////////////////////////////////////////////////////////
// CDiaryItemList window

class CDiaryItemList: public ItemList
{
    // Construction
public:
    CDiaryItemList(weight::Model& aModel);
    virtual                         ~CDiaryItemList();

    void                            View(weight::Day* aDay);

protected:

    DECLARE_MESSAGE_MAP()

private:
    Utils::Date mDate;
    weight::Day* mDay{};
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

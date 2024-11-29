#pragma once

#include "afxcmn.h"

#include <vector>

#include "Utilities/Date.h"
#include "Utilities/Observer.h"
#include "itemlist.h"

namespace weight
{
class Day;
class Item;
class Model;
}


/////////////////////////////////////////////////////////////////////////////
// CDiaryItemList window

class CDiaryItemList: public ItemList, public Observer
{
    // Construction
public:
    CDiaryItemList(weight::Model& aModel);
    virtual                         ~CDiaryItemList();

    void                            View(weight::Day* aDay);

    virtual void                    Update(Subject* aSubject);
    virtual void                    Destroyed(Subject* aSubject);

    // Implementation

      // Generated message map functions
protected:

    DECLARE_MESSAGE_MAP()

private:
    Utils::Date mDate;
    weight::Day* mDay{};
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

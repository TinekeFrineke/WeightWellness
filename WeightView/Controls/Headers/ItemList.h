#pragma once

#include <memory>
#include <vector>

namespace weight
{
class Item;
class Model;
}


class ListControl: public CListCtrl
{
public:
    ListControl();

    void                            SetNumberOfColumns(int aColumns);

    struct ColInfo
    {
        ColInfo() : mMinWidth(0), mAlignment(LVCFMT_LEFT), mHeader(_T("")) {}
        ColInfo(int aMinWidth, int anAlignment, const TCHAR* aHeader)
            : mMinWidth(aMinWidth), mAlignment(anAlignment), mHeader(aHeader) {}
        int mMinWidth;
        int mAlignment;
        const TCHAR* mHeader;
    };

    void                            SetColumnInfo(int iColumn, const ColInfo& aInfo);

    // Operations
    void                            Initialize();

private:
    std::vector<ColInfo>            mColumnInfo;
    int                             mNumberOfColumns;
};


class ItemListItem
{
public:
    ItemListItem(weight::Item* anItem);

    void Write(CListCtrl& aControl, int iItemIndex);

    weight::Item* GetItem();

private:
    weight::Item* mItem;
};


class ItemList: public ListControl
{
    // Construction
public:
    ItemList(weight::Model& aModel);
    virtual ~ItemList() override;

    // Operations
    void View(const std::vector<std::unique_ptr<weight::Item>>& aItems);

    ItemListItem* GetItemAt(int iIndex);
    ItemListItem* GetSelectedItem();
    void SelectItem(const weight::Item& anItem);
    void SelectItem(int iIndex, bool bSelect);

protected:
    DECLARE_MESSAGE_MAP()

    weight::Model& GetModel() { return mModel; }
    void                            ClearItems();

private:
    std::vector<std::unique_ptr<ItemListItem>>     mItems;
    weight::Model& mModel;
};

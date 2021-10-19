#ifndef ITEMTREEITEM_H
#define ITEMTREEITEM_H

#include "itreeitem.h"


class ItemTreeItem : public ITreeItem
{

public:
    ItemTreeItem(const QVariantMap& jsonMap, ITreeItem* parent);
    const LootEngineInterface::ItemStruct& getStruct() const;
    void setStruct(const LootEngineInterface::ItemStruct& itemStruct);

    /**
     * @brief loadJson Заполнение виджета
     * @param jsonMap данные отчета
     */
    void loadJson(const QVariantMap& jsonMap) override;
    QVariant data(const QModelIndex& index, int role) const override;

private:
    LootEngineInterface::ItemStruct _itemStruct;

};

#endif // ITEMTREEITEM_H

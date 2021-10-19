#ifndef GROUPTREEITEM_H
#define GROUPTREEITEM_H

#include "itreeitem.h"


class GroupTreeItem : public ITreeItem
{

public:
    GroupTreeItem(const QVariantMap& jsonMap, ITreeItem* parent);
    const LootEngineInterface::GroupStruct& getStruct() const;
    void setStruct(const LootEngineInterface::GroupStruct& groupStruct);

    /**
     * @brief loadJson Заполнение виджета
     * @param jsonMap данные отчета
     */
    void loadJson(const QVariantMap& jsonMap) override;
    QVariant data(const QModelIndex& index, int role) const override;

private:
    LootEngineInterface::GroupStruct _groupStruct;
    int _iconId;

};

#endif // GROUPTREEITEM_H

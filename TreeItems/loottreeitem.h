#ifndef LOOTTREEITEM_H
#define LOOTTREEITEM_H

#include "itreeitem.h"


class LootTreeItem : public ITreeItem
{

public:
    LootTreeItem(const QVariantMap& jsonMap, ITreeItem* parent);
    const LootEngineInterface::LootStruct& getStruct() const;
    void setStruct(const LootEngineInterface::LootStruct& lootStruct);

    /**
     * @brief loadJson Заполнение виджета
     * @param jsonMap данные отчета
     */
    void loadJson(const QVariantMap& jsonMap) override;

    QVariant data(const QModelIndex& index, int role) const override;

private:
    LootEngineInterface::LootStruct _lootStruct;
    int _iconId;

};

#endif // LOOTTREEITEM_H

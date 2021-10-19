#include "itemtreeitem.h"
#include "grouptreeitem.h"
#include "treemodel.h"

#include <QIcon>


ItemTreeItem::ItemTreeItem(const QVariantMap& jsonMap, ITreeItem* parent) :
    ITreeItem(Type::Item)
{
    _parent = parent;
    ItemTreeItem::loadJson(jsonMap);
}

const LootEngineInterface::ItemStruct& ItemTreeItem::getStruct() const
{
    return _itemStruct;
}

void ItemTreeItem::setStruct(const LootEngineInterface::ItemStruct& itemStruct)
{
    _itemStruct = itemStruct;
}

void ItemTreeItem::loadJson(const QVariantMap& jsonMap)
{
    _itemStruct.weight = jsonMap.value("weight", 0).toInt();
    _itemStruct.id = jsonMap.value("id", 0).toInt();
    _itemStruct.count = jsonMap.value("count", 1).toInt();
    _itemStruct.spread = jsonMap.value("spread", 0).toInt();
}

QVariant ItemTreeItem::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (static_cast<TreeModel::Columns>(index.column()))
        {
        case TreeModel::Columns::Type:      return QObject::tr("Item");
        case TreeModel::Columns::Count:     return _itemStruct.count;
        case TreeModel::Columns::Status:    return _itemStruct.weight;
        case TreeModel::Columns::Comment:   return _itemStruct.id;
        case TreeModel::Columns::enumColumnCount: return QString();
        }
    }

    if (role == Qt::DecorationRole)
    {
        if (static_cast<TreeModel::Columns>(index.column()) == TreeModel::Columns::Type && _itemStruct.id)
            return QIcon(getIconsPath() + QString("item/%1.png").arg(_itemStruct.id));
        else
            QVariant();
    }

    if (role == Qt::BackgroundColorRole)
    {
        if (_parent->getType() == Type::Group)
        {
            if (auto groupTreeItem = dynamic_cast<GroupTreeItem*>(_parent))
            {
                int chance = double(_itemStruct.weight) / groupTreeItem->getStruct().sumWeight * 10000;
                for (const auto& pair : getColorSettings())
                    if (pair.first < chance)
                        return pair.second;
            }
        }

        return QVariant();
    }

    return QVariant();
}

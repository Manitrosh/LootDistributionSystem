#include "grouptreeitem.h"
#include "itemtreeitem.h"
#include "treemodel.h"

#include <QIcon>


GroupTreeItem::GroupTreeItem(const QVariantMap& jsonMap, ITreeItem* parent) :
    ITreeItem(Type::Group)
{
    _parent = parent;
    GroupTreeItem::loadJson(jsonMap);
}

const LootEngineInterface::GroupStruct& GroupTreeItem::getStruct() const
{
    return _groupStruct;
}

void GroupTreeItem::setStruct(const LootEngineInterface::GroupStruct& groupStruct)
{
    _groupStruct = groupStruct;
}

void GroupTreeItem::loadJson(const QVariantMap& jsonMap)
{
    _groupStruct.sumWeight = jsonMap.value("sumWeight", 0).toInt();
    _groupStruct.count = jsonMap.value("count", 1).toInt();
    _groupStruct.key = jsonMap.value("key", 0).toInt();
    _groupStruct.settings = jsonMap.value("repetition", false).toBool();
    _iconId = jsonMap.value("iconId", 0).toInt();

    clearChilds();
    for (const auto& item : jsonMap.value("items").toList())
        _childs.append(new ItemTreeItem(item.toMap(), this));
}

QVariant GroupTreeItem::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (static_cast<TreeModel::Columns>(index.column()))
        {
        case TreeModel::Columns::Type:      return QObject::tr("Group");
        case TreeModel::Columns::Count:     return _groupStruct.count;
        case TreeModel::Columns::Status:    return _groupStruct.sumWeight;
        case TreeModel::Columns::Comment:   return _groupStruct.key;
        case TreeModel::Columns::enumColumnCount: return QString();
        }
    }

    if (role == Qt::DecorationRole)
    {
        if (static_cast<TreeModel::Columns>(index.column()) == TreeModel::Columns::Type && _iconId)
            return QIcon(getIconsPath() + QString("group/%1.png").arg(_iconId));
        else
            QVariant();
    }

    return QVariant();
}

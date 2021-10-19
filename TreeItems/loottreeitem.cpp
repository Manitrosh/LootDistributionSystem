#include "loottreeitem.h"
#include "grouptreeitem.h"
#include "treemodel.h"

#include <QIcon>


LootTreeItem::LootTreeItem(const QVariantMap& jsonMap, ITreeItem* parent) :
    ITreeItem(Type::Loot)
{
    _parent = parent;
    LootTreeItem::loadJson(jsonMap);
}

const LootEngineInterface::LootStruct& LootTreeItem::getStruct() const
{
    return _lootStruct;
}

void LootTreeItem::setStruct(const LootEngineInterface::LootStruct& lootStruct)
{
    _lootStruct = lootStruct;
}

void LootTreeItem::loadJson(const QVariantMap& jsonMap)
{
    _lootStruct.settings = 0;
    _iconId = jsonMap.value("iconId", 0).toInt();

    clearChilds();
    for (const auto& item : jsonMap.value("groups").toList())
        _childs.append(new GroupTreeItem(item.toMap(), this));
}

QVariant LootTreeItem::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (static_cast<TreeModel::Columns>(index.column()))
        {
        case TreeModel::Columns::Type:      return QObject::tr("Loot");
        case TreeModel::Columns::Count:     return QObject::tr("-1-");    /*!*/
        case TreeModel::Columns::Status:    return QObject::tr("-2-");   /*!*/
        case TreeModel::Columns::Comment:   return QObject::tr("-3-");  /*!*/
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

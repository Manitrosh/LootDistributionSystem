#include "treemodel.h"
#include "TreeItems/roottreeitem.h"
#include "TreeItems/loottreeitem.h"
#include "TreeItems/grouptreeitem.h"
#include "TreeItems/itemtreeitem.h"
#include "lootdialog.h"
#include "groupdialog.h"
#include "itemdialog.h"


TreeModel::TreeModel(QObject *parent) :
    QAbstractItemModel(parent),
    _rootTreeItem(new RootTreeItem())
{
}

TreeModel::~TreeModel()
{
    if (_rootTreeItem)
        delete _rootTreeItem;
}

void TreeModel::loadJson(const QVariantMap& jsonMap)
{
    beginResetModel();
    if (_rootTreeItem)
        delete _rootTreeItem;

    _rootTreeItem = new RootTreeItem(jsonMap);
    endResetModel();
    createIndexForTree(_rootTreeItem);
}

QString TreeModel::getStringByColumn(TreeModel::Columns column)
{
    switch (column)
    {
    case TreeModel::Columns::Type:      return tr("Type");
    case TreeModel::Columns::Count:     return tr("Count");
    case TreeModel::Columns::Status:    return tr("Status");
    case TreeModel::Columns::Comment:   return tr("Comment");
    case TreeModel::Columns::enumColumnCount: return QString();
    }

    return QString();
}

int TreeModel::columnCount(const QModelIndex&) const
{
    return 4;
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    ITreeItem* treeItem;
    if (parent.column() > 0 || !_rootTreeItem)
        return 0;

    if (!parent.isValid())
        treeItem = _rootTreeItem;
    else
        treeItem = static_cast<ITreeItem*>(parent.internalPointer());

    return treeItem->rowCount();
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return getStringByColumn(static_cast<TreeModel::Columns>(section));

    return QVariant();
}
QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent) || !_rootTreeItem)
        return QModelIndex();

    ITreeItem* treeItem;

    if (!parent.isValid())
        treeItem = _rootTreeItem;
    else
        treeItem = static_cast<ITreeItem*>(parent.internalPointer());

    ITreeItem* childItem = treeItem->childs().value(row, nullptr);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid() || !_rootTreeItem)
        return QModelIndex();

    ITreeItem* childItem = static_cast<ITreeItem*>(index.internalPointer());
    ITreeItem* parentItem = childItem->parent();

    if (parentItem == _rootTreeItem)
        return QModelIndex();

    if (parentItem)
        return createIndex(parentItem->row(), 0, parentItem);

    return QModelIndex();
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    return  QAbstractItemModel::flags(index) | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    return static_cast<ITreeItem*>(index.internalPointer())->data(index, role);
}

bool TreeModel::setData(const QModelIndex &/*index*/, const QVariant &/*value*/, int /*role*/)
{
    return false;
}

QModelIndex TreeModel::indexForTreeItem(const ITreeItem* item, int column)
{
    int row = item->row();
    return createIndex(row, column, const_cast<ITreeItem*>(item));
}

void TreeModel::createIndexForTree(ITreeItem* child)
{
    for (const auto& item : child->childs())
    {
        item->setExpandIndex(indexForTreeItem(item));
        createIndexForTree(item);
    }
}

//void TreeModel::treeItemUpdated(ITreeItem *treeItem)
//{

//}

void TreeModel::handleDoubleClicked(const QModelIndex &index)
{
    bool needUpdate = false;
    ITreeItem* iTreeItem = static_cast<ITreeItem*>(index.internalPointer());
    switch (iTreeItem->getType())
    {
    case ITreeItem::Type::Loot :
    {
        auto castedItem = static_cast<LootTreeItem*>(index.internalPointer());

        LootDialog dialog(castedItem->getStruct());
        needUpdate = dialog.exec();
        if (needUpdate)
            castedItem->setStruct(dialog.getData());

        break;
    }
    case ITreeItem::Type::Group :
    {
        auto castedItem = static_cast<GroupTreeItem*>(index.internalPointer());

        GroupDialog dialog(castedItem->getStruct());
        needUpdate = dialog.exec();
        if (needUpdate)
            castedItem->setStruct(dialog.getData());

        break;
    }
    case ITreeItem::Type::Item :
    {
        auto castedItem = static_cast<ItemTreeItem*>(index.internalPointer());

        ItemDialog dialog(castedItem->getStruct());
        needUpdate = dialog.exec();
        if (needUpdate)
            castedItem->setStruct(dialog.getData());

        break;
    }
    case ITreeItem::Type::Root : Q_FALLTHROUGH();
    case ITreeItem::Type::Unknow : break;
    };

    emit dataChanged(index, index);
//    treeItemUpdated(iTreeItem);
}


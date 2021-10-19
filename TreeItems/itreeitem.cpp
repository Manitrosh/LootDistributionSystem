#include "itreeitem.h"


ITreeItem::ITreeItem(Type type) :
    _type(type)
{
}

ITreeItem::~ITreeItem()
{
    clearChilds();
}

void ITreeItem::clearChilds()
{
    for (const auto& child : _childs)
        delete child;
    _childs.clear();
}

ITreeItem* ITreeItem::parent() const
{
    return _parent;
}

const QList<ITreeItem*>& ITreeItem::childs() const
{
    return _childs;
}

int ITreeItem::rowCount() const
{
    return _childs.count();
}

int ITreeItem::row() const
{
    if (!_parent)
        return 0;

    return _parent->childs().indexOf(const_cast<ITreeItem*>(this));
}

QVariant ITreeItem::data(const QModelIndex& /*index*/, int /*role*/) const
{
    return QVariant();
}

void ITreeItem::setExpandIndex(QModelIndex expandIndex)
{
    _expandIndex = expandIndex;
}

QModelIndex ITreeItem::getExpandIndex() const
{
    return _expandIndex;
}

ITreeItem::Type ITreeItem::getType() const
{
    return _type;
}

QString ITreeItem::getIconsPath() const
{
    if (_parent)
        return _parent->getIconsPath();
    return QString();
}

const QList<QPair<quint16, QColor>>& ITreeItem::getColorSettings() const
{
    if (_parent)
        return _parent->getColorSettings();

    static QList<QPair<quint16, QColor>> list;
    return list;
}

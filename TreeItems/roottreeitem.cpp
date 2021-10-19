#include "roottreeitem.h"
#include "loottreeitem.h"

#include <QDir>


RootTreeItem::RootTreeItem(const QVariantMap& jsonMap) :
    ITreeItem(Type::Root)
{
    RootTreeItem::loadJson(jsonMap);

    _colorChancesList = {
        {10000, QColor(240, 240, 240)},
        { 7000, QColor(10, 220, 0)},
        { 3000, QColor(0, 70, 255)},
        {  500, QColor(190, 35, 255)},
        {   10, QColor(255, 160, 0)},
        {    1, QColor(255, 220, 51)}
    };
}

void RootTreeItem::loadJson(const QVariantMap& jsonMap)
{
    clearChilds();
    if (!jsonMap.isEmpty())
        _childs.append(new LootTreeItem(jsonMap, this));
}

QString RootTreeItem::getIconsPath() const
{
    return _iconsPath.isEmpty() ? QDir::currentPath() + "/../LootDistributionSystem/debugSource/icons/" : _iconsPath;
}

const QList<QPair<quint16, QColor>>& RootTreeItem::getColorSettings() const
{
    return _colorChancesList;
}

void RootTreeItem::setIconsPath(const QString& iconsPath)
{
    _iconsPath = iconsPath;
}

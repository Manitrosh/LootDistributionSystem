#ifndef ITREEITEM_H
#define ITREEITEM_H

#include "../lib/lootinterface.h"

#include <QVariantMap>
#include <QModelIndex>
#include <QList>
#include <QPair>
#include <QColor>


class ITreeItem
{
public:
    enum Type
    {
        Unknow = 0,
        Item,
        Group,
        Loot,
        Root
    };


    ITreeItem(Type);
    virtual ~ITreeItem();

    void clearChilds();

    /**
     * @brief loadJson Заполнение виджета
     * @param jsonMap данные отчета
     */
    virtual void loadJson(const QVariantMap& jsonMap) = 0;

    virtual QVariant data(const QModelIndex& index, int role) const;

    ITreeItem* parent() const;
    const QList<ITreeItem*>& childs() const;

    int rowCount() const;
    int row() const;

    /**
     * @brief заполнение поля
     * @param expandIndex индекс элемента
     */
    void setExpandIndex(QModelIndex expandIndex);

    /**
     * @brief получение сэлемента для разворачивания
     * @return QModelIndex индекс элемента
     */
    QModelIndex getExpandIndex() const;

    Type getType() const;

protected:
    virtual QString getIconsPath() const;
    virtual const QList<QPair<quint16, QColor>>& getColorSettings() const;

protected:
    ITreeItem* _parent = nullptr;
    QList<ITreeItem*> _childs;

private:
    const Type _type = Type::Unknow;
    QModelIndex _expandIndex;

};

#endif // ITREEITEM_H

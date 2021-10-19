#ifndef ROOTTREEITEM_H
#define ROOTTREEITEM_H

#include "itreeitem.h"


class RootTreeItem : public ITreeItem
{
public:
    RootTreeItem(const QVariantMap& jsonMap = QVariantMap());

    /**
     * @brief loadJson Заполнение виджета
     * @param jsonMap данные отчета
     */
    void loadJson(const QVariantMap& jsonMap) override;

    void setIconsPath(const QString& iconsPath);

protected:
    QString getIconsPath() const override;
    const QList<QPair<quint16, QColor>>& getColorSettings() const override;

private:
    QString _iconsPath;
    QList<QPair<quint16, QColor>> _colorChancesList;


};

#endif // ROOTTREEITEM_H

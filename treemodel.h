#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>

class ITreeItem;
class RootTreeItem;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    enum Columns
    {
        Type = 0,
        Count,
        Status,
        Comment,

        enumColumnCount
    };

    TreeModel(QObject *parent = nullptr);
    ~TreeModel();

    void loadJson(const QVariantMap& jsonMap);

protected:
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

private:
    static QString getStringByColumn(TreeModel::Columns column);
    QModelIndex indexForTreeItem(const ITreeItem* item, int column = 0);
    void createIndexForTree(ITreeItem* child);
//    void treeItemUpdated(ITreeItem* treeItem);

    RootTreeItem* _rootTreeItem = nullptr;


public slots:
    void handleDoubleClicked(const QModelIndex &index);

};

#endif // TREEMODEL_H

#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include <QDialog>

namespace Ui {
class ItemDialog;
}
namespace LootEngineInterface {
struct ItemStruct;
}

class ItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemDialog(QWidget *parent = nullptr);
    explicit ItemDialog(const LootEngineInterface::ItemStruct& itemData, QWidget *parent = nullptr);
    ~ItemDialog();

    LootEngineInterface::ItemStruct getData() const;
    void setData(const LootEngineInterface::ItemStruct& itemData);

private:
    Ui::ItemDialog *ui;

};

#endif // ITEMDIALOG_H

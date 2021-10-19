#ifndef LOOTDIALOG_H
#define LOOTDIALOG_H

#include <QDialog>

namespace Ui {
class LootDialog;
}
namespace LootEngineInterface {
struct LootStruct;
}

class LootDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LootDialog(QWidget *parent = nullptr);
    explicit LootDialog(const LootEngineInterface::LootStruct& lootData, QWidget *parent = nullptr);
    ~LootDialog();

    LootEngineInterface::LootStruct getData() const;
    void setData(const LootEngineInterface::LootStruct& lootData);

private:
    Ui::LootDialog *ui;
};

#endif // LOOTDIALOG_H

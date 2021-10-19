#ifndef GROUPDIALOG_H
#define GROUPDIALOG_H

#include <QDialog>

namespace Ui {
class GroupDialog;
}
namespace LootEngineInterface {
struct GroupStruct;
}

class GroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupDialog(QWidget *parent = nullptr);
    explicit GroupDialog(const LootEngineInterface::GroupStruct& groupData, QWidget *parent = nullptr);
    ~GroupDialog();

    LootEngineInterface::GroupStruct getData() const;
    void setData(const LootEngineInterface::GroupStruct& groupData);

private:
    Ui::GroupDialog *ui;
};

#endif // GROUPDIALOG_H

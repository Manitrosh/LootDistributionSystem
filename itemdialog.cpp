#include "itemdialog.h"
#include "ui_itemdialog.h"
#include "lib/lootinterface.h"

#include <QPushButton>


ItemDialog::ItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked,
            this, &QDialog::accept);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::clicked,
            this, &QDialog::reject);
}

ItemDialog::ItemDialog(const LootEngineInterface::ItemStruct& itemData, QWidget *parent) :
    ItemDialog(parent)
{
    setData(itemData);
}

ItemDialog::~ItemDialog()
{
    delete ui;
}

LootEngineInterface::ItemStruct ItemDialog::getData() const
{
    return {
        static_cast<uint32_t>(ui->idSpinBox->value()),
                static_cast<uint32_t>(ui->countSpinBox->value()),
                static_cast<uint32_t>(ui->spreadSpinBox->value()),
                static_cast<uint32_t>(ui->weightSpinBox->value())
    };
}

void ItemDialog::setData(const LootEngineInterface::ItemStruct& itemData)
{
    ui->idSpinBox->setValue(itemData.id);
    ui->countSpinBox->setValue(itemData.count);
    ui->spreadSpinBox->setValue(itemData.spread);
    ui->weightSpinBox->setValue(itemData.weight);
}

#include "lootdialog.h"
#include "ui_lootdialog.h"
#include "lib/lootinterface.h"

#include <QPushButton>


LootDialog::LootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LootDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked,
            this, &QDialog::accept);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::clicked,
            this, &QDialog::reject);
}

LootDialog::LootDialog(const LootEngineInterface::LootStruct& lootData, QWidget *parent) :
    LootDialog(parent)
{
    setData(lootData);
}

LootDialog::~LootDialog()
{
    delete ui;
}

LootEngineInterface::LootStruct LootDialog::getData() const
{
    return {
        static_cast<uint32_t>(ui->settingsSpinBox->value())
    };
}

void LootDialog::setData(const LootEngineInterface::LootStruct& lootData)
{
    ui->settingsSpinBox->setValue(lootData.settings);
}

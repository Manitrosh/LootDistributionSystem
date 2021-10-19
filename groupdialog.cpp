#include "groupdialog.h"
#include "ui_groupdialog.h"
#include "lib/lootinterface.h"

#include <QPushButton>


GroupDialog::GroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked,
            this, &QDialog::accept);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel), &QPushButton::clicked,
            this, &QDialog::reject);
}

GroupDialog::GroupDialog(const LootEngineInterface::GroupStruct& groupData, QWidget *parent) :
    GroupDialog(parent)
{
    setData(groupData);
}

GroupDialog::~GroupDialog()
{
    delete ui;
}

LootEngineInterface::GroupStruct GroupDialog::getData() const
{
    return {
        static_cast<uint32_t>(ui->sumWeightSpinBox->value()),
                static_cast<uint16_t>(ui->countSpinBox->value()),
                static_cast<uint16_t>(ui->spreadSpinBox->value()),
                static_cast<uint32_t>(ui->keySpinBox->value()),
                static_cast<uint32_t>(ui->settingsSpinBox->value())
    };
}

void GroupDialog::setData(const LootEngineInterface::GroupStruct& groupData)
{
    ui->sumWeightSpinBox->setValue(groupData.sumWeight);
    ui->countSpinBox->setValue(groupData.count);
    ui->spreadSpinBox->setValue(groupData.spread);
    ui->keySpinBox->setValue(groupData.key);
    ui->settingsSpinBox->setValue(groupData.settings);
}

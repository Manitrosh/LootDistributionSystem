#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treemodel.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>
#include <QDir>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto treeModel = new TreeModel();
    ui->treeView->setModel(treeModel);

    connect(ui->treeView, &QTreeView::doubleClicked,
            treeModel, &TreeModel::handleDoubleClicked);


    handleRefreshKeyClicked();

    connect(ui->randomKeyLineEdit, &QLineEdit::editingFinished,
            this, &MainWindow::handleRandomKeyChanged);

    qDebug() << QDir::currentPath() + "/../LootDistributionSystem/debugSource/tree.json";
    QFile file(QDir::currentPath() + "/../LootDistributionSystem/debugSource/tree.json");
    if (file.open(QIODevice::ReadOnly))
        treeModel->loadJson(QJsonDocument::fromJson(file.readAll()).object().toVariantMap());

    ui->treeView->expandAll();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleRefreshKeyClicked()
{
    ui->randomKeyLineEdit->setText(QString::number(QRandomGenerator::global()->generate()));
    handleRandomKeyChanged();
}

void MainWindow::handleRandomKeyChanged()
{
    QString key = ui->randomKeyLineEdit->text();
    if (key.size() < 10)
    {
        key = QString(10 - key.size(), '0') + key;
        ui->randomKeyLineEdit->setText(key);
    }
}

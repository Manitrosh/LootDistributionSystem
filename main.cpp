#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <random>

#include "lib/item.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    qDebug() << sizeof(Item) << sizeof(Group) << sizeof(Loot)<< sizeof(Test) ;

//    int key = 1;
//    std::mt19937 mt_rand(1);
////    mt_rand.seed(1);
//    for (int i = 0; i < 100; i++)
//    qDebug() << mt_rand()<< mt_rand.default_seed << key;

    MainWindow w;
    w.show();
    return a.exec();
}

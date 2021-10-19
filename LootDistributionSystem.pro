QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    groupdialog.cpp \
    itemdialog.cpp \
    lib/group.cpp \
    lib/ilootgen.cpp \
    lib/loot.cpp \
    lib/lootengine.cpp \
    lootdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    treemodel.cpp \
    TreeItems/itreeitem.cpp \
    TreeItems/roottreeitem.cpp \
    TreeItems/loottreeitem.cpp \
    TreeItems/grouptreeitem.cpp \
    TreeItems/itemtreeitem.cpp \
    lib/item.cpp

HEADERS += \
    groupdialog.h \
    itemdialog.h \
    lib/group.h \
    lib/ilootgen.h \
    lib/loot.h \
    lib/lootdefines.h \
    lib/lootengine.h \
    lib/lootinterface.h \
    lootdialog.h \
    mainwindow.h \
    treemodel.h \
    TreeItems/itreeitem.h \
    TreeItems/roottreeitem.h \
    TreeItems/loottreeitem.h \
    TreeItems/grouptreeitem.h \
    TreeItems/itemtreeitem.h \
    lib/item.h

FORMS += \
    groupdialog.ui \
    itemdialog.ui \
    lootdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

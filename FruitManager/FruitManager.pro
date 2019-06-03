#-------------------------------------------------
#
# Project created by QtCreator 2019-04-04T20:09:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FruitManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialogwarehouse.cpp \
    dbhelper.cpp \
    userdao.cpp \
    user.cpp \
    userdaoimp.cpp \
    DialogDelete.cpp \
    DialogUpdate.cpp \
    DialogSelect.cpp \
    login.cpp \
    fruit.cpp \
    fruitdao.cpp \
    fruitdaoimp.cpp \
    dialoglack.cpp \
    dialogsale.cpp \
    supplier.cpp \
    supplierdao.cpp \
    supplierdaoimp.cpp \
    dialogpurchase.cpp \
    dialogsupplier.cpp \
    dialogsaleitem.cpp \
    dialogpurchaseorder.cpp

HEADERS += \
        mainwindow.h \
    dialogwarehouse.h \
    dbhelper.h \
    userdao.h \
    user.h \
    userdaoimp.h \
    DialogDelete.h \
    DialogUpdate.h \
    DialogSelect.h \
    login.h \
    fruit.h \
    fruitdao.h \
    fruitdaoimp.h \
    dialoglack.h \
    dialogsale.h \
    supplier.h \
    supplierdao.h \
    supplierdaoimp.h \
    dialogpurchase.h \
    dialogsupplier.h \
    dialogsaleitem.h \
    dialogpurchaseorder.h

FORMS += \
    dialogwarehouse.ui \
    DialogDelete.ui \
    DialogUpdate.ui \
    DialogSelect.ui \
    login.ui \
    mainwindow.ui \
    dialoglack.ui \
    dialogsale.ui \
    dialogpurchase.ui \
    dialogsupplier.ui \
    dialogsaleitem.ui \
    dialogpurchaseorder.ui

RESOURCES += \
    myimages.qrc



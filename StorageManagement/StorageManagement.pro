#-------------------------------------------------
#
# Project created by QtCreator 2019-05-22T15:46:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StorageManagement
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
    dbhelper.cpp \
    userdaoimp.cpp \
    user.cpp \
    userdao.cpp \
    login.cpp \
    dialogstockmanage.cpp \
    goods.cpp \
    goodsdao.cpp \
    goodsdaoimp.cpp \
    DialogDelete.cpp \
    DialogSelect.cpp \
    DialogUpdate.cpp \
    dialogviewstock.cpp \
    dialoglackmanage.cpp \
    lack.cpp \
    lackdao.cpp \
    lackdaoimp.cpp \
    dialogdeletelack.cpp \
    dialogupdatelack.cpp \
    dialogselectlack.cpp

HEADERS += \
        mainwindow.h \
    dbhelper.h \
    userdaoimp.h \
    user.h \
    userdao.h \
    login.h \
    dialogstockmanage.h \
    goods.h \
    goodsdao.h \
    goodsdaoimp.h \
    DialogDelete.h \
    DialogSelect.h \
    DialogUpdate.h \
    dialogviewstock.h \
    dialoglackmanage.h \
    lack.h \
    lackdao.h \
    lackdaoimp.h \
    dialogdeletelack.h \
    dialogupdatelack.h \
    dialogselectlack.h

FORMS += \
        mainwindow.ui \
    login.ui \
    dialogstockmanage.ui \
    DialogDelete.ui \
    DialogSelect.ui \
    DialogUpdate.ui \
    dialogviewstock.ui \
    dialoglackmanage.ui \
    dialogdeletelack.ui \
    dialogupdatelack.ui \
    dialogselectlack.ui

RESOURCES += \
    mypictures.qrc
